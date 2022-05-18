

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="./style.css">
	<link rel="stylesheet" type="text/html" href="./inscription.html">
	<link rel="stylesheet" type="text/html" href="./connexion.html">
	<link rel="stylesheet" type="text/html" href="./n1.html">
	<link rel="stylesheet" type="text/html" href="./n2.html">
	<link rel="stylesheet" type="text/html" href="./n3.html">
	<title>CirPark</title>
</head>
<body class="fond-ecran">
	<header>
			<h1 id="titre">Centre Commercial</h1> 
		<nav class="nav li" id="ma_nav"> 
			<ul>
				<li><a class="blanc" id="accueil">Accueil</a></li>
				<li class="deroulant">
					<a id="parking">Parking</a>
					<ul class="sous">
						<li><a id="n1" class="blanc" id="n1">Niveau 1</a></li>
						<hr>
						<li><a id="n2" class="blanc" id="n2">Niveau 2</a></li>
						<hr>
						<li><a id="n3" class="blanc" id="n3">Niveau 3</a></li>
					</ul>
				</li>
				<li><a class="blanc" id="inscription">Inscription</a></li> 
				<li><a class="blanc" id="connexion">Connexion</a></li>
			</ul>
		</nav>
	</header>
<?php
	if (isset($_GET['créationreussi'])){
	echo "Votre compte a bien été crée monsieur ".$_COOKIE['NomReg']." ".$_COOKIE['PrenomReg'];
}

	if (isset($_GET['connexionreussi'])){
	echo "Bienvenue sur votre compte monsieur ".$_COOKIE['Nom']." ".$_COOKIE['Prenom'];
}
	if (isset($_GET['existemail'])){
	echo "Mince! il semblerais que cet email est déja associer a un compte";
}




?>
	<div id="section">
	<?php 
		include_once('accueil.html');
	?>
	</div>
	<div class="fleche">
		<a href="#" id="back-to-top-sticky" class="back-to-top-sticky d-block text-white text-center pb-4" title="Back to top">
			<span><img style="width: 5%;" src="Image/fleche.png"></span><br>
		</a>
	</div>
	<footer>
		<br>
		<div>All Right Reserved to Aakash/Rashmi/Yoan/Dilshan - 2022 ©</div>
	</footer>
	<script type="text/javascript" src="donnees.js"></script>
	<script type="text/javascript" src="ajax.js"></script>
</body>
</html>


