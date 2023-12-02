#include "MyPage_MainIndex.h"

using namespace MyPortal;

void MainIndex::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
    // viewに渡すデータはHttpViewData型に格納します
    // drogon::HttpViewData viewData;
    // HttpViewData へのデータの格納は、key - valueのペアで行います。
    // ここでは name というキーワードに対して、リクエストで渡ってきた request_name 引数の値を取得し設定しています。
    // viewData.insert(
    //     "name", 
    //     req->getParameter("request_name")
    //     );

    //"HelloView.csp"から構築されたviewへの呼び出しを作成し、コールバックに登録します。
    // auto resp = HttpResponse::newHttpResponse();
    // resp->setStatusCode(k200OK);
    // resp->setContentTypeCode(CT_TEXT_HTML);
    // resp->setBody("<h1>hogehoge</h1>");
    callback(
        HttpResponse::newFileResponse("/medias/index.html")
        // resp
        );
}
