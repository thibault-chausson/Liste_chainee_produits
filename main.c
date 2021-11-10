#include "fcts_listes.h"

main() {
    //Produit 1
    int c1= 100;
    int q1=3;
    float p1=13.99;

    //Produit 2
    int c2=200;
    int q2=7;
    float p2=5.99;

    //Produit 3
    int c3=300;
    int q3=21;
    float p3=9.99;

    List p=NULL;

    //Création de la liste

    p= insert_head(p,c1,q1,p1);
    p= insert_tail(p,c2,q2,p2);
    p= insert_tail(p,c3,q3,p3);


    //On affiche la liste
    printf("La liste de base : \n");
    print_list(p);

    printf("\n");


    //On recherche
    printf("La recherche :\n");
    print_list(research(p,c3));

    printf("\n");

    //Suppression en tête
    p= remove_head(p);
    printf("La suppression en tête :\n");
    print_list(p);

    printf("\n");

    //Suppression en queue
    p= remove_tail(p);
    printf("La suppression en queue :\n");
    print_list(p);

    printf("\n");

}