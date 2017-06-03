<?php
class VKAuth{

	public $settings	= array();
	public $auth_status = false;
	public $user_info   = array();

	public function __construct($settings){

		if(isset($settings["client_id"], $settings["client_secret"], $settings["redirect_uri"])){

			$this->settings = $settings;
		}
	}

	public function auth($code){

		if($code && $this->settings){

			$query = urldecode(http_build_query(array(

				"client_id"		 => $this->settings["client_id"],
				"client_secret"  => $this->settings["client_secret"],
				"code" 			 => $code,
				"redirect_uri" 	 => $this->settings["redirect_uri"]
			)));

			$token = json_decode(file_get_contents("https://oauth.vk.com/access_token?".$query), true);

			if(isset($token["access_token"])){

				$query = urldecode(http_build_query(array(

					"uids"         => $token["user_id"],
					"fields"       => "uid,first_name,last_name,photo_100",
					"access_token" => $token["access_token"]
				)));

				$this->user_info = json_decode(file_get_contents("https://api.vk.com/method/users.get?".$query), true);

				if(isset($this->user_info["response"][0]["uid"])){

					$this->user_info = $this->user_info["response"][0];
					$this->auth_status = true;

					return true;
				}
			}
		}

		return false;
	}

	public function get_link(){

		if($this->settings){

			$query = urldecode(http_build_query(array(

				"client_id"     => $this->settings["client_id"],
				"redirect_uri"  => $this->settings["redirect_uri"],
				"response_type" => "code"
			)));

			return "https://oauth.vk.com/authorize?".$query;
		}

		return false;
	}
}
?>