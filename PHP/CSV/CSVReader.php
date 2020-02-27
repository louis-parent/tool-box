<?php

	class CSVReader
	{
		private $filename;
		private $isHeaderOnFirstLine;
		
		public function __construct($filename, $isHeaderOnFirstLine)
		{
			$this->filename = $filename;
			$this->isHeaderOnFirstLine = $isHeaderOnFirstLine;
		}
		
		public function isHeaderOnFirstLine()
		{
			return $this->isHeaderOnFirstLine;
		}
		
		public function parse()
		{
			$headerArray = array();
			$start = 0;
			
			$lines = $this->getLines();
			
			$rows = array();
			
			if($this->isHeaderOnFirstLine)
			{
				$headerArray = explode(';', $lines[0]);
				$start = 1;
				
			}
			else
			{
				$headerArray = range(0, count(explode(';', $lines[0])));
			}
			
			for($i = $start; $i < count($lines); $i++)
			{
				$row = array();
				$exploded = explode(';', $lines[$i]);
				for($j = 0; $j < count($exploded); $j++)
				{
					$row[$headerArray[$j]] = $exploded[$j];
				}
				array_push($rows, $row);
			}
			
			return $rows;
		}
		
		public function parseAndSort($filters)
		{
			return self::sort($this->parse(), $filters);
		}
		
		public static function sort($csv, $filters)
		{
			$sorted = array();
			
			foreach($csv as $row)
			{
				$insert = true;
				
				foreach($filters as $attribute => $filter)
				{
					if(!isset($row[$attribute]) || $row[$attribute] != $filter)
					{
						$insert = false;
					}	
				}
				
				if($insert)
				{
					array_push($sorted, $row);
				}
			}
			
			return $sorted;
		}
		
		private function getLines()
		{
			return explode(PHP_EOL, file_get_contents($this->filename));
		}
	}
