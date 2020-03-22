/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "projet.h"

personne liste_personnes[5]; //Liste des personnes
int nbPersonnes;
outil outils[5]; //Liste des outils
int nbOutils;
poste postes[5]; //Liste des postes
int nbPostes;
location locations[5]; //Locations d'outils
int nbLocations;
reservation reservations[5]; //Reservations de postes
int nbReservations;
paiement paiements[5]; //Liste des paiements
int nbPaiements;



int *
init_1_svc(void *argp, struct svc_req *rqstp)
{
	printf("Serveur : \n");
	static int  result;

	//Initialisations des nb tableaux à 0
	nbPersonnes = 0;
	nbOutils = 0;
	nbPostes = 0;
	nbLocations = 0;
	nbReservations = 0;
	nbPaiements = 0;


	//Ajout de personnes
	personne personne_1;
	personne_1.id = nbPersonnes;
	strcpy(personne_1.prenom,"Philippe");
	strcpy(personne_1.nom,"Hamon");
	personne_1.adherent = 0;
	liste_personnes[nbPersonnes] = personne_1;
	nbPersonnes++;


	//Ajout des outils
	outil outil_1 = {id:nbOutils, nom:"Marteau",anomalie:0};
	outils[nbOutils] = outil_1;
	nbOutils++;

	outil outil_2 = {id:nbOutils, nom:"Tournevis",anomalie:0};
	outils[nbOutils] = outil_2;
	nbOutils++;

	//Ajout de postes de travail
	poste poste_1;
	poste_1.id = nbPostes;
	strcpy(poste_1.nom,"Poste 1");
	strcpy(poste_1.description,"3m x 2m");
	postes[nbPostes] = poste_1;
	nbPostes++;

	poste poste_2;
	poste_2.id = nbPostes;
	strcpy(poste_2.nom,"Poste 2");
	strcpy(poste_2.description,"9m x 4m");
	postes[nbPostes] = poste_2;
	nbPostes++;

	//Ajout de methodes de paiements
	paiement paiement_1 = {id:nbPaiements,nom:"Paypal"}; //Paypal
	paiements[nbPaiements] = paiement_1;
	nbPaiements++;

	paiement paiement_2 = {id:nbPaiements,nom:"CB"}; //Carte Bancaire
	paiements[nbPaiements] = paiement_2;
	nbPaiements++;

	//Ajout d'une location (tournevis)
	location location_1;
	location_1.id = nbLocations;
	location_1.id_outil = 1;
	location_1.id_personne = 0;
	location_1.payer = 1;
	location_1.retourner = 0;
	locations[nbLocations] = location_1;
	nbLocations++;

	result = 1;
	printf("- Init \n");
	return &result;
}

int *
enregistrer_adherent_1_svc(personne *argp, struct svc_req *rqstp)
{
	static int  result;

	argp->id = nbPersonnes;
	liste_personnes[argp->id] = *argp;
	nbPersonnes++;
	result = argp->id;
	printf("- Enregistrement d'un adhérent (%s %s)\n",argp->prenom,argp->nom);
	return &result;
}

int *
renouveler_adhesion_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;

	liste_personnes[*argp].adherent = 1;

	result = 1;
	printf("- Renouvellement  (%s %s)\n",liste_personnes[*argp].prenom,liste_personnes[*argp].nom);
	return &result;
}

tab_outils *
lister_outils_1_svc(int *argp, struct svc_req *rqstp)
{
	static tab_outils result;
	result.nbOutils = 0;

	//Seulement outils disponibles
	if(*argp == 1) {
		for (int i = 0; i < nbOutils; i++)
		{
			int outil_deja_loue = 0;
			for(int y = 0;y<nbLocations;y++){
				if(locations[y].id_outil == i && locations[y].retourner == 0){
					//Ne pas ajouter à la liste car déjà louer
					outil_deja_loue = 1;
				}
			}
			if(!outil_deja_loue && !outils[i].anomalie){
				result.listeOutils[i] = outils[i];
				result.nbOutils++;
			}
		}
		printf("- Envoi liste outils seulement dispo(%d outils)\n",result.nbOutils);
	}
	//Ou tous les outils
	else{
		for (int i = 0; i < nbPostes; i++)
		{
			result.listeOutils[i] = outils[i];
			result.nbOutils++;
		}
		printf("- Envoi liste outils(%d outils)\n",result.nbOutils);
	}
	return &result;
}

