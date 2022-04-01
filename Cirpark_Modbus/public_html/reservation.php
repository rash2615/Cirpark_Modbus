<?php

$jours = array(1=>"Lu",2=>"Ma",3=>"Me",4=>"Je",5=>"Ve",6=>"Sa",0=>"Di");
if(isset($_GET['annee']) AND preg_match("#^[0-9]{4}$#",$_GET['annee'])){    //si on souhaite afficher une autre année, on l'affiche si elle est correcte
    $annee=$_GET['annee'];
} else {
    $annee=date("Y");   //si non, on affiche l'année actuelle
}
$NbrDeJour=[];
for($mois=1;$mois<=12;$mois++) {
    $NbrDeJour[$mois]=date("t",mktime(1,1,1,$mois,2,$annee));
    $PremierJourDuMois[$mois]=date("w",mktime(5,1,1,$mois,1,$annee));
}
?>