<?php
/*========================================== 
	Appointment: Аутентификации через Twitter
	File: TWAuth.php
	Author: Anton Kuliashou
===========================================*/

class TWAuth{

	public $settings	= array();
	public $auth_status = false;
	public $user_info	= array();

	private $app_data = array();

	public function __construct($settings){

		if(isset($settings["client_id"], $settings["client_secret"], $settings["redirect_uri"])){

			$this->settings = $settings;

			// Формирование подписи для запроса
			$an = md5(uniqid(rand(), true));
			$at = time();

			$sign_str = "GET&".urlencode("https://api.twitter.com/oauth/request_token")."&".implode(
				"",
				array_map("urlencode", array(

					"oauth_callback=".urlencode($this->settings["redirect_uri"])."&",
					"oauth_consumer_key=".$this->settings["client_id"]."&",
					"oauth_nonce=".$an."&",
					"oauth_signature_method=HMAC-SHA1&",
					"oauth_timestamp=".$at."&",
					"oauth_version=1.0"
				))
			);

			$as = base64_encode(hash_hmac("sha1", $sign_str, $this->settings["client_secret"]."&", true));

			// Формирование токена для запроса
			$ot_url = "https://api.twitter.com/oauth/request_token?oauth_callback=".urlencode($this->settings["redirect_uri"]).implode("&", array(

					"&oauth_consumer_key=".$this->settings["client_id"],
					"oauth_nonce=".$an,
					"oauth_signature=".urlencode($as),
					"oauth_signature_method=HMAC-SHA1",
					"oauth_timestamp=".$at,
					"oauth_version=1.0"
				)
			);

			$response = file_get_contents($ot_url);
			parse_str($response, $response);

			$this->app_data["response_at"] 		  = $response["oauth_token"];
			$this->app_data["response_at_secret"] = $response["oauth_token_secret"];
		}
	}

	public function auth($oauth_token, $oauth_verifier){

		// Формирование подписи для запроса
		$an = md5(uniqid(rand(), true));
		$at = time();

		$sign_str = "GET&".urlencode("https://api.twitter.com/oauth/access_token")."&".implode(
			"",
			array_map("urlencode", array(

				"oauth_consumer_key=".$this->settings["client_id"]."&",
				"oauth_nonce=".$an."&",
				"oauth_signature_method=HMAC-SHA1&",
				"oauth_token=".$oauth_token."&",
				"oauth_timestamp=".$at."&",
				"oauth_verifier=".$oauth_verifier."&",
				"oauth_version=1.0"
			))
		);

		$as = base64_encode(hash_hmac("sha1", $sign_str, $this->settings["client_secret"]."&".$this->app_data["response_at_secret"], true));

		// Формирование токена для запроса
		$ot_url = "https://api.twitter.com/oauth/access_token?".implode("&", array(

			"oauth_nonce=".$an,
			"oauth_signature_method=HMAC-SHA1",
			"oauth_timestamp=".$at,
			"oauth_consumer_key=".$this->settings["client_id"],
			"oauth_token=".urlencode($oauth_token),
			"oauth_verifier=".urlencode($oauth_verifier),
			"oauth_signature=".urlencode($as),
			"oauth_version=1.0"
		));

		$response = file_get_contents($ot_url);
		parse_str($response, $response);

		if(isset($response["oauth_token"], $response["oauth_token_secret"], $response["screen_name"])){

			// Формирование подписи для запроса
			$an = md5(uniqid(rand(), true));
			$at = time();

			$oauth_token 		= $response["oauth_token"];
			$oauth_token_secret = $response["oauth_token_secret"];
			$screen_name 		= $response["screen_name"];

			$sign_str = "GET&".urlencode("https://api.twitter.com/1.1/users/show.json")."&".implode(
				"",
				array_map("urlencode", array(

					"oauth_consumer_key=".$this->settings["client_id"]."&",
					"oauth_nonce=".$an."&",
					"oauth_signature_method=HMAC-SHA1&",
					"oauth_timestamp=".$at."&",
					"oauth_token=".$oauth_token."&",
					"oauth_version=1.0&",
					"screen_name=".$screen_name
				))
			);

			$as = base64_encode(hash_hmac("sha1", $sign_str, $this->settings["client_secret"]."&".$oauth_token_secret, true));

			// Формирование токена для запроса (Данные пользователя)
			$ot_url = "https://api.twitter.com/1.1/users/show.json?".implode("&", array(

				"oauth_consumer_key=".$this->settings["client_id"],
				"oauth_nonce=".$an,
				"oauth_signature=".urlencode($as),
				"oauth_signature_method=HMAC-SHA1",
				"oauth_timestamp=".$at,
				"oauth_token=".urlencode($oauth_token),
				"oauth_version=1.0",
				"screen_name=".$screen_name
			));

			$this->user_info = json_decode(file_get_contents($ot_url), true);

			if(isset($this->user_info["id"])){

				$this->auth_status = true;

				return true;
			}
		}

		return false;
	}

	public function get_link(){

		if($this->app_data){

			return "https://api.twitter.com/oauth/authorize?oauth_token=".$this->app_data["response_at"];
		}

		return false;
	}
}
?>