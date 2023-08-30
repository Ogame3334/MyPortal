#include "myportal_api_suggest.h"
#include <drogon/HttpClient.h>
#include <cmath>
#include <uchar.h>

using namespace myportal::api;

// Add definition of your processing function here

// http://www.google.com/complete/search?hl=en&q=hello&output=toolbar

void suggest::getSuggests(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback,
               std::string &&word){
    // LOG_DEBUG << "word: " << word;
    // auto resp = HttpResponse::newHttpResponse();
    // resp->setBody(word);
    // resp->setContentTypeCode(CT_TEXT_HTML);
    // resp->setStatusCode(k200OK);
    // callback(resp);
    auto client = HttpClient::newHttpClient(
        "http://www.google.com/"
    );
    std::string api_path = "/complete/search";
    std::string language = "jp";
    std::string access_path = api_path + "?"
        + "hl=" + language + "&"
        + "q=" + word + "&"
        + "ie=utf_8&"
        + "oe=utf_8&"
        + "output=toolbar";

    auto request = HttpRequest::newHttpRequest();
    std::cout << access_path << std::endl;
    request->setPath(access_path);
    request->setMethod(Get);

    auto result = client->sendRequest(request);

    auto hoge = result.second->getBody();
    // HttpResponse
    // auto response = HttpResponse::newHttpResponse();
    std::string fuga{hoge};
    std::cout << fuga << std::endl;
    // response->setBody(fuga);
    
    Json::Value ret;
    auto piyo = parceXmlStr(fuga);
    for(int i = 1; i < piyo.size(); i++){
        ret[std::to_string(i-1)] = piyo[i];
        std::cout << replaceUCS(piyo[i]) << std::endl;
    }

    auto response = HttpResponse::newHttpJsonResponse(ret);

    callback(response);
}

std::vector<std::string> suggest::parceXmlStr(std::string_view xmlData){
    std::vector<std::string> words;
    bool wordMode = false;
    std::string word = "";
    for(auto c : xmlData){
        if(c == '"'){
            if(wordMode){
                words.push_back(word);
                word = "";
                wordMode = false;
            }
            else{
                wordMode = true;
            }
        }
        else{
            if(wordMode){
                word += c;
            }
        }
    }
    return words;
}
std::string suggest::replaceUCS(std::string_view arg){
    bool isAnd = false;
    bool isSharp = false;
    bool replaceMode = false;
    std::string output = "";
    std::string charCode = "";
    for(auto c : arg){
        if(replaceMode){
            if(c == ';'){
                std::cout << charCode << std::endl;
                std::cout << this->convertHex(charCode) << std::endl;
                wchar_t a = this->convertHex(charCode);
                char16_t a16 = this->convertHex(charCode);
                // char* b;
                // auto hoge = wcstombs(b, &a, 1);
                // std::wcout << a << std::endl;
                // std::cout << hoge << std::endl;
                std::wcout << a16 << std::endl;
                output += a;
                charCode = "";
                replaceMode = false;
            }
            else{
                charCode += c;
            }
        }
        else{
            if(c == '&' and !isAnd){
                isAnd = true;
            }
            else if(c == '#' and isAnd){
                isAnd = false;
                isSharp = true;
            }
            else if(c == 'x' and isSharp){
                isSharp = false;
                replaceMode = true;
            }
            else{
                output += c;
            }
        }
    }
    return output;
}
int suggest::convertHex(std::string_view charCode){
    std::string charTable = "0123456789ABCDEF";
    int output = 0;
    {
        int j = 0;
        for(int i = charCode.length() - 1; i >= 0; i--){
            int num = charTable.find(charCode[i]);
            output += num * std::pow(16, j);
            j++;
        }
    }
    
    return output;
}