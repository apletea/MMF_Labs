<!DOCTYPE HTML>
<html>
<head>
   <meta charset="utf-8">
   <link rel="stylesheet" type="text/css" href="css/CSS.css">
   <title>lab2</title>
</head>
<body>
	<header>
	</header>
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
			<p>Напишите функцию вычисления НОД(a, b)</p>
		</article>
		<article>
			<?php
				function nod($a, $b){
					while ($a && $b)
				        if ($a >= $b)
				           $a %= $b;
				        else
				           $b %= $a;
				    return $a | $b;
				}
				$a = 32;
				$b = 56;
				echo 'a: '.$a .'<br>';
				echo 'b: '.$b . '<br>';
				echo 'nod: '.nod($a, $b);
			?>

		</article>
	</section>
	<footer>
	</footer>
</body>
</html>