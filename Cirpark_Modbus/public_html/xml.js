var IP="172.20.21.221";
// var PORT="2357";
var xmlDoc;

// Pour CHROME
function readxml(){
	if(navigator.userAgent.indexOf('Fiefox')){
		xmlDoc= document.implementation.createDocument("", "", null);
		xmlDoc.async=false;
		xmlDoc.load("rest.php/place");
	}else{       
		xmlHttp = new window.XMLHttpRequest();
		xmlHttp.open("GET","rest.php/place",false);
		xmlHttp.send(null);
		xmlDoc = xmlHttp.responseXML.documentElement;
	}
}

// Requête HTTP JS vers un fichier php qui va lire les données 
/*function rechercherMateriel(){
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
function chercherInfoMateriel(){
    readxml();          
	var allTag=xmlDoc.getElementsByTagName("id");
	if(allTag.length>0){
		for (i = 0; i < allTag.length; i++){
			text=allTag[i].textContent;
			alert(text);
		}	
	}
}
*/