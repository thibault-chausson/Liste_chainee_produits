//
// Created by Thibault on 27/10/2021.
//

#include "fcts_listes.h"

BOOL is_empty(List l){
    if (l==NULL) /*Si l pointe sur vide ca veut dire que la liste chainée est vide*/ {
        return TRUE;
    }
    else {
        return FALSE;
         }
}

List insert_head(List l, int c, int q, float p) {
    List new_produit; //On crée la liste
    new_produit=(produit *) malloc(sizeof(produit)); //On lui affecte une taille
    new_produit->codeP=c; //On complète toutes les informations necessaires
    new_produit->quantP=q;
    new_produit->prixP=p;
    new_produit->next=l;
    return new_produit;
}

List insert_tail(List l, int c, int q, float p) {
    List new_produit; // On initialise la liste
    List a;
    new_produit=(produit *) malloc(sizeof(produit));
    new_produit->codeP=c;
    new_produit->quantP=q;
    new_produit->prixP=p;
    new_produit->next=NULL;
    if(l == NULL) {
        l=new_produit; //Si c'est vide on ajoute au début
    }
    else {
        a = l;
        while (a->next !=NULL) /*On va jusqu'a la fin est on le met à la fin*/{
            a=a->next;
        }
        a->next=new_produit;
    }
    return l;
}

List remove_head(List l) {
    List a;
    if(l==NULL)/*Si c'est vide on peu rien supprimer donc on renvoi la liste vide*/{
        a=NULL;
    }
    else{
        a=l->next; /*On supprime le debut en mettant l qui pointe sur l'élément suivant et on libère l'élément du début*/
        free(l);
    }
    return a;
}

List remove_tail(List l) {
    if(l!=NULL)/*Si c'est vide on renvoie la liste vide */{
        if (l->next == NULL) /*S'il n'y a que un élément on renvoie une liste vide et on libère l'élément*/{
            free(l);
            l=NULL;
        }
        else {
            List a=l;
            while (a->next->next !=NULL) {
                a=a->next;
            }
            free(a->next); /*On va jusqu'a la fin et on libère le dernier*/
            a->next=NULL;
        }
    }
    return l;
}

List research(List l, int c){
    List a=l;
    List b=NULL; //On crée une liste pour mettre les éléments trouvés
    while (a->next!=NULL){
        if (a->codeP==c)/*On regarde si on a le bon code produit et on l'ajoute dans la liste résultat*/{
            b=insert_head(b,a->codeP,a->quantP,a->prixP);
        }
        a=a->next;
        }
    //On n'oublie pas le dernier
    if (a->codeP==c){
        b=insert_head(b,a->codeP,a->quantP,a->prixP);
    }
    return(b);
}

void print_list(List l) {
        if( is_empty(l) ) /*Si la listez est vide on l'affiche*/ {
        printf(" *** EMPTY LIST *** \n");
        }

        else{

            List a=l;

            while (a->next !=NULL) /*On avance et on affiche chaque caractère*/ {
                printf("[Le code produit : %d, ", a->codeP);
                printf("La quantité du produit en stock : %d, ", a->quantP);
                printf("Le prix du produit : %f ]\n", a->prixP);
                a=a->next;
            }
            /*Et on n'oublie pas le dernier*/
            printf("[Le code produit : %d, ", a->codeP);
            printf("La quantité du produit en stock : %d, ", a->quantP);
            printf("Le prix du produit : %f ]\n", a->prixP);
        }
}

int compter(List l){
    if (is_empty(l)==TRUE) /*Si la liste est vide on renvoie 0 (cas de base)*/{
        return(0);
    }
    else{
        return(compter(l->next)+1); //On fait +1 et on avance au suivant jusqu'à la fin
    }
}

int nb_occurence(List l, int c){
    if (is_empty(l)==TRUE)/*Cas de base si la liste est vide il n'y a aucune occurence de l'élément*/{
        return(0);
    }
    else{
        if(l->codeP==c){
            return(nb_occurence(l->next,c)+1); //Si on trouve l'élément on fait +1 et on avance
        }
        else {
            return(nb_occurence(l->next,c)); //Si on ne le trouve pas on avance seulement
        }
    }
}

List effacer (List l){
    List a=l;
    if (is_empty(l)==FALSE){
        while (l->next !=NULL) /*On avance et on met tout à 0*/{
            l->codeP=0;
            l->quantP=0;
            l->prixP=0;
            l=l->next;
        }
        /*On n'oublie pas le dernier*/
        l->codeP=0;
        l->quantP=0;
        l->prixP=0;
    }
    return(a);
}

int code_produit_i_aux(List l, int i, int n){
    if (is_empty(l)){
        return(-1); //-1 donc problème car pas d'élément ou on a fait toute la liste
    }
    else {
        if (n==i)/*Si on trouve lélément on renvoie cet élément*/{
            return(l->codeP);
        }
        else{
            return (code_produit_i_aux(l->next,i,n+1)); //On avance si on ne le trouve pas
        }
    }
}

int code_produit_i(List l, int i)/*Fonction chapeau et on met le compteur à 1 pour commencer au premier élément*/{
    return(code_produit_i_aux(l,i,1));
}