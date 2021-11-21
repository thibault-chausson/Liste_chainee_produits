//
// Created by Thibault on 17/11/2021.
//

#include "fcts_listes.h"

main(){
    int n;
    char cont = 'o';
    List p=NULL;
    int c1;
    int q1;
    float p1;
    int ele;
    int i;
    //On affiche l'ensemble des actions possible
    printf("Que voulez-vous faire ?\n");
    printf("1 : inserer un élément en tête\n");
    printf("2 : inserer un élément en queue\n");
    printf("3 : enlever un élément en tête\n");
    printf("4 : enlever un élément en queue\n");
    printf("5 : rechercher un élément\n");
    printf("6 : compter le nombre d'éléments\n");
    printf("7 : nombre d'occurence d'un élément\n");
    printf("8 : vider liste\n");
    printf("9 : code produit du ième\n");
    printf("10 : afficher\n");
    while(cont=='o')/*Pour savoir si on continue en fonction de la réponse de l'utilisateur*/{
        scanf("%d",&n);
        switch (n) {
            case 1:
                printf("Code produit ?\n");
                scanf("%d",&c1);
                printf("Quantité ?\n");
                scanf("%d",&q1);
                printf("Prix ?\n");
                scanf("%f",&p1);
                p= insert_head(p,c1,q1,p1);
                break;
            case 2:
                printf("Code produit ?\n");
                scanf("%d",&c1);
                printf("Quantité ?\n");
                scanf("%d",&q1);
                printf("Prix ?\n");
                scanf("%f",&p1);
                p= insert_tail(p,c1,q1,p1);
                break;
            case 3:
                p=remove_head(p);
                break;
            case 4:
                p=remove_tail(p);
                break;
            case 5:
                printf("Quel est le code du produit recherché ?\n");
                scanf("%d",&ele);
                print_list(research(p,ele));
                break;
            case 6:
                printf("Nombre éléments dans la liste : %d\n",compter(p));
                break;
            case 7:
                printf("Quel est le code du produit à compter le nombre d'occurence ?\n");
                scanf("%d",&ele);
                printf("Nombre d'occurence de l'éléments %d dans la liste : %d\n",ele,nb_occurence(p,ele));
                break;
            case 8:
                p=effacer(p);
                break;
            case 9:
                printf("Quel est la position de l'élément cherché ?\n");
                scanf("%d",&i);
                printf("Le %d ème élément est : %d\n", i, code_produit_i(p,i));
                break;
            case 10:
                print_list(p);
                break;
            default: //S'il demande une action non référencée
                printf("Commande non référencé");
        }
        printf("Voulez-vous continuer o/n?\n");
        scanf("%s",&cont);
    }
}

