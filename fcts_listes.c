//
// Created by Thibault on 27/10/2021.
//

#include "fcts_listes.h"

BOOL is_empty(List l){
    if (l==NULL) {
        return TRUE;
    }
    else {
        return FALSE;
         }
}

List insert_head(List l, int c, int q, float p) {
    List new_produit;
    new_produit=(produit *) malloc(sizeof(produit));
    new_produit->codeP=c;
    new_produit->quantP=q;
    new_produit->prixP=p;
    new_produit->next=l;
    return new_produit;
}

List insert_tail(List l, int c, int q, float p) {
    List new_produit;
    List a;
    new_produit=(produit *) malloc(sizeof(produit));
    new_produit->codeP=c;
    new_produit->quantP=q;
    new_produit->prixP=p;
    new_produit->next=NULL;
    if(l == NULL) {
        l=new_produit;
    }
    else {
        a = l;
        while (a->next !=NULL) {
            a=a->next;
        }
        a->next=new_produit;
    }
    return l;
}

List remove_head(List l) {
    List a;
    if(l==NULL){
        a=NULL;
    }
    else{
        a=l->next;
        free(l);
    }
    return a;
}

List remove_tail(List l) {
    if(l!=NULL){
        if (l->next == NULL) {
            free(l);
            l=NULL;
        }
        else {
            List a=l;

            while (a->next->next !=NULL) {
                a=a->next;
            }
            free(a->next);
            a->next=NULL;
        }
    }
    return l;
}

List research(List l, int c){
    BOOL res;
    res = FALSE;
    List a=l;
    List b;
    b=(produit *) malloc(sizeof(produit));;
    b->next=NULL;
    b->codeP=-1;
    b->quantP=-1;
    b->prixP=-1;
    while (a->next!=NULL && !res){
        if (a->codeP==c){
            res=TRUE;
            b->next=NULL;
            b->codeP=a->codeP;
            b->quantP=a->quantP;
            b->prixP=a->prixP;
        }
        a=a->next;
        if (a->codeP==c){
            res=TRUE;
            b->next=NULL;
            b->codeP=a->codeP;
            b->quantP=a->quantP;
            b->prixP=a->prixP;
        }
    }
    return(b);
}

void print_list(List l) {
        if( is_empty(l) ) {
        printf(" *** EMPTY LIST *** \n");
        }

        else{

            List a=l;

            while (a->next !=NULL) {
                printf("[Le code produit : %d, ", a->codeP);
                printf("La quantité du produit en stock : %d, ", a->quantP);
                printf("Le prix du produit : %f ]\n", a->prixP);
                a=a->next;
            }
            printf("[Le code produit : %d, ", a->codeP);
            printf("La quantité du produit en stock : %d, ", a->quantP);
            printf("Le prix du produit : %f ]\n", a->prixP);
        }
}