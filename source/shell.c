//
// Projet Shell - Created on 14/11/2020.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../header/shell.h"

/**
 * \brief Fonction qui récupère l'hostname et le login de l'utilisateur courant afin de formater le prompt
 * @return une chaine de caractère servant a l'affichage du prompt
 */
char *prePrintShell() {
    char login[1024];
    char machine[1024];
    char prompt[1014] = "\033[1;33m";

    getlogin_r(login, sizeof(login));
    gethostname(machine, sizeof(login));
    return strcat(strcat(strcat(strcat(prompt, login), "@"), machine), " $ \033[0m");
}

/**
 * \brief Fonction principale du Shell en charge du prompt, de l'appel du traitement syntaxique et de l'appel des builtins
 */
_Noreturn void runShell() {

    while (1) {
        write(0, prePrintShell(), strlen(prePrintShell()));
        char *cmd = malloc(sizeof(cmd));
        read(1, cmd, sizeof(cmd));
        printf(cmd);
    }
}