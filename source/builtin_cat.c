//
// Created by arthur on 17/01/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../header/builtin_cat.h"

/**
 * \brief Builtin cat qui affiche le contenu du fichier passé en paramètre
 * \param liste : Liste chaînée
 */
void exec_builtin_cat(Liste *liste) {
    char *buffer;

    // Ouverture du fichier passé en param
    FILE *fd = fopen(searchELementByIndex(liste, 0), "r");

    if ( fd != NULL )
    {
        // Placement du descripteur de fichier en fin de fichier
        fseek(fd, 0L, SEEK_END);

        // Récuperation de la taille du fichier
        long s = ftell(fd);

        // Replacement du descripteur au début du fichier
        rewind(fd);

        buffer = malloc(s);
        if ( buffer != NULL )
        {
            fread(buffer, s, 1, fd);

            printf("%s", buffer);
            printf("\n");

            // Fermeture du fichier
            fclose(fd);

            // Libère l'espace pris par le buffer pour éviter les fuites mémoires
            free(buffer);
        }
    }

}
