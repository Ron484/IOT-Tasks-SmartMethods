<?php



$db_host='localhost';
$db_username='root';
$db_password='Rr0533831624';//chang with your database password
$db_name='get_sensorval';

$connection= mysqli_connect($db_host,$db_username,$db_password,$db_name);

if(!$connection){
    die('connection failed');
}
echo  'connection sucss';


$val1= $_GET['temperature'];
$val2= $_GET['humidity'];
mysqli_query($connection , "INSERT  into `sensor`(`temperature`,`humidity`) values ($val1,$val2);");



?>