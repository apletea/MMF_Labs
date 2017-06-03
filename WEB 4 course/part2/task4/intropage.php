<!DOCTYPE html>
<html>
<head>
  <title>Lab4</title>
  <link rel="stylesheet" type="text/css" href="https://bootswatch.com/paper/bootstrap.min.css">

</head>
<body class="container">
  <?php require_once("connection.php"); ?>
  <?php
  ?>
  <form method="post" action="intropage.php">
    <div class="form-group">
      <label for="word">Ваше слово:</label>
      <input type="text" class="form-control" id="word" name='word'>
    </div>
    <button type="submit" class="btn btn-default">Перевести</button>
  
</form>

<div class="well">

<?php
    if($_POST['word']){
      $query =mysql_query("SELECT * FROM words WHERE rus='".$_POST['word']."'");
    };
?>
    
  </div>
</body>
</html>