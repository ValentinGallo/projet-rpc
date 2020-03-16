struct date{ 
    int jour;
    int mois; 
    int annee;
    int heure;
};

struct personne{
    int id;
    char prenom[255];
    char nom[255];
    int adherent;
};

struct outil{
    int id;
    char nom[255];
    int anomalie;
};

struct poste{
    int id;
    char nom[255];
    char description[255];
};

struct location{
    int id;
    int id_personne;
    int id_outil;
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
    char nom[255];
};

struct param_paiement{
    int id_paiement;
    int id_location;
    int type_location;
};

struct tab_outils{
	outil listoutils[50];
	int nbOutils;
};

struct tab_postes{
	poste listpostes[50];
	int nbPostes;
};

struct informations{
    char tarifs[255];
    char horraires[255];
};


program GEOM_PROG {
	version GEOM_VERSION_1 {
        int INIT() = 1;
        int enregistrer_adherent(personne une_personne) = 2;
        int renouveler_adherent(personne une_personne) = 3;
        tab_outils lister_outils(param_date) = 4;
        tab_postes lister_postes(param_date) = 5;
        int louer_outil(param_outil) = 6;
        int reserver_poste(param_poste) = 7;
        int renouveler_adhesion(personne une_personne) = 8;
        informations afficher_tarifs_postes() = 9;
        informations afficher_mode_paiement() = 10;
        int effectuer_paiement(param_paiement) = 11;
        int retour_location(int id_location) = 12;
        int signaler_anomalie(outil un_outil) = 13;
        
        
	} = 1;
} = 0x20000001;


