<?php
/****** Connexion au serveur de BdD *******/
function ConnectDB() {
	$ini=parse_ini_file('./app.ini');
	$id = new PDO("mysql:host=".$ini['host'].";dbname=".$ini['database'].";charset=utf8", $ini['user'], $ini['password']);
	$id->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	return $id;
}

function exectuterRequete($id,$req,$tableauDeDonnees){
	$res=preparerRequete($id,$req);
	$res=exectuterRequetePrepare($res,$tableauDeDonnees);
	//print_r(extraireDonneesRequetePrepare($res));
	return extraireDonneesRequetePrepare($res);

}

function preparerRequete($id,$req){
	$res=$id->prepare($req, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
	return $res;
}

function exectuterRequetePrepare($res,$tableauDeDonnees){
	$res->execute($tableauDeDonnees);
  return $res;
}

function extraireDonneesRequetePrepare($res){
	  return $res->fetchAll(PDO::FETCH_ASSOC);
}

function recupererLeDernierIdInserer($id){
	  return $id->lastInsertId();
}

function fermerCursor($res){
	$res->closeCursor();
}

function handle_sql_errors($query, $error_message)
{
    echo '<pre>';
    echo $query;
    echo '</pre>';
    echo $error_message;
    die;
}


?>
