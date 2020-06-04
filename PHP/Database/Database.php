<?php
	class Database
	{
		private static $instance = null;
	
		private $host = "TODO";
		private $db = "TODO";
		private $user = "TODO";
		private $pwd = "TODO";
		
		private $pdo = null;
		
		private function __construct() {}
		
		protected function getDBConfig()
		{
			return array(
				"host" => $this->host,
				"db" => $this->db,
				"user" => $this->user,
				"pwd" => $this->pwd
			);
		}

		public function getPDO()
		{
			if($this->pdo == null)
			{
				$this->pdo = new PDO('mysql:host=' . $this->host . ';dbname=' . $this->db, $this->user, $this->pwd, array(PDO::ATTR_PERSISTENT => true));
			}
			
			return $this->pdo;
		}
		
		public static function getInstance()
		{
			if(self::$instance == null)
			{
				self::$instance = new Database();
			}
			
			return self::$instance;
		}
	}
?>
