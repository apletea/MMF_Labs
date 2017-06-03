'use strict'
function getShortURL(url) { 
        let bitlyApikey = "R_0058d022beb1467b81283053231770b7";
        let bitlyLogin = "o_1srunel3i1";
        let apiURL = 'http://api.bit.ly/shorten?version=2.0.1&longUrl='+url+'&login='+bitlyLogin+'&apiKey='+$bitlyApikey; 
        let $("#result").load(apiURL);
        bitlyInfo = 