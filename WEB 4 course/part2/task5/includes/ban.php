<?php
    $id=$_GET['id'];
        require("connection.php");
        mysql_query("UPDATE `usertbl` SET `banned` = '1' WHERE `usertbl`.`id` = ".$id);
        header("Location: http://taskone.loc/intropage.php")
?>
