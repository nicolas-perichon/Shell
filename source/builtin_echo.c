//
// Created by nicolas on 10/12/2020.
//

#include <stdio.h>
#include "../header/builtin_echo.h"

/**
 * \brief Builtin echo qui re prompt les arguments passés paramètres
 * \param liste : Liste chaînée
 */
void exec_builtin_echo(Liste *liste) {
    // Prompt les éléments de la liste autre que la cmd (echo)
    for (int i = getSizeList(liste) - 2; i >= 0; i--) {
        printf("%s ", searchELementByIndex(liste, i));
    }
    printf("\n");
}