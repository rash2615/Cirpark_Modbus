<?php 
include_once('model.php');

$listeMenuGraphe = array('pitch','roll','yaw','vgx','vgy','vgz','templ','temph','tof','h','bat','baro','time','agx','agy','agz');
$historique = $_GET['historique'];

if (isset($_GET['AfficherGraphe'])){
    $donnees = "historique/".$;
    foreach ($_GET['historique'] as $c=>$v) {
        $donnees .= "/".$v;
    }
    echo $donnees;

$option=array(CURLOPT_HTTPGET=>true);
$reponseAPIJson=executerRequeteCurl($donnees,$option);
$reponseAPITab=json_decode($reponseAPIJson,true);
}	
?>