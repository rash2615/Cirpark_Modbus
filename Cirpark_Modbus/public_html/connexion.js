// Gestion du clic sur le bouton submit
let btn_submit = document.getElementById("submit");
btn_submit.addEventListener("click", EnvoiFormulaireConnexion);

function EnvoiFormulaireConnexion()
{
    //console.debug("CLICk !!!");
    // RÃ©cupÃ©rer les donnÃ©es saisies dans le formulaire et les mettre au format JSON
    let in_login = document.getElementById("adressmail");
    let in_mdp = document.getElementById("mdp");
    let json = '{"mail":"' + in_login.value + '", "mdp":"' + in_mdp.value + '"}';
    console.debug(json);

    var xhttp = new XMLHttpRequest();
    
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        console.log(this.responseText);
        }
    };
    xhttp.open("post", "rest.php/connexion", true);
    xhttp.setRequestHeader("Content-type", "application/json;charset=UTF-8");
    xhttp.send(json);

}

// RÃ©ception de la rÃ©ponse du serveur
