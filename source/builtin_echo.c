//
// Created by nicolas on 10/12/2020.
//

#include <stdio.h>
#include "../header/builtin_echo.h"

/**
 * \brief Lancement du builtin_echo
 * \param liste : Liste chaînée
 */
void exec_builtin_echo(Liste *liste) {

    for (int i = getSizeList(liste) - 2; i >= 0; i--) {
        printf("%s ", searchELementByIndex(liste, i));
    }
    printf("\n");
}