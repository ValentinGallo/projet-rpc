/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "projet.h"


void
projet_1(char *host)
{
	CLIENT *clnt;
	int  *resultat;
	void *vide;
	tab_outils *outils;
	tab_paiements *paiements;
	personne adherent;

#ifndef	DEBUG
	clnt = clnt_create (host, PROJET, GEOM_VERSION_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	printf("CLIENT : \n");
	resultat = init_1(vide,clnt);

	//INIT
	if (resultat == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else printf("Initialisation réussie(code : %d) \n",*resultat);

	//Enregistrer adhérent
	adherent.id = 0;
	strcpy(adherent.prenom,"Jean");
	strcpy(adherent.nom,"Dupont");
	adherent.adherent = 1;
	resultat = enregistrer_adherent_1(&adherent, clnt);
	if (resultat == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else printf("Enregistrement réussie(code : %d) \n",*resultat);

	//Liste outils
	date debut = {heure:0,jour:1,mois:1,annee:2020};
	date fin = {heure:24,jour:1,mois:1,annee:2020};
	param_date dates = {date_debut:debut, date_fin:fin};
	outils = lister_outils_1(&dates, clnt);
	if (outils == (tab_outils *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("////////////////////// Liste outils(%d dispo) ////////////////////// \n",outils->nbOutils);
	for(int i = 0;i<outils->nbOutils;i++){
		printf("- Outil n°%d : %s(id : %d)\n",i+1,outils->listeOutils[i].nom,outils->listeOutils[i].id);
	}
	printf("/////////////////////////////////////////////////////////////////// \n");

	//Louer un outil
	param_outil info_location;
	info_location.date_debut = debut;
	info_location.date_fin = fin;
	info_location.id_adherent = adherent.id;
	info_location.id_outil = 0; //Marteau
	resultat = louer_outil_1(&info_location, clnt);
	if (resultat == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else printf("Location réussie(%s)\n",outils->listeOutils[info_location.id_outil].nom);

	//Liste paiements
	paiements = afficher_mode_paiement_1(&vide, clnt);
	if (paiements == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("////////////////////// Liste Paiements(%d dispo) ////////////////////// \n",paiements->nbPaiements);
	for(int i = 0;i<paiements->nbPaiements;i++){
		printf("- Paiement n°%d : %s(id : %d)\n",i+1,paiements->listePaiements[i].nom,paiements->listePaiements[i].id);
	}
	printf("/////////////////////////////////////////////////////////////////// \n");

	//Effectuer paiement
	param_paiement info_paiement;
	info_paiement.id_location = 0; //Location d'un marteau
	info_paiement.id_paiement = 0; //Paypal
	resultat = effectuer_paiement_1(&info_paiement, clnt);
	if (resultat == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else printf("Paiement réussie avec %s\n",paiements->listePaiements[info_paiement.id_paiement].nom);

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	projet_1 (host);
exit (0);
}
