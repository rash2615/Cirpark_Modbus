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
ini_set("allow_url_fopen", true);

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
			$reqEtatcapteur = "SELECT etat,numero_place FROM capteur inner join place on capteur.id_capteur=place.id_capteur 
								inner join niveau on niveau.id_niveau=place.id_niveau where niveau.niveau=?";
			$resEtatcapteur = exectuterRequete($id,$reqEtatcapteur,array($req_data['2']));
			
			$reponseAPI = $resEtatcapteur;
		}
		else{
			$reqEtatcapteur = "SELECT etat,numero_place FROM capteur inner join place on capteur.id_capteur=place.id_capteur";
			$resEtatcapteur = exectuterRequete($id,$reqEtatcapteur,array());
			
			$reponseAPI = $resEtatcapteur;
		}
	}
	if($req_data['1']=="utilisateur"){
		// Recupere des donnees de utilisateurs  
		$reqNButilisateur = "SELECT * FROM utilisateur"; 
		$resNButilisateur = exectuterRequete($id,$reqNButilisateur,array());
		
		$reponseAPI = $resNButilisateur;
	}
	if($req_data['1']=="historique"){
		// Recupere de l'historique de l'utilisateur  
		$reqHistorique = "SELECT * FROM historique WHERE id_utilisateur=?"; 
		$resHistorique = exectuterRequete($id,$reqHistorique,array());
		
		$reponseAPI = $resHistorique;
	}/*
	if($req_data['1']=="capteur"){ 
		// Recupere des capteur par emplacement
		$reqCapteur = "SELECT nom_capteur, id_place, id_capteur FROM capteur";
		$resCapteur = exectuterRequete($id,$reqEmplacement,array());

		$reponseAPI= $resEmplacement;
	}
	if($req_data['1']=="emplacement"){	
		// Recupere des capteur par niveau pour affichage des place total dispo 
		$reqNBplace = "SELECT count(id_place), id_capteur, niveau FROM capteur";
		$resNBplace = exectuterRequete($id,$reqNBplace,array());
		 			  
		$reponseAPI = $resNBplace;
	}	*/		
	echo(json_encode($reponseAPI));	 	
}
	
/////////////////////////// Requete HTTP : POST ////////////////////////////////
if($req_type==='POST'){
	/*if($req_data['1']=="reservation"){
		// Insertion des reservations
		$reqReservation = "INSERT * FROM reservation WHERE id_utilisateur=?"; 
		$resReservation = exectuterRequete($id,$reqReservation,array());

		$reponseAPI = $resHistorique;
	}	*/
	if($req_data['1']=="connexion"){
    	$data = json_decode(file_get_contents('php://input'), true);
    	$reqConnexion = "SELECT * FROM utilisateur WHERE mail=? AND mdp=?";
	// Gestion du formulaire de connexion
		$resConnexion = exectuterRequete($id, $reqConnexion, array());
		$tableauDeDonnees=array($data["login"],$data["mdp"]);
		$resConnexion->execute($tableauDeDonnees);
		$reponseAPI = $resConnexion->fetchAll(PDO::FETCH_ASSOC);
 		print_r($reponseAPI);
  		if(empty($reponseAPI) == false) {echo '{"login":"ok"}';}
 		else {echo '{"login":"bad"}';}
	}	
	else{
    echo "Les donnees ont été envoyé en GET ???";
	}
	echo(json_encode($reponseAPI));
}


?>