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
 * \brief Exec du builtin env avec execv
 */
void exec_builtin_env() {
    int state;

    pid_t process_id;
    process_id = fork();

    if (process_id == -1) {
        printf("can't fork");
    } else if (process_id == 0) {
        char *argv_list[] = {"env", NULL};
        execv("/bin/env", argv_list);
        printf("\n");
        exit(0);
    } else {
        if (waitpid(process_id, &state, 0) > 0) {
            return;
        }
    }
}
