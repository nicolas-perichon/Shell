//
// Created by arthur on 17/01/2021.
//

#include <stdio.h>
#include <unistd.h>
#include "../header/builtin_pwd.h"

/**
 * \brief Exec du builtin pwd
 * \param liste : Liste chaînée
 */
void exec_builtin_pwd() {
    char working_directory[1024];

    /* Récuperation du répertoire de travail courant */
    getcwd(working_directory, sizeof(working_directory));

    printf("%s\n", working_directory);
}
