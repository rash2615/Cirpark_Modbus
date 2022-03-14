<?php

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="InterfaceWeb/Siteweb/style.css">
	<link rel="stylesheet" type="text/html" href="InterfaceWeb/Siteweb/inscription.html">
	<link rel="stylesheet" type="text/html" href="InterfaceWeb/Siteweb/connexion.html">
	<link rel="stylesheet" type="text/html" href="InterfaceWeb/Siteweb/n1.html">
	<link rel="stylesheet" type="text/html" href="InterfaceWeb/Siteweb/n2.html">
	<link rel="stylesheet" type="text/html" href="InterfaceWeb/Siteweb/n3.html">
	<title>CirPark</title>
</head>
<header>
		<h1 id="titre">Centre Commercial</h1> 
	</header>
	<nav class="nav li" id="ma_nav"> 
		<ul>
			<li><a class="blanc" href="index.html">Accueil</a></li>

			<li class="deroulant">
				<a id="parking">Parking</a>
				<ul class="sous">
        			<li><a id="n1" class="blanc" href="n1.html">Niveau 1</a></li>
        			<hr>
        			<li><a id="n2" class="blanc" href="n2.html">Niveau 2</a></li>
        			<hr>
        			<li><a id="n3" class="blanc" href="n3.html">Niveau 3</a></li>
        		</ul>
        	</li>
			<li id="nav_inscript" ><a class="blanc" href="inscription.html">Inscription</a></li> 
			<li id="nav_co"><a class="blanc" href="connexion.html">Connexion</a></li>
		</ul>
	</nav>
<body class="fond-ecran">
	
	<table class="center">
		<h1 class="cadre center"> Place disponible </h1> <br/>
		<tr class="police">
			<th class="cadre">Niveau 1</th>
			<th class="cadre">Niveau 2</th>
			<th class="cadre">Niveau 3</th>
		</tr>
		<tr class="police">
			<td class="cadre"> 50 </td>
			<td class="cadre"> 50 </td>
			<td class="cadre"> 50 </td>
		</tr>
	</table>
		<br>
		<hr>
	<table>
		<h1 class="cadre"> Tarifs Parking </h1> <br/>
		<tr class="police">
			<th class="cadre">Durée</th>
			<th class="cadre">Prix</th>
		</tr>
		<tr class="police">
			<td class="cadre">30min</td>
			<td class="cadre">1€</td>
		</tr>	
		<tr class="police">
			<td class="cadre">2h</td>
			<td class="cadre">2€</td>
		</tr>
		<tr class="police">
			<td class="cadre">3h</td>
			<td class="cadre">5€</td>
		</tr>
	</table>
		<br>
		<hr>
	<table>
		<h1 class="cadre"> Horaire Parking </h1> <br/>
		<tr class="police">
			<th class="cadre">Jour</th>
			<th class="cadre">Heure</th>
		</tr>
		<tr class="police">
			<td class="cadre">Lundi - Vendredi</td>
			<td class="cadre">9h - 21h</td>
		</tr>	
		<tr class="police">
			<td class="cadre">Samedi</td>
			<td class="cadre">9h - 23h</td>
		</tr>
		<tr class="police">
			<td class="cadre">Dimanche</td>
			<td class="cadre">10h - 18h</td>
		</tr>
	</table>

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
</body>
</html>

?>
