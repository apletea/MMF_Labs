<?php 
session_start();
if(!isset($_SESSION["session_username"])) {
	header("location:login.php");
} else {
?>
<?php include("includes/header.php"); ?>

<div class="col-xs-12 col-md-4 col-md-offset-4 jumbotrone" id="welcome">	
	<h2>Welcome, <span><?php echo $_SESSION['session_username'];?>! </span></h2>
  <h3>Последний визит: <?php

require("includes/connection.php");
   $result = mysql_query("SELECT lastLogin FROM usertbl WHERE username=\"".$_SESSION['session_username']."\"");
  $date = strtotime(mysql_result($result, 0));
  $date = date("d.m.Y H:i", $date);
  echo $date;
 ?></h3>
	<p><a href="logout.php">Logout</a></p>
<?php
	$sql ="SELECT * FROM usertbl";
   	$result = mysql_query($sql) or die("Ошибка " . mysql_error($con));
   	echo ('<table class="table table-striped">
   		  <thead>
		      <tr>
		        <th>Username</th>
		        <th>banned</th>
		      </tr>
		    </thead>
		    <tbody>');
    
   	while ($row = mysql_fetch_array($result)){
       $username=$row['username'];
       $id=$row['id'];
   	   $sql ="SELECT banned FROM usertbl WHERE username='$username'";
       $res=mysql_result(mysql_query($sql), 0);
       if($res==1){
       	echo ('<tr><td>'.$row['username'].'</td><td><a href="includes/unban.php?id='.$row['id'].'" class="btn btn-success btn-ban" t">UNBAN</a></td>');
       }else{
       	echo ('<tr><td>'.$row['username'].'</td><td><a href="includes/ban.php?id='.$row['id'].'" class="btn btn-danger btn-ban">BAN</a></td>');
       }
   }
   echo('</tbody>')
?>
</div>

<?php include("includes/footer.php"); ?>
<?php
}
?>
<script>
    $('#ban').click(function(){
        $.post(
            "includes/ban.php"
        );
    });
</script>