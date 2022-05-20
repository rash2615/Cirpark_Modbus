<?php	
$mysqli = mysqli_connect("172.20.21.221","cirpark","Modbus2022","cirpark_modbus");
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
	if (isset($_SERVER['PATH_INFO'])) {
	
	$req_path = $_SERVER['PATH_INFO'];

	$req_data = explode('/',$req_path);
}
	$header = apache_request_headers();

/////////////////////////// Requete HTTP : GET //////////////////////////////////
if($req_type === 'GET'){
	if (isset($_SERVER['PATH_INFO'])) {
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
	}
	if($req_data['1']=="playlists"){
		// Recupere de la playlist de Yoan
		//$reqHistorique = "SELECT liste FROM playlist WHERE";  
	}
	echo(json_encode($reponseAPI));	 	
	}
}	

/////////////////////////// Requete HTTP : POST ////////////////////////////////
if($req_type === 'POST'){

	if (isset($_POST['connexion'])) {
		$data = json_decode(file_get_contents('php://input'), true);
		$email= $_POST["adressmail_utilisateur"];
		$mdp= $_POST["mdp_utilisateur"];
    	
    	$reqConnexion = "SELECT * FROM utilisateur WHERE mail='$email' AND mdp='$mdp'";
   	 	$resultat = $mysqli->query($reqConnexion);
    	$row = $resultat->fetch_assoc();

    	if ($row != null) {
			header("Location: index.php?connexionreussi");
			setcookie("Nom",$row["nom"]);
			setcookie("Prenom",$row["prenom"]);
			}
		else {
			echo "Oups une erreur est survenue lors de votre connexion";
		}
	}

    if (isset($_POST['inscription'])) {
		$data = json_decode(file_get_contents('php://input'), true);
		$nom= $_POST["nom_utilisateur"];
		$prenom= $_POST["prenom_utilisateur"];
		$email= $_POST["adressmail_utilisateur"];
		$mdp1= $_POST["mdp1"];
		$mdp2= $_POST["mdp2"];

		$reqConnexion = "SELECT * FROM utilisateur WHERE mail='$email'";
		$resultat = $mysqli->query($reqConnexion);
		$row = $resultat->fetch_assoc();

		if ($mdp1 != $mdp2) {
			echo "Oups il semblerais que les mots de passe ne sont pas identique";
		} else if ($row != null) {
			header("Location: index.php?existemail");
			} 
			else {

		$reqInscription = "INSERT INTO utilisateur (role,nom,prenom,mail,mdp) VALUES ('client','$nom','$prenom','$email','$mdp1')";
		$resultat = $mysqli->query($reqInscription);

		if ($resultat != null) {
			header("Location: index.php?créationreussi");
			setcookie("NomReg",$nom);
			setcookie("PrenomReg",$prenom);
			}
		else {
			echo "Oups une erreur est survenue lors de le création de votre compte";
		}
		}	
    }
}

?>