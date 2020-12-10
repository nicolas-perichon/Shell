//
// Created by arthur on 10/12/2020.
//

#ifndef SHELL_LIST_H
#define SHELL_LIST_H

typedef struct Element Element;

struct Element{
    char * arg;
    Element *suivant;
};

typedef struct Liste Liste;

struct Liste {
    Element *premier;
};

extern Liste *initialisation();
extern void insertion(Liste *liste, char *nvArg);
extern void ajouterElement(Liste *liste, Element *nouveau);
extern void suppression(Liste *liste);
extern void afficherListe(Liste *liste);
extern void modifierELement(Element *element, char *nvArg);
extern void searchELement(Liste *liste, char *nbNombre);
extern char *searchELementByIndex(Liste *liste, int index);
extern void suppressionByIndex(Liste *liste, int index);
extern int getSizeList(Liste *liste);

#endif //SHELL_LIST_H
