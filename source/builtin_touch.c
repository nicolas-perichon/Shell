//
// Created by arthur on 24/01/2021.
//

#include <stdio.h>
#include <string.h>
#include "../header/builtin_touch.h"

/**
 * \brief Exec du builtin touch
 * \param liste : Liste chaînée
 */
void exec_builtin_touch(Liste *liste) {
    /* Création du fichier */
    FILE *fd =fopen(searchELementByIndex(liste, 0),"w");

    if (fd != NULL) {
        /* Fermeture du fichier */
        fclose(fd);
    }
    else {
        printf("Le fichier n'a pas été créé");
    }
}