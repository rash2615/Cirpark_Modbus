<?php

function executerRequeteCurl($donnees,$option){
  $ini=parse_ini_file('./app.ini');

  $url="http://".$ini['host']."/~cirparkm/CirparkModbus/SiteWeb/PHP/rest.php/";
  $url.=$donnees;
  $curl = curl_init();

  curl_setopt($curl, CURLOPT_URL,$url );
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($curl, CURLOPT_HTTPHEADER, array('Accept: application/js'));

  curl_setopt_array($curl,$option);

  $reponseAPIJson=curl_exec($curl);
  curl_close ($curl);
  return $reponseAPIJson;
}

?>