#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class AddPlayer : public drogon::HttpController<AddPlayer>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(AddPlayer::addPlayer, "/addPlayer", Post);
    METHOD_LIST_END

    void addPlayer(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback);
};
