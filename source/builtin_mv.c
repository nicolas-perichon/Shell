//
// Created by arthur on 24/01/2021.
//

#include <stdio.h>
#include "../header/builtin_mv.h"

/**
 * \brief Exec du builtin mv avec execv
 * \param liste : Liste chaînée
 */
void exec_builtin_mv(Liste *liste) {
    /* Renomme ou déplace le fichier */
    int is_renamed = rename(searchELementByIndex(liste,1), searchELementByIndex(liste,0));

    if (is_renamed != 0) {
        printf("Le fichier n'a pas été renommé et/ou déplacé");
    }
}