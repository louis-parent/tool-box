<?php
	
	class Redirect
	{
		public static function to($url, $permanent = false)
		{
			header('Location: ' . $url, true, $permanent ? 301 : 302);
			exit();
		}
		
		public static function fromUrl($defaultDestination)
		{
			if(self::hasRedirection())
			{
				self::to(self::getRedirectionPage());
			}
			else
			{
				self::to($defaultDestination);
			}
		}
		
		public static function hasRedirection()
		{
			return isset($_GET["redirect"]);
		}
		
		public static function getRedirectionPage()
		{
			return urldecode($_GET["redirect"]);
		}
		
		public static function toGetData()
		{
			if(self::hasRedirection())
			{
				return "redirect=" . urlencode(self::getRedirectionPage());
			}
			else
			{
				return "";
			}
		} 
	}
?>
