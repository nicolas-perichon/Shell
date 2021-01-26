//
// Created by arthur on 24/01/2021.
//

#include <stdio.h>
#include "../header/builtin_rm.h"

/**
 * \brief Exec du builtin rm
 * \param liste : Liste chaînée
 */
void exec_builtin_rm(Liste *liste) {
    /* Suppression du fichier */
    int rd = remove(searchELementByIndex(liste, 0));

    if(rd != 0) {
        printf("Le fichier n'a pas pu être supprimé");
    }

}