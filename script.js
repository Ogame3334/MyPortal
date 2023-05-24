function gen_search_url(words){
    if(/^https?:\/\//.test(words)){
        return words
    }
    const base_url = 'https://www.google.com/search?q=';
    // var url = base_url + words;
    // words = words.replaceAll('#', '%23').replaceAll('&', '%26').replaceAll('+', '%2B').replaceAll('?', '%3F').replaceAll('=', '%3D').replaceAll(' ', '+').replaceAll('　', '+');
    var url = base_url + encodeURIComponent(words) + '&hl=ja';
    url = url.replaceAll('%20', '+')

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