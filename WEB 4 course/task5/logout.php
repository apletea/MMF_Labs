<?php 
session_start();
require("includes/connection.php");

date_default_timezone_set('Europe/Moscow');
$sql = "UPDATE usertbl SET lastLogin=\"".date("Y-m-d H:i:s")."\" WHERE username=\"".$_SESSION['session_username']."\"";
echo $sql;
mysql_query($sql);

unset($_SESSION['session_username']);
session_destroy();
header("location:login.php");
?>
