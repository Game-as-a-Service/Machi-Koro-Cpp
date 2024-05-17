#define DROGON_TEST_MAIN
#include <gtest/gtest.h>
#include <drogon/drogon.h>

#include <future>
#include <thread>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <io.h>
#else
    #include <unistd.h>
#endif

using namespace drogon;

int main(int argc, char** argv)
{
    const std::string strConfig =
        "{\"listeners\":[{\"address\":\"127.0.0.1\",\"port\":8086}],\"app\":{\"log\":{\"use_"
        "spdlog\":true,\"log_level\":\"TRACE\"}},\"plugins\":[{\"name\":\"drogon::plugin::"
        "AccessLogger\",\"config\":{\"use_spdlog\":true}}]}";
    Json::Value jsonConfig;
    Json::Reader reader;
    reader.parse(strConfig, jsonConfig);

    std::promise<void> p1;
    std::future<void> f1 = p1.get_future();

    // Start the main loop on another thread.
    std::thread th1([&p1, &jsonConfig]() {   
        // Queues the promise to be fulfilled after starting the loop.
        app().getLoop()->queueInLoop([&p1]() { p1.set_value(); });
        app().loadConfigJson(jsonConfig);
        app().run();
    });

    // The future is only satisfied after the event loop started.
    f1.get();

    testing::InitGoogleTest(&argc, argv);
    int status = RUN_ALL_TESTS();

    // Ask the event loop to shutdown and wait.
    app().getLoop()->queueInLoop([]() { app().quit(); });
    th1.join();

    return status;
}