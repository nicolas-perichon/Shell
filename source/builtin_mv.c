//
// Created by arthur on 24/01/2021.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include "../header/builtin_mv.h"

/**
 * \brief Exec du builtin mv avec execv
 */
void exec_builtin_mv(Liste *liste) {
    int state;

    pid_t process_id;
    process_id = fork();

    if (process_id == -1) {
        printf("can't fork");
    } else if (process_id == 0) {
        char *argv_list[] = {"mv", searchELementByIndex(liste, 1 ), searchELementByIndex(liste, 0), NULL};
        execv("/bin/mv", argv_list);
        printf("\n");
        exit(0);
    } else {
        if (waitpid(process_id, &state, 0) > 0) {
            return;
        }
    }
}