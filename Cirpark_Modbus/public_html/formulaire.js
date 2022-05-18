
                // Gestion du clic sur le bouton submit
                let btn_submit = document.getElementById("submit");
               

                function EnvoiFormulaireConnexion()
                {
                    //console.debug("CLICk !!!");
                    // Récupérer les données saisies dans le formulaire et les mettre au format JSON
                    let in_login = document.getElementById("login");
                    let in_mdp = document.getElementById("mdp");
                    let json = '{"login":"' + in_login.value + '", "mdp":"' + in_mdp.value + '"}';
                    console.debug(json);

                    // Envoyer ces données au serveur
                    function resultatConnexion () {
                        const reponse = JSON.parse(this.responseText);
                        console.log(reponse.login);
                        let p_resultat = document.getElementById("resultat");
                        if(reponse.login == "ok")
                        {
                            p_resultat.innerHTML="Connexion réussie";
                        }
                        else if(reponse.login == "bad")
                        {
                            p_resultat.innerHTML="Connexion échouée";
                        }
                    }

                    let req_ajax = new XMLHttpRequest();
                    req_ajax.onload = resultatConnexion;
                    req_ajax.open("post", "formulaire.php", true);
                    req_ajax.setRequestHeader("Content-type", "application/json;charset=UTF-8");
                    req_ajax.send(json);

                }
				btn_submit.addEventListener("click", EnvoiFormulaireConnexion);
                // Réception de la réponse du serveur