tab_postes *
lister_postes_1_svc(void *argp, struct svc_req *rqstp)
{
	static tab_postes  result;
	result.nbPostes = 0;

	for (int i = 0; i < nbPostes; i++)
	{
		result.listePostes[i] = postes[i];
		result.nbPostes++;

	}

	printf("- Envoi liste postes(%d outil)\n",result.nbPostes);
	return &result;
}

int *
louer_outil_1_svc(param_outil *argp, struct svc_req *rqstp)
{
	static int  result;

	//Creation de la location
	location la_location;
    la_location.id = nbLocations;
	la_location.id_personne = argp->id_adherent;
	la_location.id_outil = argp->id_outil;
	la_location.retourner = 0;
	la_location.payer = 0;

	locations[nbLocations] = la_location;

	result = la_location.id;
	nbLocations++;
	printf("- Location d'un outil (%s)\n",outils[argp->id_outil].nom);
	return &result;
}

int *
reserver_poste_1_svc(param_poste *argp, struct svc_req *rqstp)
{
	static int  result = -1;
	if(liste_personnes[argp->id_adherent].adherent == 0)return &result; //Si la personne n'est pas adhérent
	if(argp->date.jourSemaine == 'd')return &result; //Reservation impossible le dimanche
	if(argp->date.jourSemaine == 's' && (argp->date.heure < 14 || argp->date.heure > 18))return &result;; //Reservation impossible le dimanche
	if(argp->date.heure < 12 || ((argp->date.heure > 14 && argp->date.heure < 17))|| argp->date.heure > 19)return &result; //Reservation impossible heure incorrect
	//Creation de la reservation
	reservation la_reservation;
	la_reservation.id = nbReservations;
	la_reservation.id_personne = argp->id_adherent;
	la_reservation.id_poste = argp->id_poste;
	la_reservation.date = argp->date;
	la_reservation.duree = argp->duree;
	reservations[nbReservations] = la_reservation;
	nbReservations++;

	result = la_reservation.id;
	printf("- Location d'un poste (%s)\n",postes[argp->id_poste].nom);
	return &result;
}

informations *
tarifs_horaires_1_svc(void *argp, struct svc_req *rqstp)
{
	static informations infos;
	strcpy(infos.tarifs,"10€ pour 1h, 30€ pour 4h, et 50€ pour 8h");
	strcpy(infos.horaires,"les jours de la semaine 12h à 14h ou 17h à 19h");
	printf("- Envoi des tarifs ou horaires\n");
	return &infos;
}

tab_paiements *
afficher_mode_paiement_1_svc(void *argp, struct svc_req *rqstp)
{
	static tab_paiements  result;

	result.nbPaiements = 0;
	for (int i = 0; i < nbPaiements; i++)
	{
		result.listePaiements[i] = paiements[i];
		result.nbPaiements++;
	}
	printf("- Envoi des modes de paiements (%d disponibles)\n",result.nbPaiements);
	return &result;
}

int *
effectuer_paiement_1_svc(param_paiement *argp, struct svc_req *rqstp)
{
	static int  result;

	locations[argp->id_location].payer = 1;
	result = 1;
	printf("- Effectuer paiements\n");
	return &result;
}

int *
retour_location_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;

	for (int i = 0; i < nbLocations; i++)
	{
		if(locations[i].id_outil == *argp){
			locations[i].retourner == 1;
		}
	}
	printf("- Retourner location\n");
	return &result;
}

int *
signaler_anomalie_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;

	outils[*argp].anomalie = 1;
	result = 1;
	printf("- Signalement d'une anomalie sur l'outil (%s)\n",outils[*argp].nom);
	return &result;
}


int *
corriger_anomalie_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;

	outils[*argp].anomalie = 0;
	result = 1;
	printf("- Correction d'une anomalie sur l'outil\n");
	return &result;
}