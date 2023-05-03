function gen_search_url(words){
    if(words.slice(0, 8) == 'https://' || words.slice(0, 7) == 'http://'){
        return words
    }
    const base_url = 'https://www.google.com/search?q=';
    words = base_url + words;
    words = words.replaceAll('+', '%2B').replaceAll(' ', '+').replaceAll('　', '+');
    url = words + '&hl=ja';

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

document.getElementById('search-text-box').focus();