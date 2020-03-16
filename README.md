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

2 - lister l'ensemble des outils

3 - ajouter location

4 - Afficher les modes de paiement

5 - effectuer paiement

6 - Retour Outils

## Scénario 2 :

1 - afficher tarifs réservations/horraires

3 - lister postes de travail dispo (date)

4 - ajouter réservation (erreur impossible pas abo)

5 - renouveler adhésion

( 2 methodes paiements)

6 - ajouter réservation
