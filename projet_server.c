/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "projet.h"

personne liste_personnes[50]; 
tab_outils outils[50];
informations infos = {tarifs:"5€",horraires:"8h"};

int *
init_1_svc(void *argp, struct svc_req *rqstp)
{
	static int  result;

	outils->nbOutils = 0;

	//Ajout d'un outil
	outil outil_1 = {id:outils->nbOutils, nom:"Marteau",anomalie:0};
	outils->listoutils[outils->nbOutils] = outil_1;
	
	printf("init");
	result = 1;
	return &result;
}

int *
enregistrer_adherent_1_svc(personne *argp, struct svc_req *rqstp)
{
	static int  result;

	liste_personnes[argp->id] = *argp;
	printf("enregistrement");
	result = 1;
	return &result;
}

int *
renouveler_adherent_1_svc(personne *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

tab_outils *
lister_outils_1_svc(param_date *argp, struct svc_req *rqstp)
{
	return outils;
}

tab_postes *
lister_postes_1_svc(param_date *argp, struct svc_req *rqstp)
{
	static tab_postes  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
louer_outil_1_svc(param_outil *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
reserver_poste_1_svc(param_poste *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
renouveler_adhesion_1_svc(personne *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

informations *
afficher_tarifs_postes_1_svc(void *argp, struct svc_req *rqstp)
{
	return &infos;
}

informations *
afficher_mode_paiement_1_svc(void *argp, struct svc_req *rqstp)
{
	static informations  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
effectuer_paiement_1_svc(param_paiement *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
retour_location_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
signaler_anomalie_1_svc(outil *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}
