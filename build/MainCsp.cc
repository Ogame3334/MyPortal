//this file is generated by program(drogon_ctl) automatically,don't modify it!
#include "MainCsp.h"
#include <drogon/utils/OStringStream.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <deque>
#include <queue>
using namespace drogon;
std::string MainCsp::genText(const DrTemplateData& MainCsp_view_data)
{
	drogon::OStringStream MainCsp_tmp_stream;
	std::string layoutName{""};
	MainCsp_tmp_stream << "<html>\n";
	MainCsp_tmp_stream << "    <head>\n";
	MainCsp_tmp_stream << "        <title>OgamePortalSite</title>\n";
	MainCsp_tmp_stream << "        <link href=\"./myportal/style.css\" rel=\"stylesheet\">\n";
	MainCsp_tmp_stream << "        <link rel=\"icon\" href=\"favicon.ico\">\n";
	MainCsp_tmp_stream << "        <link rel=\"icon\" type=\"image/png\" href=\"./myportal/images/icon.webp\">\n";
	MainCsp_tmp_stream << "    </head>\n";
	MainCsp_tmp_stream << "    <body>\n";
	MainCsp_tmp_stream << "        <header>\n";
	MainCsp_tmp_stream << "            <div class=\"header-pin-right\"></div>\n";
	MainCsp_tmp_stream << "            <div class=\"header-pin-left\"></div>\n";
	MainCsp_tmp_stream << "            <h1 class=\"headline\">\n";
	MainCsp_tmp_stream << "                <a>PortalBoard</a>\n";
	MainCsp_tmp_stream << "            </h1>\n";
	MainCsp_tmp_stream << "        </header>\n";
	MainCsp_tmp_stream << "        <main>\n";
	MainCsp_tmp_stream << "            <!-- <div class=\"searchbox-pin-right\"></div>\n";
	MainCsp_tmp_stream << "            <div class=\"searchbox-pin-left\"></div> -->\n";
	MainCsp_tmp_stream << "            <div class=\"search-box\">\n";
	MainCsp_tmp_stream << "                <a href=\"javascript:search();\">\n";
	MainCsp_tmp_stream << "                    <img src=\"./myportal/images/search_button.webp\" class=\"search-button\">\n";
	MainCsp_tmp_stream << "                </a>\n";
	MainCsp_tmp_stream << "                <input class=\"search-text-box\" type=\"text\" id=\"search-text-box\" onkeypress=\"down_enter(event.keyCode);\" >\n";
	MainCsp_tmp_stream << "                <div class=\"suggest-box\"></div>\n";
	MainCsp_tmp_stream << "            </div>\n";
	MainCsp_tmp_stream << "            <div class=\"cork-board\">\n";
	MainCsp_tmp_stream << "                <br>\n";
	MainCsp_tmp_stream << "                <div class=\"board\">\n";
	MainCsp_tmp_stream << "                    <div class=\"line-right\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"line-left\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"pin\"></div>\n";
	MainCsp_tmp_stream << "                    <br>\n";
	MainCsp_tmp_stream << "                    <div class=\"panel\">\n";
	MainCsp_tmp_stream << "                        <h2 class=\"category-name\">Google</h2>\n";
	MainCsp_tmp_stream << "                        <div class=\"images\">\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.google.com/\">\n";
	MainCsp_tmp_stream << "                                <img class=\"c-btn\" src=\"./myportal/images/Google/Google.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.youtube.com/\">\n";
	MainCsp_tmp_stream << "                                <img class=\"c-btn\" src=\"./myportal/images/Google/youtube.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://mail.google.com/mail/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Google/gmail.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://drive.google.com/drive/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Google/GoogleDrive.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.google.co.jp/maps/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Google/GoogleMap.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                        </div>\n";
	MainCsp_tmp_stream << "                    </div>\n";
	MainCsp_tmp_stream << "                </div>\n";
	MainCsp_tmp_stream << "                <div class=\"board\">\n";
	MainCsp_tmp_stream << "                    <div class=\"line-right\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"line-left\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"pin\"></div>\n";
	MainCsp_tmp_stream << "                    <br>\n";
	MainCsp_tmp_stream << "                    <div class=\"panel\">\n";
	MainCsp_tmp_stream << "                        <h1 class=\"category-name\">Subscription & Novel</h1>\n";
	MainCsp_tmp_stream << "                        <div class=\"images\" style=\"display: flex; flex-wrap: wrap;\" >\n";
	MainCsp_tmp_stream << "                            <a href=\"https://animestore.docomo.ne.jp/animestore/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Subscription/danime.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.amazon.co.jp/gp/video/storefront/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Subscription/primevideo.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://syosetu.com/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Novel/narou.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://kakuyomu.jp/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Novel/kakuyomu.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                        </div>\n";
	MainCsp_tmp_stream << "                    </div>\n";
	MainCsp_tmp_stream << "                </div>\n";
	MainCsp_tmp_stream << "                <div class=\"board\">\n";
	MainCsp_tmp_stream << "                    <div class=\"line-right\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"line-left\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"pin\"></div>\n";
	MainCsp_tmp_stream << "                    <br>\n";
	MainCsp_tmp_stream << "                    <div class=\"panel\">\n";
	MainCsp_tmp_stream << "                        <h1 class=\"category-name\">Campas</h1>\n";
	MainCsp_tmp_stream << "                        <div class=\"images\" style=\"display: flex; flex-wrap: wrap;\" >\n";
	MainCsp_tmp_stream << "                            <a href=\"https://ict-i.el.kyutech.ac.jp/my/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Campas/moodle.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://virginia.jimu.kyutech.ac.jp/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Campas/LiveCampas.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.iizuka.kyutech.ac.jp/campuslife/schedule/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Campas/CampasCalender.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.iizuka.kyutech.ac.jp/faculty/educational-info#i-4\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Campas/schedule.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://edragon-syllabus.jimu.kyutech.ac.jp/guest/syllabuses\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Campas/syllabus.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                        </div>\n";
	MainCsp_tmp_stream << "                    </div>\n";
	MainCsp_tmp_stream << "                </div>\n";
	MainCsp_tmp_stream << "                <div class=\"board\">\n";
	MainCsp_tmp_stream << "                    <div class=\"line-right\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"line-left\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"pin\"></div>\n";
	MainCsp_tmp_stream << "                    <br>\n";
	MainCsp_tmp_stream << "                    <div class=\"panel\">\n";
	MainCsp_tmp_stream << "                        <h1 class=\"category-name\">SNS</h1>\n";
	MainCsp_tmp_stream << "                        <div class=\"images\" style=\"display: flex; flex-wrap: wrap;\" >\n";
	MainCsp_tmp_stream << "                            <a href=\"https://twitter.com/home/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/SNS/twitter.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://mastodon.compositecomputer.club/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/SNS/mastodon.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.instagram.com/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/SNS/instagram.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://toybox.compositecomputer.club/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/SNS/ToyBox.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                        </div>\n";
	MainCsp_tmp_stream << "                    </div>\n";
	MainCsp_tmp_stream << "                </div>\n";
	MainCsp_tmp_stream << "                <div class=\"board\">\n";
	MainCsp_tmp_stream << "                    <div class=\"line-right\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"line-left\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"pin\"></div>\n";
	MainCsp_tmp_stream << "                    <br>\n";
	MainCsp_tmp_stream << "                    <div class=\"panel\">\n";
	MainCsp_tmp_stream << "                        <h1 class=\"category-name\">Learning</h1>\n";
	MainCsp_tmp_stream << "                        <div class=\"images\" style=\"display: flex; flex-wrap: wrap;\" >\n";
	MainCsp_tmp_stream << "                            <a href=\"https://chat.openai.com/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Lerning/chatgpt.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.deepl.com/ja/translator\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Lerning/deepl.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://www.desmos.com/calculator?lang=ja\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Lerning/desmos.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://ja.overleaf.com/project\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Lerning/overleaf.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                        </div>\n";
	MainCsp_tmp_stream << "                    </div>\n";
	MainCsp_tmp_stream << "                </div>\n";
	MainCsp_tmp_stream << "                <div class=\"board\">\n";
	MainCsp_tmp_stream << "                    <div class=\"line-right\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"line-left\"></div>\n";
	MainCsp_tmp_stream << "                    <div class=\"pin\"></div>\n";
	MainCsp_tmp_stream << "                    <br>\n";
	MainCsp_tmp_stream << "                    <div class=\"panel\">\n";
	MainCsp_tmp_stream << "                        <h1 class=\"category-name\">Other</h1>\n";
	MainCsp_tmp_stream << "                        <div class=\"images\" style=\"display: flex; flex-wrap: wrap;\" >\n";
	MainCsp_tmp_stream << "                            <a href=\"https://github.com/Ogame3334/\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Other/github.png\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                            <a href=\"https://ogame3334.github.io/MyPage/?anim=false\">\n";
	MainCsp_tmp_stream << "                                <img src=\"./myportal/images/Other/icon.webp\">\n";
	MainCsp_tmp_stream << "                            </a>\n";
	MainCsp_tmp_stream << "                        </div>\n";
	MainCsp_tmp_stream << "                    </div>\n";
	MainCsp_tmp_stream << "                </div>\n";
	MainCsp_tmp_stream << "            </div>\n";
	MainCsp_tmp_stream << "        </main>\n";
	MainCsp_tmp_stream << "        <script src=\"./myportal/script.js\"></script>\n";
	MainCsp_tmp_stream << "    </body>\n";
	MainCsp_tmp_stream << "</html>\n";
if(layoutName.empty())
{
std::string ret{std::move(MainCsp_tmp_stream.str())};
return ret;
}else
{
auto templ = DrTemplateBase::newTemplate(layoutName);
if(!templ) return "";
HttpViewData data = MainCsp_view_data;
auto str = std::move(MainCsp_tmp_stream.str());
if(!str.empty() && str[str.length()-1] == '\n') str.resize(str.length()-1);
data[""] = std::move(str);
return templ->genText(data);
}
}
