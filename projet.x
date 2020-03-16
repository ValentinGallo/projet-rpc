struct personne{
    int id;
    char* prenom;
    char* nom;
    int adherent;
};

struct outil{
    int id;
    char * nom;
};

struct poste{
    int id;
    char * nom;
    char * description;
};

struct location{
    int id;
    int id_personne;
    int id_outil;
};

struct date{ 
    int jour;
    int mois; 
    int annee;
    int heure;
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

struct param_paiement{
    int id_paiement;
    int id_location;
};

struct paiement{
    int id;
    char * nom;
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


program GEOM_PROG {
	version GEOM_VERSION_1 {
        void INIT() = 1;
        void enregistrer_adherent(personne une_personne) = 2;
        tab_outils lister_outils(param_date) = 3;
        tab_postes lister_postes(param_date) = 4;
        int louer_outil(param_outil) = 5;
        int reserver_poste(param_poste) = 6;
        int renouveler_adhesion(personne une_personne) = 7;
        void afficher_tarifs_postes() = 8;
        void afficher_mode_paiement() = 9;
        int effectuer_paiement(param_paiement) = 10;
        int retour_location(int id_location) = 11;
        afficher_description_poste(int id_poste) = 12;
        
        
	} = 1;
} = 0x20000001;


