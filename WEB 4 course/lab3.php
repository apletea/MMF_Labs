<!DOCTYPE HTML>
<html>
<head>
   <meta charset="utf-8">
   <link rel="stylesheet" type="text/css" href="css/CSS.css">
   <title>lab3</title>
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
					<li><a href="lab4.php">lab4</a></li>
					<li class="vypod2"><a href="#">lab5</a>
						<ul>
							<li><a href="lab5log.php">Отметиться</a></li>
							<li><a href="lab5info.php">Статистика</a></li>
							<li><a href="lab5del.php">Почистить</a></li>
						</ul>
					</li>
				</ul>
			</li>
			<li><a href="#">Прочая информация</a></li>	
		</ul>
	</nav>
	<section>
		<article>
			<h2>Условие</h2>
			<p>	Имеется	список членов коллектива с указанием принадлежности каждого 
			к различным общественным организациям 
			(профком, ученый совет, общество книголюбов, федерация пентикса и т.д.).
			Напечатайте	приглашение	всем членам на очередное заседание указанной организации. 
			Задается только вид организации, место и время сбора.</p>
		</article>
		<article>
			<h2>Выполнение</h2>
			<form method="post" action="lab3.php">
				<div>
					<fieldset>	
					<legend>Выберете организацию, место и время встречи</legend>
						<label for="country">Организация</label>
						<select name=organization>
							<option selected="selected"></option>
							<option>ЗОО"Захват Мира"</option>
							<option>ЗОО"Порабощение Вселенной"</option>
							<option>ЗОО"Управление захваченным"</option>
						</select>   
						<label>Место встречи</label>
						<input name=mesto> 
						<label>Дата</label>
						<input name=date type="date" value="2015-03-25">
						<label>Время</label>
						<input name=time type="time" value="10:00">
						<input class="submit" type="submit" value="Ввод=)">
					</fieldset>
					<fieldset>	
					<legend>Приглашения</legend>
					<div>
						<?php
						$fp=fopen("./SpisokOrg.txt","r");
						while(!feof	($fp))
						{
							$text = 'раз четыре шестьдесят сорок пользователь он автомобиль номер';
							$arr = explode(" ", $text);
							for ($i=0; $i<count($arr); $i++) {
							    $max = $arr[0];
							    if(strlen($arr[$i]) > strlen($max)){

							        $max = $arr[$i];
							      }
							    }
							echo $max;
						}
						fclose($fp);
						?>
					</div>
					</fieldset>
				</div>	
			</form>
		</article>
	</section>
	<footer>
	</footer>
</body>
</html>