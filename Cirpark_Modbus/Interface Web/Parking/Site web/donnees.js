function ChangerTitre() {
	var h1 = document.getElementById("titre");
	if (h1.innerHTML == "Centre Commercial") {
		h1.innerHTML = "Parking en temps réel";
		setTimeout(ChangerTitre, 1000);
	}
	else if (h1.innerHTML == "Parking en temps réel") {
		h1.innerHTML = "Centre Commercial";	
	}
}
titre.addEventListener('mouseover', ChangerTitre);

function ChangerSection() {
	var parking = document.getElementById("ChangerSection");
	var n1 = document.getElementById("n1");
	var n2 = document.getElementById("n2");
	var n3 = document.getElementById("n3");
	if(this.id == "n1") {
			n1.style.display = "block";
			n2.style.display = "none";
			n3.style.display = "none";
		}
	if(this.id == "n2") {
			n1.style.display = "none";
			n2.style.display = "block";
			n3.style.display = "none";
		}
	if(this.id == "n3") {
			n1.style.display = "none";
			n2.style.display = "none";
			n3.style.display = "block";
		}
}
n1.addEventListener('onclick', ChangerSection);
n2.addEventListener('onclick', ChangerSection);
n3.addEventListener('onclick', ChangerSection);

function VerifierFormulaireInscription () {	
	var mdp1 = document.getElementById("mdp1").value;
	var mdp2 = document.getElementById("mdp2").value;
	var envoyer = document.getElementById("envoyer").value;
	if (mdp1 != mdp2) {
		alert ("Mot de passe différent !");	
		event.preventDefault();
	}
	else {}
}

envoyer.addEventListener('onclick', VerifierFormulaireInscription);

	
function VerifierMotdePasse() {
	var mdp_longueur = document.getElementById("mdp_longueur");
	var mdp_maj = document.getElementById("mdp_maj");
	var mdp_min = document.getElementById("mdp_min");
	var mdp_chiffre = document.getElementById("mdp_chiffre");
	if (mdp1.length < 7) {
		mdp_longueur.style.color = "red";
		event.preventDefault();
	}
	else {
		mdp_longueur.style.color = "vert";
	}
}
