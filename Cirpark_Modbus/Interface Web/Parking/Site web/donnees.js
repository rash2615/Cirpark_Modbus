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