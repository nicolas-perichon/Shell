//
// Created by arthur on 17/01/2021.
//

#include <unistd.h>
#include "../header/builtin_cd.h"

/**
 * \brief Builtin cd pour changer le répertoire courant
 * \param liste : Liste chaînée
 */
void exec_builtin_cd(Liste *liste) {
    /* Changement du répertoire de travail */
    chdir(searchELementByIndex(liste, 0 ));
}
