<?php
session_start();
?>

<?php require_once("includes/connection.php"); ?>
<?php include("includes/header.php"); ?>

<?php

if(isset($_SESSION["session_username"])){
// echo "Session is set"; // for testing purposes
header("Location: intropage.php");
}

if(isset($_POST["login"])){

if(!empty($_POST['username']) && !empty($_POST['password'])) {
    $username=$_POST['username'];
    $password=$_POST['password'];

    $query =mysql_query("SELECT * FROM usertbl WHERE username='".$username."' AND password='".$password."'");

    $numrows=mysql_num_rows($query);
    if($numrows!=0)

    {
    while($row=mysql_fetch_assoc($query))
    {
    $dbusername=$row['username'];
    $dbpassword=$row['password'];
    }

    if($username == $dbusername && $password == $dbpassword)

    {


    $_SESSION['session_username']=$username;
    

    /* Redirect browser */
    header("Location: intropage.php");
    }
    } else {

 $message =  "Invalid username or password!";
    }

} else {
    $message = "All fields are required!";
}
}
?>




    <div class="col-xs-12 col-sm-6 col-sm-offset-3 col-md-4 col-md-offset-4 wrapper">
    <div class=" text-center">
            <div id="login">
    <h1>LOGIN</h1>

<form name="loginform" id="loginform" action="" method="POST">
<p class="input-group">
        <span class="input-group-addon" id="basic-addon1"><i class="fa fa-user" aria-hidden="true"></i></span>
        <input type="text" name="username" id="username" class="form-control" value=""/>
    </p>
    
    <p class="input-group">
    
        <span class="input-group-addon" id="basic-addon1"><i class="fa fa-lock" aria-hidden="true"></i></span>
        <input type="password" name="password" id="password" class="form-control" value=""/>
    </p>
        <p>
        <input type="submit" name="login" class="btn btn-default" value="Log In" />
         <a href="register.php" class="btn  btn-info">Register</a>
         </p>

<?php
error_reporting(0);
require_once("includes/connection.php");
require_once("includes/FBAuth.php");
$fb = new FBAuth(array(
                "client_id" => "351739135167506",
                "client_secret" => "381ad374a82241ce8d09c740463f6b9b",
                "redirect_uri" => "http://taskone.loc/login.php"
));
$fb->auth($_GET["code"]);
echo ("<a href='" . $fb->get_link() . "'><img width=\"64\" alt=\"fb\" src=\"img/fb.png\"></a>");
$username = strval($fb->user_info["id"]);
$query    = mysql_query("SELECT * FROM usertbl WHERE username='" . $username . "'");

$numrows  = mysql_num_rows($query);
if ($fb->auth_status) {
    if ($numrows != 0) {
            while ($row = mysql_fetch_assoc($query)) {
                echo (mysql_fetch_assoc($query));
                $dbusername = $row['username'];
            }
            
            if ($username == $dbusername) {
                
                
                $_SESSION['session_username'] = $username;
                
                /* Redirect browser */
                header("Location: intropage.php");
            }
        } else {
            
            $message = "Invalid username or password!";
        }
}
require_once("includes/VKAuth.php");
$vk = new VKAuth(array(
                "client_id" => "5672447",
                "client_secret" => "VuCO6EDV0WsdIDM3i0aT",
                "redirect_uri" => "http://taskone.loc/login.php"
));
$vk->auth($_GET["code"]);
echo ("<a href='" . $vk->get_link() . "'><img width=\"64\" alt=\"fb\" src=\"img/vk.png\"></a>");
$username = strval($vk->user_info["uid"]);
$query    = mysql_query("SELECT * FROM usertbl WHERE username='" . $username . "'");
$numrows  = mysql_num_rows($query);
if ($vk->auth_status) {
    if ($numrows != 0) {
          while ($row = mysql_fetch_assoc($query)) {
                echo (mysql_fetch_assoc($query));
                $dbusername = $row['username'];
            }
            
            if ($username == $dbusername) {
                
                
                $_SESSION['session_username'] = $username;
                
                /* Redirect browser */
                header("Location: intropage.php");
            }
        } else {
            
            $message = "Invalid username or password!";
        }      
}


require_once("includes/TWAuth.php");
error_reporting(0);

    $tw = new TWAuth(array(

        "client_id"     => "4iFJb4R3kYgIqyuugpMGWjdw3",
        "client_secret" => "EavxyUFQXOE6aBUogHiM3zjQObAt4sFA1zHqZceYfDXyoNv6GJ",
        "redirect_uri"  => "http://taskone.loc/login.php"
    ));

    if(isset($_GET["oauth_token"], $_GET["oauth_verifier"])){

        $tw->auth(
            $_GET["oauth_token"],
            $_GET["oauth_verifier"]
        );
    }
echo ("<a href='" . $tw->get_link() . "'><img width=\"64\" alt=\"tw\" src=\"img/tw.png\"></a>");
$username = strval($tw->user_info["screen_name"]);
$query    = mysql_query("SELECT * FROM usertbl WHERE username='" . $username . "'");
$numrows  = mysql_num_rows($query);
if ($tw->auth_status) {
               if ($numrows != 0) {
          while ($row = mysql_fetch_assoc($query)) {
                echo (mysql_fetch_assoc($query));
                $dbusername = $row['username'];
            }
            
            if ($username == $dbusername) {
                
                
                $_SESSION['session_username'] = $username;
                
                /* Redirect browser */
                header("Location: intropage.php");
            }
        } else {
            
            $message = "Invalid username or password!";
        }  
}
?>
</form>
    
    </div>
    </div>
    </div>

	<?php include("includes/footer.php"); ?>
	
	<?php
if (!empty($message)) {
    echo ('<script type=\'text/javascript\'>alert('."'". $message ."'". ');</script>');
}
?>
	