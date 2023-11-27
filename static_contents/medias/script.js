var is_focus = true;
var focused_index = 0;
var pre_word = "";

function focused_index_add(){
    if(focused_index >= 9) return;
    focused_index++;
}
function focused_index_sub(){
    if(focused_index <= -1) return;
    focused_index--;
}

function word_encode(word){
    var encoded = encodeURIComponent(word);
    encoded = encoded.replaceAll('%20', '+');
    return encoded;
}

function recolor_suggest(pre_num, now_num){
    var pre_con = document.getElementById('suggest-container-' + String(pre_num));
    if(!(pre_con == null)) pre_con.setAttribute('style', 'background-color: white');
    var pre_text = document.getElementById('suggest-box-' + String(pre_num));
    if(!(pre_text == null)) pre_text.setAttribute('style', 'background-color: white');
    
    var now_con = document.getElementById('suggest-container-' + String(now_num));
    if(!(now_con == null)) now_con.setAttribute('style', 'background-color: lightgray');
    var now_text = document.getElementById('suggest-box-' + String(now_num));
    if(!(now_text == null)) now_text.setAttribute('style', 'background-color: lightgray');
}

function gen_search_url(words){
    if(/^https?:\/\//.test(words)){
        return words
    }
    const base_url = 'https://www.google.com/search?q=';
    var url = base_url + word_encode(words) + '&hl=ja';

    return url;
}

function search(){
    const words = document.getElementById('search-text-box').value;
    const url = gen_search_url(words);
    window.location.href = url;
}

function down_enter(code){
    if(13 == code){
        search();
    }
}

async function callSuggestApi(word) {
    const res = await fetch("http://localhost:49153/api/suggest/" + word_encode(word));
    const suggests = await res.json();
    return suggests
}

document.addEventListener('keydown', event => {
    if(event.key == '/'){
        event.preventDefault();
        document.getElementById('search-text-box').focus();
    }
    else if(event.key == 'ArrowUp' & is_focus){
        event.preventDefault();
        var temp = focused_index;
        focused_index_sub();
        recolor_suggest(temp, focused_index);
        if(temp == -1) pre_word = document.getElementById('search-text-box').value; 
        if(focused_index == -1) document.getElementById('search-text-box').value = pre_word;
        else document.getElementById('search-text-box').value = document.getElementById('suggest-box-text-' + String(focused_index)).textContent;
    }
    else if(event.key == 'ArrowDown' & is_focus){
        event.preventDefault();
        var temp = focused_index;
        focused_index_add();
        recolor_suggest(temp, focused_index);
        if(temp == -1) pre_word = document.getElementById('search-text-box').value; 
        if(focused_index == -1) document.getElementById('search-text-box').value = pre_word;
        else document.getElementById('search-text-box').value = document.getElementById('suggest-box-text-' + String(focused_index)).textContent;
        
    }
});

async function showSuggest(){
    focused_index = -1;
    const suggests = await callSuggestApi(document.getElementById('search-text-box').value);
    var suggest_area = document.getElementById('suggest-area');
    suggest_area.innerHTML = "";
    if(suggests == null) return;
    for(var i = 0; i < 10; i++){
        if(suggests[String(i)] == null) break;
        suggest_area.innerHTML += "<div class=\"suggest-container\" id=\"suggest-container-" 
                                + String(i) 
                                + "\"><div class=\"suggest-box\" id=\"suggest-box-"
                                + String(i)
                                + "\"><p class=\"suggest-box-text\" id=\"suggest-box-text-"
                                + String(i)
                                + "\">" 
                                + suggests[String(i)] 
                                + "</p></div></div>";
    }
}

function closeSuggest(){
    var suggest_area = document.getElementById('suggest-area');
    suggest_area.innerHTML = "";
}

document.addEventListener('click', (e) => {
    if(!e.target.closest('.search-box')) {
        closeSuggest();
        is_focus = false;
    } else {
        if(!is_focus) showSuggest();
        is_focus = true;
    }
  })

document.getElementById('search-text-box').addEventListener("input", showSuggest);

document.getElementById('search-text-box').focus();