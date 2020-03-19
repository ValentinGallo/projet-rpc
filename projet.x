struct date{ 
    int jour;
    int mois; 
    int annee;
    int heure;
};

struct personne{
    int id;
    char prenom[10];
    char nom[10];
    int adherent;
};

struct outil{
    int id;
    char nom[10];
    int anomalie;
};

struct poste{
    int id;
    char nom[10];
    char description[10];
};

struct location{
    int id;
    int id_personne;
    int id_outil;
    int type_location;
    int payer;
    int retourner;
    date date_debut;
    date date_fin;
};

struct param_date{
    date date_debut;
    date date_fin;
};

struct param_outil{
    int id_outil;
    int id_adherent;
    date date_debut;
    date date_fin;
};

struct param_poste{
    int id_poste;
    int id_adherent;
    date date_debut;
    date date_fin;
};

struct paiement{
    int id;
    char nom[10];
};

struct param_paiement{
    int id_paiement;
    int id_location;
};

struct tab_outils{
	outil listeOutils[5];
	int nbOutils;
};

struct tab_postes{
	poste listePostes[5];
	int nbPostes;
};

struct tab_paiements{
    paiement listePaiements[5];
    int nbPaiements;
};

struct informations{
    char tarifs[50];
    char horaires[50];
};


program PROJET {
	version GEOM_VERSION_1 {
        int INIT() = 1;
        int enregistrer_adherent(personne) = 2;
        int renouveler_adhesion(int) = 3;
        tab_outils lister_outils(param_date) = 4;
        tab_postes lister_postes(param_date) = 5;
        int louer_outil(param_outil) = 6;
        int reserver_poste(param_poste) = 7;
        informations tarifs_horaires() = 8;
        tab_paiements afficher_mode_paiement() = 9;
        int effectuer_paiement(param_paiement) = 10;
        int retour_location(int) = 11;
        int signaler_anomalie(int) = 12;
	} = 1;
} = 0x23456789;