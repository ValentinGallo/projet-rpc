/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PROJET_H_RPCGEN
#define _PROJET_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct date {
	int jour;
	int mois;
	int annee;
	int heure;
};
typedef struct date date;

struct personne {
	int id;
	char prenom[10];
	char nom[10];
	int adherent;
};
typedef struct personne personne;

struct outil {
	int id;
	char nom[10];
	int anomalie;
};
typedef struct outil outil;

struct poste {
	int id;
	char nom[10];
	char description[10];
};
typedef struct poste poste;

struct location {
	int id;
	int id_personne;
	int id_outil;
	int type_location;
	int payer;
	int retourner;
	date date_debut;
	date date_fin;
};
typedef struct location location;

struct param_date {
	date date_debut;
	date date_fin;
};
typedef struct param_date param_date;

struct param_outil {
	int id_outil;
	int id_adherent;
	date date_debut;
	date date_fin;
};
typedef struct param_outil param_outil;

struct param_poste {
	int id_poste;
	int id_adherent;
	date date_debut;
	date date_fin;
};
typedef struct param_poste param_poste;

struct paiement {
	int id;
	char nom[10];
};
typedef struct paiement paiement;

struct param_paiement {
	int id_paiement;
	int id_location;
};
typedef struct param_paiement param_paiement;

struct tab_outils {
	outil listeOutils[5];
	int nbOutils;
};
typedef struct tab_outils tab_outils;

struct tab_postes {
	poste listePostes[5];
	int nbPostes;
};
typedef struct tab_postes tab_postes;

struct tab_paiements {
	paiement listePaiements[5];
	int nbPaiements;
};
typedef struct tab_paiements tab_paiements;

struct informations {
	char tarifs[50];
	char horraires[50];
};
typedef struct informations informations;

#define PROJET 0x23456789
#define GEOM_VERSION_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define INIT 1
extern  int * init_1(void *, CLIENT *);
extern  int * init_1_svc(void *, struct svc_req *);
#define enregistrer_adherent 2
extern  int * enregistrer_adherent_1(personne *, CLIENT *);
extern  int * enregistrer_adherent_1_svc(personne *, struct svc_req *);
#define renouveler_adherent 3
extern  int * renouveler_adherent_1(personne *, CLIENT *);
extern  int * renouveler_adherent_1_svc(personne *, struct svc_req *);
#define lister_outils 4
extern  tab_outils * lister_outils_1(param_date *, CLIENT *);
extern  tab_outils * lister_outils_1_svc(param_date *, struct svc_req *);
#define lister_postes 5
extern  tab_postes * lister_postes_1(param_date *, CLIENT *);
extern  tab_postes * lister_postes_1_svc(param_date *, struct svc_req *);
#define louer_outil 6
extern  int * louer_outil_1(param_outil *, CLIENT *);
extern  int * louer_outil_1_svc(param_outil *, struct svc_req *);
#define reserver_poste 7
extern  int * reserver_poste_1(param_poste *, CLIENT *);
extern  int * reserver_poste_1_svc(param_poste *, struct svc_req *);
#define renouveler_adhesion 8
extern  int * renouveler_adhesion_1(personne *, CLIENT *);
extern  int * renouveler_adhesion_1_svc(personne *, struct svc_req *);
#define afficher_tarifs_postes 9
extern  informations * afficher_tarifs_postes_1(void *, CLIENT *);
extern  informations * afficher_tarifs_postes_1_svc(void *, struct svc_req *);
#define afficher_mode_paiement 10
extern  tab_paiements * afficher_mode_paiement_1(void *, CLIENT *);
extern  tab_paiements * afficher_mode_paiement_1_svc(void *, struct svc_req *);
#define effectuer_paiement 11
extern  int * effectuer_paiement_1(param_paiement *, CLIENT *);
extern  int * effectuer_paiement_1_svc(param_paiement *, struct svc_req *);
#define retour_location 12
extern  int * retour_location_1(int *, CLIENT *);
extern  int * retour_location_1_svc(int *, struct svc_req *);
#define signaler_anomalie 13
extern  int * signaler_anomalie_1(int *, CLIENT *);
extern  int * signaler_anomalie_1_svc(int *, struct svc_req *);
extern int projet_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INIT 1
extern  int * init_1();
extern  int * init_1_svc();
#define enregistrer_adherent 2
extern  int * enregistrer_adherent_1();
extern  int * enregistrer_adherent_1_svc();
#define renouveler_adherent 3
extern  int * renouveler_adherent_1();
extern  int * renouveler_adherent_1_svc();
#define lister_outils 4
extern  tab_outils * lister_outils_1();
extern  tab_outils * lister_outils_1_svc();
#define lister_postes 5
extern  tab_postes * lister_postes_1();
extern  tab_postes * lister_postes_1_svc();
#define louer_outil 6
extern  int * louer_outil_1();
extern  int * louer_outil_1_svc();
#define reserver_poste 7
extern  int * reserver_poste_1();
extern  int * reserver_poste_1_svc();
#define renouveler_adhesion 8
extern  int * renouveler_adhesion_1();
extern  int * renouveler_adhesion_1_svc();
#define afficher_tarifs_postes 9
extern  informations * afficher_tarifs_postes_1();
extern  informations * afficher_tarifs_postes_1_svc();
#define afficher_mode_paiement 10
extern  tab_paiements * afficher_mode_paiement_1();
extern  tab_paiements * afficher_mode_paiement_1_svc();
#define effectuer_paiement 11
extern  int * effectuer_paiement_1();
extern  int * effectuer_paiement_1_svc();
#define retour_location 12
extern  int * retour_location_1();
extern  int * retour_location_1_svc();
#define signaler_anomalie 13
extern  int * signaler_anomalie_1();
extern  int * signaler_anomalie_1_svc();
extern int projet_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_date (XDR *, date*);
extern  bool_t xdr_personne (XDR *, personne*);
extern  bool_t xdr_outil (XDR *, outil*);
extern  bool_t xdr_poste (XDR *, poste*);
extern  bool_t xdr_location (XDR *, location*);
extern  bool_t xdr_param_date (XDR *, param_date*);
extern  bool_t xdr_param_outil (XDR *, param_outil*);
extern  bool_t xdr_param_poste (XDR *, param_poste*);
extern  bool_t xdr_paiement (XDR *, paiement*);
extern  bool_t xdr_param_paiement (XDR *, param_paiement*);
extern  bool_t xdr_tab_outils (XDR *, tab_outils*);
extern  bool_t xdr_tab_postes (XDR *, tab_postes*);
extern  bool_t xdr_tab_paiements (XDR *, tab_paiements*);
extern  bool_t xdr_informations (XDR *, informations*);

#else /* K&R C */
extern bool_t xdr_date ();
extern bool_t xdr_personne ();
extern bool_t xdr_outil ();
extern bool_t xdr_poste ();
extern bool_t xdr_location ();
extern bool_t xdr_param_date ();
extern bool_t xdr_param_outil ();
extern bool_t xdr_param_poste ();
extern bool_t xdr_paiement ();
extern bool_t xdr_param_paiement ();
extern bool_t xdr_tab_outils ();
extern bool_t xdr_tab_postes ();
extern bool_t xdr_tab_paiements ();
extern bool_t xdr_informations ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PROJET_H_RPCGEN */
