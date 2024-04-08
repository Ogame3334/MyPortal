#include "myportal_api_suggest.h"
#include <drogon/HttpClient.h>
#include <cmath>
#include <uchar.h>
#include <locale>
#include <codecvt>

using namespace api;

// Add definition of your processing function here

// http://www.google.com/complete/search?hl=jp&q=hello&ie=utf_8&oe=utf_8&output=toolbar

void suggest::getSuggests(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback,
               std::string &&word){
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
    request->setPath(access_path);
    request->setMethod(Get);

    auto result = client->sendRequest(request);

    auto hoge = result.second->getBody();
    std::string fuga{hoge};
    
    Json::Value ret;
    auto piyo = parceXmlStr(fuga);
    for(int i = 1; i < piyo.size(); i++){
        ret[std::to_string(i-1)] = replaceUCS(piyo[i]);
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

std::string c16tochar(char16_t c16){
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
    std::string str = converter.to_bytes(c16);
    return str;
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
                char16_t a16 = this->convertHex(charCode);
                output += c16tochar(a16);
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