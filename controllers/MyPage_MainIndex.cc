#include "MyPage_MainIndex.h"
#include <fstream>

using namespace MyPortal;

Json::Value readLinkJson(){
    std::ifstream ifs;
    ifs.open("../data.json");
    if(!ifs.good()) {
        exit(1);
    }
    
    std::string jsonStr((std::istreambuf_iterator<char>(ifs)),
        std::istreambuf_iterator<char>());
    

    ifs.close();

    Json::Reader reader;
    Json::Value value;
    reader.parse(jsonStr, value);

    return value;
}

HttpViewData makeInformation(std::string url, std::string src){
    HttpViewData data;
    data.insert("url", url);
    data.insert("src", src);

    return data;
}

void MainIndex::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    const std::string CategoryName = "category_name";
    const std::string Informations = "informations";
    Json::Value jsonData = readLinkJson();
    HttpViewData viewData;
    std::vector<HttpViewData> categories;
    for(auto category : jsonData["categories"]){
        HttpViewData data;
        std::vector<HttpViewData> informations;
        for(auto information : category[Informations]){
            informations.push_back(
                makeInformation(
                    information["url"].asString(),
                    information["src"].asString()
                )
            );
        }

        data.insert(CategoryName, category[CategoryName].asString());
        data.insert(Informations, informations);
        categories.push_back(data);
    }
    viewData["categories"] = categories;

    auto res = HttpResponse::newHttpViewResponse("top.csp", viewData);
    callback(res);


    // auto res = HttpResponse::newHttpResponse();
    // res->setStatusCode(k200OK);
    // res->setContentTypeCode(CT_TEXT_HTML);
    // res->setBody("Hi, I'm .");
    // readLinkJson();
    
    // callback(res);
}
