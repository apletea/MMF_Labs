<!DOCTYPE HTML>
<html>
<head>
   <meta charset="utf-8">
   <link rel="stylesheet" type="text/css" href="css/CSS.css">
   <title>lab1</title>
</head>
<body>
	<header>
	<nav>
		<ul class="clearfix">
			<li class="Home"><a href="index.php">Главная</a></li>
			<li class="vypod">
				<a href="#">Лабы</a>
				<ul>
					<li><a href="lab1.php">lab1</a></li>
					<li><a href="lab2.php">lab2</a></li>
					<li><a href="lab3.php">lab3</a></li>
					
				</ul>
			</li>
			<li><a href="#">Прочая информация</a></li>	
		</ul>
	</nav>
	<section>
		<article>
			<h2>Условие</h2>
			<p>Создайте ассоциативный массив. Найдите количество различных элементов массива.</p>
		</article>
		<article>
			<h2>Выполнение</h2>
			<?php
				$name = array("Будный" => "Сымон ", "Скорина" => "Франциск ",
				 "Мавр" => "Янка","Богданович" => "Максим", "Купала" => "Янка","Горецкий" => "Максим", "Колас" => "Якуб", "Чечот" => "Ян");
				echo "<h4>Элементы массива: </h4>";
				foreach($name as $key => $value) 
 				{ 
 					echo "$value $key<br/>"; 
  				}
  				$flag=0; 
  				foreach($name as $key => $value) 
 				{ 
     				foreach($name as $key1 => $value1) 
	 				{ 
	 					
	     				if(($value==$value1)&&($key!=$key1))
	     				{
	     					$flag++;
	     				}
	  				}
  				}
  				$kol=count($name)-$flag/2;
  				echo "<h4>Количество различных элементов массива: $kol </h4>";
			?>
		</article>
	</section>
	<footer>
	</footer>
</body>
</html>