#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api
{
class suggest : public drogon::HttpController<suggest>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(suggest::get, "/{2}/{1}", Get); // path is /api/suggest/{arg2}/{arg1}
    // METHOD_ADD(suggest::your_method_name, "/{1}/{2}/list", Get); // path is /api/suggest/{arg1}/{arg2}/list
    // ADD_METHOD_TO(suggest::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
    METHOD_ADD(suggest::getSuggests, "/{1:word}", Get);

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
    void getSuggests(const HttpRequestPtr &req,
            std::function<void (const HttpResponsePtr &)> &&callback,
            std::string &&word);
  private:
    std::vector<std::string> parceXmlStr(std::string_view xmlData);
    std::string replaceUCS(std::string_view arg);
    int convertHex(std::string_view charCode);
};
}
