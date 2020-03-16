# projet-rpc

## Variables globales (server.c)

tableau d'adhérents (ex : adherent liste_adherents[100])
id personnel
id

tableau d'outils (ex : outil liste_outils[100])

tableau postes (ex : poste liste_postes[100])


ex :
struct location
    id_personnel(->struct personnel)
    id_outil (->struct outil)

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
