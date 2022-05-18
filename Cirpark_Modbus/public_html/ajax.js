var reponseHTTP;
function chargerPlaces(url) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState == 4 && this.status == 200) {
        reponseHTTP=this.responseText;
        modifierEtatPlaces();
      }
    };
    xhttp.open("GET", url, true);
    xhttp.send();
}

function modifierEtatPlaces(){
    console.log(reponseHTTP);
    document.getElementById('A3').style.backgroundColor='red';
    document.getElementById('A1').style.backgroundColor='red';
    document.getElementById('B2').style.backgroundColor='red';
}

// Gestion du clic sur le bouton accueil
let accueil = document.getElementById("accueil");
accueil.addEventListener("click", afficherAccueil);
function afficherAccueil(){
  var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState == 4 && this.status == 200) {
        reponseHTTP=this.responseText;
        //console.log(reponseHTTP);
        document.getElementById("section").innerHTML = reponseHTTP;
      }
    };
    xhttp.open("GET", "accueil.html", true);
    xhttp.send();
}

// Gestion du clic sur le bouton n1
let n1 = document.getElementById("n1");
n1.addEventListener("click", afficherN1);
function afficherN1(){
  var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState == 4 && this.status == 200) {
        reponseHTTP=this.responseText;
        //console.log(reponseHTTP);
        document.getElementById("section").innerHTML = reponseHTTP;
      }
    };
    xhttp.open("GET", "n1.html", true);
    xhttp.send();
}
// Gestion du clic sur le bouton n2
let n2 = document.getElementById("n2");
n2.addEventListener("click", afficherN2);
function afficherN2(){
  var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState == 4 && this.status == 200) {
        reponseHTTP=this.responseText;
        //console.log(reponseHTTP);
        document.getElementById("section").innerHTML = reponseHTTP;
      }
    };
    xhttp.open("GET", "n2.html", true);
    xhttp.send();
}

// Gestion du clic sur le bouton n3
let n3 = document.getElementById("n3");
n3.addEventListener("click", afficherN3);
function afficherN3(){
  var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState == 4 && this.status == 200) {
        reponseHTTP=this.responseText;
        //console.log(reponseHTTP);
        document.getElementById("section").innerHTML = reponseHTTP;
      }
    };
    xhttp.open("GET", "n3.html", true);
    xhttp.send();
}

// Gestion du clic sur le bouton connexion
let connexion = document.getElementById("connexion");
connexion.addEventListener("click", afficherConnexion);
function afficherConnexion(){
  var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState == 4 && this.status == 200) {
        reponseHTTP=this.responseText;
        //console.log(reponseHTTP);
        document.getElementById("section").innerHTML = reponseHTTP;
      }
    };
    xhttp.open("GET", "connexion.html", true);
    xhttp.send();
}

// Gestion du clic sur le bouton connexion
/*let oublieco = document.getElementById("oublieco");
oublieco.addEventListener("click", afficherOublieco);
function afficherOublieco(){
  var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState == 4 && this.status == 200) {
        reponseHTTP=this.responseText;
        //console.log(reponseHTTP);
        document.getElementById("section").innerHTML = reponseHTTP;
      }
    };
    xhttp.open("GET", "oublieco.html", true);
    xhttp.send();
}*/

// Gestion du clic sur le bouton inscription
let inscription = document.getElementById("inscription");
inscription.addEventListener("click", afficherInscription);
function afficherInscription(){
  var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState == 4 && this.status == 200) {
        reponseHTTP=this.responseText;
        //console.log(reponseHTTP);
        document.getElementById("section").innerHTML = reponseHTTP;
      }
    };
    xhttp.open("GET", "inscription.html", true);
    xhttp.send();
}