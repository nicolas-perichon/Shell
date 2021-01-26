//
// Created by arthur on 17/01/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "../header/builtin_env.h"

/**
 * \brief Exec du builtin env
 * \param liste : Liste chaînée
 */
void exec_builtin_env(Liste *liste) {
    /* Récuperation de la variable d'environnement */
    char *env = getenv(searchELementByIndex(liste, 0));

    printf("%s\n", env );

}
