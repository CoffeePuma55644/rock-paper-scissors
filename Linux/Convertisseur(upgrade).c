#include <stdio.h>

void convertion_binaire(int nombre){ // Fonction qui convertit un nombre en binaire
    int quotient, reste;
    int tab[100], i = 0;

    quotient = nombre;

    while(quotient != 0){ // Tant que le quotient est différent de 0
        reste = quotient % 2; // On récupère le reste de la division par 2
        tab[i] = reste;     // On stocke le reste dans un tableau, le i correspond à l'index
        quotient = quotient / 2; // On divise le quotient par 2 pour la prochaine itération
        i++; // On incrémente i pour viser l'index suivant du tableau
    }

    printf("Le nombre %d en binaire est : ", nombre); // On affiche le nombre en binaire
    for(int j = i-1; j >= 0; j--){ // On parcourt le tableau en partant de la fin
        printf("%d", tab[j]); // On affiche le contenu du tableau
    }
    printf("\n");
}

void convertion_hexadecimal(int nombre){ // Fonction qui convertit un nombre en hexadécimal
    int quotient, reste;
    char tab[100];
    int i = 0;

    quotient = nombre;

    while(quotient != 0){ // Tant que le quotient est différent de 0
        reste = quotient % 16; // On récupère le reste de la division par 16
        if(reste < 10){ // Si le reste est inférieur à 10
            tab[i] = reste + 48; // On stocke le reste dans le tableau en ajoutant 48 pour obtenir le code ASCII
        }else{ // Sinon
            tab[i] = reste + 55; // On stocke le reste dans le tableau en ajoutant 55 pour obtenir le code ASCII
        }
        quotient = quotient / 16; // On divise le quotient par 16 pour la prochaine itération
        i++; // On incrémente i pour viser l'index suivant du tableau
    }

    printf("Le nombre %d en hexadécimal est : ", nombre); // On affiche le nombre en hexadécimal
    for(int j = i-1; j >= 0; j--){ // On parcourt le tableau en partant de la fin
        printf("%c", tab[j]); // On affiche le contenu du tableau
    }
    printf("\n");
}

void convertion_dollars(int dollars){ // Fonction qui convertit des dollars en francs
    float francs = dollars * 5.6; // On multiplie le nombre de dollars par 5.6 pour obtenir le nombre de francs
    printf("%d dollars équivaut à %.2f francs\n", dollars, francs); // On affiche le résultat
}

void convertion_francs(int francs){ // Fonction qui convertit des francs en dollars
    float dollars = francs / 5.6; // On divise le nombre de francs par 5.6 pour obtenir le nombre de dollars
    printf("%d francs équivaut à %.2f dollars\n", francs, dollars); // On affiche le résultat
}

int main(void){

    int mot_de_passe = 1234;
    int mot_de_passe_utilisateur;

    printf("Entrez le mot de passe : ");
    scanf("%d", &mot_de_passe_utilisateur);
    
    if (mot_de_passe == mot_de_passe_utilisateur)
    {
        printf("Mot de passe correct\n");
        printf("Bienvenue dans le convertisseur ! \n");
        printf("Ici vous pouvez convertir un nombre en binaire et en hexadécimal. \n");
        printf("Vous pouvez également convertir des dollars en francs et des francs en dollars. \n");

        while (1) {
            int choix;

            printf("\n1. Conversion en binaire\n2. Conversion en hexadécimal\n3. Conversion en dollars\n4. Conversion en francs\n5. Quitter\n");
            printf("Entrez votre choix : ");
            scanf("%d", &choix);

            switch (choix)
            {
            case 1:
                printf("Entrez un nombre : ");
                int nombre;
                scanf("%d", &nombre);
                convertion_binaire(nombre);
                break;

            case 2:
                printf("Entrez un nombre : ");
                int nombre2;
                scanf("%d", &nombre2);
                convertion_hexadecimal(nombre2);
                break;

            case 3:
                printf("Entrez un nombre de dollars : ");
                int dollars;
                scanf("%d", &dollars);
                convertion_dollars(dollars);
                break;

            case 4:
                printf("Entrez un nombre de francs : ");
                int francs;
                scanf("%d", &francs);
                convertion_francs(francs);
                break;

            case 5:
                printf("Au revoir ! \n");
                return 0;

            default:
                printf("Choix invalide ! \n");
            }
        }
    }
    else {
        printf("Mot de passe incorrect ! \n");
        printf("Vous n'avez pas accès au convertisseur\n");
    }

    return 0;
}