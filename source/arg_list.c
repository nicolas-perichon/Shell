//
// Created by arthur on 10/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/arg_list.h"

/**
 * \brief Initialise le liste chaîné avec le premier elem à NULL
 * \return une liste chaîné
 */
Liste *initialisation() {
    Liste *liste = malloc(sizeof(*liste));

    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }

    liste->premier = NULL;

    return liste;
}

/**
 * \brief Créer et insert un nouvel element dans une liste chaîné
 * \param liste : la liste chaîné dans laquelle inserer un élement
 * \param nvArg : arguments à inserer dans la liste chaîné
 */
void insertion(Liste *liste, char *nvArg) {
    Element *nouveau = malloc(sizeof(*nouveau));

    if (liste == NULL || nouveau == NULL) {
        exit(EXIT_FAILURE);
    }

    nouveau->arg = nvArg;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


/**
 * \brief Récupère et insert un élément dans la liste chaîné
 * \param liste : la liste chaîné dans laquelle inserer un élement
 * \param nouveau : l'élément à inserer
 */
void ajouterElement(Liste *liste, Element *nouveau) {
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


/**
 * \brief Supprimer la liste chaîné
 * \param liste : la liste chaîné à supprimer
 */
void suppression(Liste *liste) {
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL) {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }

}

/**
 * \brief Affiche les éléments de la liste chaîné
 * \param liste : la liste chaîné à affciher
 */
void afficherListe(Liste *liste) {
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL) {
        printf("%s -> ", actuel->arg);
        actuel = actuel->suivant;
    }

    printf("NULL\n");
}


/**
 * \brief Modifie un élément de la liste chaîné
 * \param element : l'élément à inserer
 * \param nvArg : le nouvel argument
 */
void modifierELement(Element *element, char *nvArg) {
    element->arg = nvArg;
}

/**
 * \brief Récupère un élément par son index
 * \param liste : la liste chaîné sur laquel chercher l'élément
 * \param index : position dans la liste chaîné sur laquelle récupérer l'élément
 * \return l'argument de l'élément récupéré
 */
char *searchELementByIndex(Liste *liste, int index) {
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (index > 0) {
        actuel = actuel->suivant;
        index--;
    }

    return actuel->arg;
}


/**
 * \brief Supprime un élément par son index
 * \param liste : la liste chaîné sur laquel supprimer l'élément
 * \param index : position dans la liste chaîné sur laquelle supprimer l'élément
 */
void suppressionByIndex(Liste *liste, int index) {
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *actuel = searchELementByIndex(liste, index);

    printf("%d", index);

    if (actuel->arg == NULL) {
        printf("L'index out of bound");
    } else {
        Element *precedent = searchELementByIndex(liste, index - 1);
        printf("Precedent : %s\nSuivant : %s\n", precedent->arg, actuel->arg);
        precedent->suivant = actuel->suivant;
        printf("Test %s\n", precedent->suivant->arg);
        free(actuel);
        printf("Element supprimé\n");
    }
}


/**
 * \brief Récupère la taille de la liste
 * \param liste : la liste chaîné
 * \return la taille de la liste
 */
int getSizeList(Liste *liste) {
    Element *actuel = liste->premier;
    int index = 0;
    while (actuel != NULL) {
        actuel = actuel->suivant;
        index++;
    }

    return index;
}