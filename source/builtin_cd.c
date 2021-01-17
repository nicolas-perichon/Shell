//
// Created by arthur on 17/01/2021.
//

#include <unistd.h>
#include "../header/builtin_cd.h"

/**
 * \brief Exec du builtin cd
 */
void exec_builtin_cd(Liste *liste) {
    chdir(searchELementByIndex(liste, 0 ));
}
