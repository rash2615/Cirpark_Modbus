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

ini_set('display_errors', 1);   
ini_set('display_startup_errors', 1);   
error_reporting(E_ALL);   

	include_once('model.php');
	$id = ConnectDB();

	$req_type = $_SERVER['REQUEST_METHOD'];
	$req_path = $_SERVER['PATH_INFO'];

	$req_data = explode('/',$req_path);

	$header = apache_request_headers();

/////////////////////////// Requete HTTP : GET //////////////////////////////////
if($req_type==='GET'){
	if($req_data['1']=="place"){ 
		if(isset($req_data['2'])){
		//	Recupere l'etat des places d'un niveau

			$reqEtatplace = "SELECT etat,numero_place FROM capteur inner join place on capteur.id_capteur=place.id_capteur 
								inner join niveau on niveau.id_niveau=place.id_niveau where niveau.niveau=? ";
			$resEtatplace = exectuterRequete($id,$reqEtatplace,array($req_data['2']));
			
			$reponseAPI = $resEtatplace;
		}
		else{
			$reqEtatplace = "SELECT etat,numero_place FROM capteur inner join place on capteur.id_capteur=place.id_capteur";
			$resEtatplace = exectuterRequete($id,$reqEtatplace,array());
			
			$reponseAPI = $resEtatplace;
		}
	}/*
	if($req_data['1']=="capteur"{ 
		// Lecture des capteur par emplacement
		$reqEmplacement = "SELECT modele, id_place, id_capteur FROM capteur";
		$resEmplacement = exectuterRequete($id,$reqEmplacement,array());

		$reponseAPI['emplacement'] = $resEmplacement[0]['emplacement'];
	}
	if($req_data['1']=="utilisateur"){
		// Lecture de l'historique des utilisateurs  
		$reqNButilisateur = "SELECT * FROM utilisateur"; 
		$resNButilisateur = exectuterRequete($id,$reqNButilisateur,array());
		
		$reponseAPI['nbutilisateur'] = $resNButilisateur[0]['nbutilisateur'];
	}
	if($req_data['1']=="emplacement"){	
		// Lecture des capteur par niveau pour affichage des place total dispo 
		$reqNBplace = "SELECT count(id_place), id_capteur, niveau FROM capteur";
		$resNBplace = exectuterRequete($id,$reqNBplace,array());
		 			  
		$reponseAPI['nbplace'] = $resNBplace[0]['nbplace'];
	}	*/		
	echo(json_encode($reponseAPI));	 	
}
	
/////////////////////////// Requete HTTP : POST ////////////////////////////////
if($req_type==='POST'){
	if($req_data['1']=='vol'){
		
	}
}

?>