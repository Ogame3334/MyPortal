#include "hello.h"

void hello::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
    Json::Value ret;
    ret["text"] = "hello, world!!";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
