# projet-rpc

Projet RPC-GEN de Valentin GALLO et Killian Le Corre


## Scénario 1 :

1 - Enregistrer un adhérent
```c
void enregistrer_adherent(personne une_personne);
```
2 - lister l'ensemble des outils
```c
tab_outils lister_outils(param_date);
```
3 - louer un outil
```c
int louer_outil(param_outil);
```
4 - Afficher les modes de paiement
```c
void afficher_mode_paiement();
```
5 - effectuer paiement
```c
int effectuer_paiement(param_paiement);
```
6 - Retour Outils
```c
int effectuer_paiement(param_paiement);
```
7 - Signaler un anomalie
```c
int signaler_anomalie(outil un_outil)
```
## Scénario 2 :

1 - afficher tarifs réservations/horraires
```c
void afficher_tarifs_postes()
```
3 - lister postes de travail dispo (date)
```c
tab_postes lister_postes(param_date)
```
4 - reserver poste (erreur car pas adhérent)
```c
int reserver_poste(param_poste)
```
5 - renouveler adhésion
```c
void renouveler_adherent(personne une_personne)
```
6 - Afficher les modes de paiement
```c
void afficher_mode_paiement();
```
7 - effectuer paiement
```c
int effectuer_paiement(param_paiement);
```
8 - reserver poste (validé car adhérent)
```c
int reserver_poste(param_poste)
```
## Autres informations

## Structures

- Une personne :
```c
struct personne{
    int id;
    char prenom[255];
    char nom[255];
    int adherent; //True or False
};
```

- Un outil :
```c
struct outil{
    int id;
    char nom[255];
    int anomalie; //True or False
};
```

- Un poste :
```c
struct poste{
    int id;
    char nom[255];
    char description[255];
};
```

- Une location (outil ou poste) :
```c
struct location{
    int id;
    int id_personne;
    int id_outil; //1 si outil, 2 si poste
    date date_debut;
    date date_fin;
};
```

- Une date :
```c
struct date{ 
    int jour;
    int mois; 
    int annee;
    int heure;
};
```
