//
// Created by Thibault on 27/10/2021.
//

#ifndef LISTE_FCTS_LISTES_H
#define LISTE_FCTS_LISTES_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

//Déclaration de la liste pour produit
typedef struct prod {
    int codeP;
    int quantP;
    float prixP;
    struct prod *next;
} produit;

typedef produit * List;

BOOL is_empty(List l);

List insert_head(List l, int c, int q, float p);

List insert_tail(List l, int c, int q, float p);

List remove_head(List l);

List remove_tail(List l);

List research(List l, int c);

void print_list(List l);

#endif //LISTE_FCTS_LISTES_H
