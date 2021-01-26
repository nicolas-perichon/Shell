//
// Created by arthur on 10/12/2020.
//

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "../header/builtin_ls.h"

/**
 * \brief Builtin ls qui liste les fichiers et sous répertoires du répertoire courant
 */
void exec_builtin_ls() {
    // Instanciation de la structure des répertoires
    struct dirent *de;

    // Ouverture du répertoire courant
    DIR *dr = opendir(".");

    // Parcours des fichiers et sous répertoires
    while ((de = readdir(dr)) != NULL) {
        printf("%s   ", de->d_name);
    }

    printf("\n");

    // Fermeture du répertoire
    closedir(dr);
}
