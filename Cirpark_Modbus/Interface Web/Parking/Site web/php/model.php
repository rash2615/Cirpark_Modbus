<?php
/****** Connexion au serveur de BdD *******/
function ConnectDB() {
	$ini=parse_ini_file('../app.ini');
	$id = new PDO("mysql:host=".$ini['172.20.21.221'].";dbname=".$ini['cirpark_modbus'].";charset=utf8", $ini['cirpark'], $ini['Modbus2022']);
	$id->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	return $id;
}

?>