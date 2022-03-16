<?php
	
// Accès depuis n'importe quel site ou appareil (*)
header("Access-Control-Allow-Origin: *");
// Format des données envoyées
header("Content-Type: application/json; charset=UTF-8");
// Méthode autorisée
header("Access-Control-Allow-Methods: GET");
// Durée de vie de la requête
header("Access-Control-Max-Age: 3600");
// Entêtes autorisées
header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

	include_once('model.php');
	$id = ConnectDB();

	$req_type = $_SERVER['REQUEST_METHOD'];
	$req_path = $_SERVER['PATH_INFO'];

	$req_data = explode('/',$req_path);

	$header = apache_request_headers();

/////////////////////////// Requête HTTP : GET //////////////////////////////////

if($req_type==='GET'){
	if($req_data['1']=='drone'&&empty($req_data['2'])){
		$req
	}




}


/////////////////////////// Requête HTTP : POST ////////////////////////////////
if($req_type==='POST'){
	if($req_data['1']=='vol'){
	}
}

?>