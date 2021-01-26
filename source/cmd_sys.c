//
// Created by arthur on 17/01/2021.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "../header/cmd_sys.h"

/**
 * \brief Exec des cmd sys avec execv
 */
void exec_cmd_sys(Liste *liste) {
    char cmd[1024] = "/bin/";
    int state;
    char *tab[getSizeList(liste)];
    int index = 0;

    for (int i = getSizeList(liste) - 1; i >= 0; i--) {
        tab[index] = searchELementByIndex(liste, i);
        index += 1;
    }
    tab[index] = NULL;

    pid_t process_id;

    process_id = fork();
    if (process_id == -1) {
        printf("can't fork");
    } else if (process_id == 0) {
        execv(strcat(cmd, tab[0]), tab);
        printf("\n");
        exit(0);
    } else {
        if (waitpid(process_id, &state, 0) > 0) {
            return;
        }
    }
}