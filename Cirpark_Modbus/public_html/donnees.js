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

