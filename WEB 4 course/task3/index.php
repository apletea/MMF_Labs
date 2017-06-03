<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Lab 3</title>
    <link rel="stylesheet" type="text/css" href="https://bootswatch.com/paper/bootstrap.min.css">
</head>
<body class="container">

<a href="second.php">second</a><br>
<a href="third.php">third</a><br>
<a href="fourth.php">fourth</a><br>

<?php

$file = fopen("address.txt", "a+");
$arr = array();
$k = 0;

echo "<b>На сие страницу переходили со следующий страниц:</b><br>";
while(!feof($file)) {
    array_push($arr, fgets($file));
    echo $arr[$k] . "<br>";
    $k++;
}

if($_SERVER['HTTP_REFERER']) {
    echo "<b>Вы перешли со страницы:<b> " . $_SERVER['HTTP_REFERER'];
    fwrite($file, $_SERVER['HTTP_REFERER'] . "\n");
    array_push($arr, $_SERVER['HTTP_REFERER']);
}

fclose($file);

echo "<br><b>Валидные url без localhost : </b><br><br>";

for($i = 0; $i < count($arr); $i++) {
    if(preg_match('/^http(s)?:\/\/(?!localhost)[a-z0-9]+(.[a-z0-9-]+)*$/i', $arr[$i])) {
        echo $arr[$i] . "<br>";
    }
}

?>

</body>
</html>

