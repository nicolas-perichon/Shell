//
// Created by arthur on 17/01/2021.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include "../header/builtin_env.h"

/**
 * \brief Exec du builtin pwd
 */
void exec_builtin_pwd() {
    char working_directory[1024];
    getcwd(working_directory, sizeof(working_directory));
    printf("%s\n", working_directory);
}
