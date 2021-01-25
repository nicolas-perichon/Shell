//
// Created by arthur on 24/01/2021.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include "../header/builtin_rm.h"

/**
 * \brief Exec du builtin cat avec execv
 */
void exec_builtin_rm(Liste *liste) {
    int state;

    pid_t process_id;
    process_id = fork();

    if (process_id == -1) {
        printf("can't fork");
    } else if (process_id == 0) {
        char *argv_list[] = {"rm", searchELementByIndex(liste, 0 ), NULL};
        execv("/bin/rm", argv_list);
        printf("\n");
        exit(0);
    } else {
        if (waitpid(process_id, &state, 0) > 0) {
            if (WIFEXITED((state) && WEXITSTATUS(state))) {
                return;
            }
        }
    }
}