//
// Projet Shell - Created on 14/11/2020.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../header/shell.h"
#include "../header/arg_list.h"
#include "../header/builtin_ls.h"
#include "../header/builtin_echo.h"
#include "../header/builtin_cat.h"
#include "../header/builtin_env.h"
#include "../header/builtin_pwd.h"
#include "../header/builtin_cd.h"
#include "../header/builtin_touch.h"
#include "../header/builtin_rm.h"
#include "../header/builtin_mv.h"


/**
 * \brief Récupère l'hostname et le login de l'utilisateur courant afin de formater le prompt
 * @return une chaine de caractère servant a l'affichage du prompt
 */
char *prePrintShell() {
    char login[1024];
    char machine[1024];

    // Ajoute de la couleur pour différence le prompt
    char prompt[1014] = "\033[1;33m";

    getlogin_r(login, sizeof(login));
    gethostname(machine, sizeof(login));
    return strcat(strcat(strcat(strcat(prompt, login), "@"), machine), " $ \033[0m");
}

/**
 * \brief Parse la commande et appelle le bon builtin
 * \param cmd : commande en input
 */
void parseCmd(char *cmd) {
    char *builtin;

    // Extrait les tokens de cmd avec le séparateur space
    builtin = strtok(cmd, " ");

    Liste *maListe = initialisation();

    while(builtin != NULL) {
        insertion(maListe, builtin);
        builtin = strtok(NULL, " ");
    }
    int size = getSizeList(maListe);

    char *builtin_name = searchELementByIndex(maListe, size-1);

    if (strcmp(builtin_name, "ls") == 0) {
        exec_builtin_ls();
    }
    else if (strcmp(builtin_name, "echo") == 0) {
        exec_builtin_echo(maListe);
    }
    else if (strcmp(builtin_name, "touch") == 0) {
        exec_builtin_touch(maListe);
    }
    else if (strcmp(builtin_name, "rm") == 0) {
        exec_builtin_rm(maListe);
    }
    else if (strcmp(builtin_name, "mv") == 0) {
        exec_builtin_mv(maListe);
    }
    else if (strcmp(builtin_name, "cat") == 0) {
        exec_builtin_cat(maListe);
    }
    else if (strcmp(builtin_name, "pwd") == 0) {
        exec_builtin_pwd();
    }
    else if (strcmp(builtin_name, "cd") == 0) {
        exec_builtin_cd(maListe);
    }
    else if (strcmp(builtin_name, "env") == 0) {
        exec_builtin_env();
    } else {
        printf("\033[1;31mINFO %s : Commande introuvable\033[0m \n", builtin_name);
        printf("\033[1;31mEssayer avec les commandes suivantes : echo, cat, cd, pwd, ls, touch, rm, mv, env\033[0m\n");
    }
}


/**
 * \brief Lancement du shell
 */
_Noreturn void runShell() {

    while (1) {
        char *entre = NULL;
        fwrite(prePrintShell(), strlen(prePrintShell()),1, stdout);

        char * cmd = malloc(256 * sizeof(char));

        if (fgets(cmd, 256, stdin) != NULL) {
            entre = strchr(cmd, '\n');
            *entre = '\0';
        }

        if(strlen(cmd) > 0) {
            parseCmd(cmd);
        }
    }
}