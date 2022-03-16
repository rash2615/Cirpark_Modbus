var IP="";
var PORT="";
var xmlDoc;

// Pour CHROME
function Lirexml()
    {
		if(navigator.userAgent.indexOf('Fiefox')){
			xmlDoc= document.implementation.createDocument("", "", null);
			xmlDoc.async=false;
			xmlDoc.load("./xml/reponse.xml");
		}else{       
			xmlHttp = new window.XMLHttpRequest();
			xmlHttp.open("GET","./xml/reponse.xml",false);
			xmlHttp.send(null);
			xmlDoc = xmlHttp.responseXML.documentElement;
		}
    }

// Requête HTTP JS vers un fichier php qui va lire les données 
function RechercherMateriel(){
	var xhr_object_connecte = null; 
	if(window.XMLHttpRequest)
		xhr_object_connecte = new XMLHttpRequest(); 
	else { 
		 alert("Votre navigateur ne supporte pas les objets XMLHTTPRequest..."); 
		 return; 
	} 
	
	var req = "HTTPCirPark.php?xml=devices.xml";	
	
	xhr_object_connecte.open("POST", req, true);
	xhr_object_connecte.onreadystatechange = function() { 
	 if(xhr_object_connecte.readyState == 4) 
		chercherInfoMateriel();
	} 

	xhr_object_connecte.send();
}
function ChercherInfoMateriel(){
    readxml();          
	var allTag=xmlDoc.getElementsByTagName("id");
	if(allTag.length>0){
		for (i = 0; i < allTag.length; i++){
			text=allTag[i].textContent;
			alert(text);
		}	
	}
}