<?php

	class ReCaptcha
	{
		private static $siteVerifyUrl = "https://www.google.com/recaptcha/api/siteverify";
		private static $secret = "TODO";

		public static function verifyResponse($response)
		{
		    if ($response == null || strlen($response) == 0)
		    {
		        return false;
		    }

		    $postResponse = self::sendHTTPPost(array("secret" => self::$secret, "response" => $response));
		    										  
		    if($postResponse === false)
		    {		    	
		   		return false;
		    }
		    else
		    {
		    	$captchaResult = json_decode($postResponse, true);
		    	return $captchaResult["success"];
		    }
		}

		private static function sendHTTPPost($params)	
		{
			$options = array('http' => array('method'  => 'POST',
											 'header'  => 'Content-type: application/x-www-form-urlencoded',
											 'content' => http_build_query($params))
			);
			
			$context = stream_context_create($options);
			return file_get_contents(self::$siteVerifyUrl, false, $context);	
		}
	}

?>
