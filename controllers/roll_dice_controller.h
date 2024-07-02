#ifndef CONTROLLERS_ROLL_DICE_CONTROLLER_H
#define CONTROLLERS_ROLL_DICE_CONTROLLER_H

#include <memory>

#include "drogon/HttpController.h"
#include "utils/util.h"
#include "loggers/logger.h"

class LoggerBase;
class UtilBase;

using namespace drogon;

class RollDice : public drogon::HttpController<RollDice> {
public:
    METHOD_LIST_BEGIN
    METHOD_ADD(RollDice::RollDice, "/{game_id}", Post);
    METHOD_LIST_END

    void rollDice(const HttpRequestPtr& req,
                  std::function<void(const HttpResponsePtr&)>&& callback,
                  const std::string& game_id);

private:
    // Logger.
    std::shared_ptr<LoggerBase> log_ = Logger::self();

    // Utility.
    std::shared_ptr<UtilBase> util_ = Util::self();
};

#endif  // CONTROLLERS_ROLL_DICE_CONTROLLER_H