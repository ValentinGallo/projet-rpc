# projet-rpc

Projet RPC-GEN de Valentin GALLO et Killian Le Corre


## Scénario 1 :

1 - Enregistrer un adhérent
```c
int enregistrer_adherent(personne); //Renvoie l'id de l'adhérent
```
2 - lister l'ensemble des outils
```c
tab_outils lister_outils(int); //Paramètre : 0 pour tous les outils | 1 seulement ceux disponibles
```
3 - louer un outil
```c
int louer_outil(param_outil); //Renvoie l'id de la location ou -1 si location impossible
```
4 - Afficher les modes de paiement
```c
tab_paiements afficher_mode_paiement();
```
5 - effectuer paiement
```c
int effectuer_paiement(param_paiement);
```
6 - Signaler un anomalie
```c
int signaler_anomalie(int) //Prend en paramètre l'id de l'outil à signaler
```
7 - Retour Outils
```c
int retour_location(int); //Prend en paramètre l'id de l'outil à renvoyer
```

## Scénario 2 :

1 - afficher tarifs
```c
informations tarifs_horaires()
```
2 - lister postes de travail dispo (date)
```c
tab_postes lister_postes()
```
3 - afficher horaires
```c
informations tarifs_horaires()
```
4 - reserver poste (erreur car pas adhérent)
```c
int reserver_poste(param_poste) //Renvoie l'id de la location ou -1 si location impossible
```
5 - renouveler adhésion
```c
int renouveler_adherent(personne)
```
6 - reserver poste (validé car adhérent)
```c
int reserver_poste(param_poste) //Renvoie l'id de la location ou -1 si location impossible
```
## Autres informations

## Structures

- Une personne :
```c
struct personne{
    int id;
    char prenom[10];
    char nom[10];
    int adherent;
};
```

- Un outil :
```c
struct outil{
    int id;
    char nom[10];
    int anomalie;
};
```

- Un poste :
```c
struct poste{
    int id;
    char nom[10];
    char description[10];
};
```

- Une location (outil) :
```c
struct location{
    int id;
    int id_personne;
    int id_outil;
    int payer;
    int retourner;
};
```

- Une réservation (poste) :
```c
struct reservation{
    int id;
    int id_personne;
    int id_poste;
    int payer;
    date date;
    int duree;
};
```

- Une date :
```c
struct date{ 
    int jour;
    int mois; 
    int annee;
    int heure;
    char jourSemaine; //Ex : d = dimanche
};
```

- Un paiement :
```c
struct paiement{
    int id;
    char nom[10];
};
```

- Informations :
```c
struct informations{
    char tarifs[50];
    char horraires[50];
};
```

## Paramètres méthodes
```c
struct param_paiement{
    int id_paiement;
    int id_location;
};
```
```c
struct param_poste{
    int id_poste;
    int id_adherent;
    date date;
    int duree;
};
```
```c
struct param_outil{
    int id_outil;
    int id_adherent;
};
```

## Autres

```c
struct tab_outils{
	outil listeOutils[5];
	int nbOutils;
};
```
```c
struct tab_postes{
	poste listePostes[5];
	int nbPostes;
};
```
```c
struct tab_paiements{
    paiement listePaiements[5];
    int nbPaiements;
};
```