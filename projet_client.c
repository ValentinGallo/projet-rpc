/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "projet.h"


void
geom_prog_1(char *host)
{
	CLIENT *clnt;
	int  *resultat;
	void *vide;
	tab_outils *outils;
	informations *infos;

	//Informations client
	personne client;
	client.id = 0;
	strcpy(client.prenom,"Jean");
	strcpy(client.nom,"Maurice");
	client.adherent = 1;


#ifndef	DEBUG
	clnt = clnt_create (host, GEOM_PROG, GEOM_VERSION_1, "udp");
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
	resultat = enregistrer_adherent_1(&client, clnt);
	if (resultat == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else printf("Enregistrement réussie(code : %d) \n",*resultat);

	//Afficher tarif
	infos = afficher_tarifs_postes_1(vide, clnt); //ERREUR (call failed: RPC: Remote system error)
	if (infos == (informations *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("Tarif %s",infos->tarifs);

	//Liste outils
	date debut = {heure:0,jour:1,mois:1,annee:2020};
	date fin = {heure:24,jour:1,mois:1,annee:2020};
	param_date dates = {date_debut:debut, date_fin:fin};
	outils = lister_outils_1(&dates, clnt); //ERREUR (call failed: RPC: Remote system error)
	if (outils == (tab_outils *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	for(int i = 0;i<outils->nbOutils;i++){
		printf("Outil %d : %s",i,outils->listoutils[i].nom);
	}
	
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
	geom_prog_1 (host);
exit (0);
}
