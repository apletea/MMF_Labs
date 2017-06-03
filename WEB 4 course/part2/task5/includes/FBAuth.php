<?php
/*========================================== 
	Appointment: Аутентификации через Facebook
	File: FBAuth.php
	Author: Anton Kuliashou
===========================================*/

class FBAuth{

	public $settings	= array();
	public $auth_status = false;
	public $user_info	= array();

	public function __construct($settings){

		if(isset($settings["client_id"], $settings["client_secret"], $settings["redirect_uri"])){

			$this->settings = $settings;
		}
	}

	public function auth($code){

		if($code && $this->settings){

			$query = urldecode(http_build_query(array(

				"client_id"		 => $this->settings["client_id"],
				"redirect_uri" 	 => $this->settings["redirect_uri"],
				"client_secret"  => $this->settings["client_secret"],
				"code" 			 => $code
			)));

			$token = false;
			parse_str(file_get_contents("https://graph.facebook.com/oauth/access_token?".$query), $token);

			if(isset($token["access_token"])){

				$query = urldecode(http_build_query(array(

					"access_token" => $token["access_token"],
					"fields"	   => "id,first_name,last_name,picture.width(120).height(120)"
				)));

				$this->user_info = json_decode(file_get_contents("https://graph.facebook.com/me?".$query), true);

				if(isset($this->user_info["id"])){

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

			return "https://www.facebook.com/dialog/oauth?".$query;
		}

		return false;
	}
}
?>