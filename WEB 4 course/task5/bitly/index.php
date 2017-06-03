<?php function getShortURL($url) { 
        $bitlyApikey = "R_0058d022beb1467b81283053231770b7";
        $bitlyLogin = "o_1srunel3i1";
        $apiURL = 'http://api.bit.ly/shorten?version=2.0.1&longUrl='.$url.'&login='.$bitlyLogin.'&apiKey='.$bitlyApikey; 
        $API = file_get_contents($apiURL); 
        $bitlyInfo = json_decode(utf8_encode($API),true); 
		if (!($bitlyInfo['errorCode']==0)) return false;
		if (isset($bitlyInfo['results'][urldecode($url)]['shortUrl'])) return $bitlyInfo['results'][urldecode($url)]['shortUrl'];
        return false; 
}
echo('<a href='.getShortURL("http://vk.com").'>'.getShortURL("http://vk.com").'</a>');
?>