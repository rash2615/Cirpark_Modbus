var reponseHTTP;
function chargerPlaces(url) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this .readyState ==4 && this.status == 200) {
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
}