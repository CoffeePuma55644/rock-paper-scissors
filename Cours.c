#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int nombre1; // Déclaration des variables que je vais utiliser !
    int nombre2;
    int choix;

    printf("Bienvenue dans le calculateur ! \n"); // Acceuil
    printf("Choisissez votre operation ! \n");

    printf("Entrez votre premier nombre.\n"); // Demande du premier nombre
    scanf("%d", &nombre1);

    printf("1. Addition \n 2. Soustraction \n 3. Multiplication \n 4. Division \n"); // Choix de l'opération
    scanf("%d", &choix);

    printf("Entrez votre deuxieme nombre pour que le calcul s'éxécute !\n"); // Demande du deuxième nombre et exécution
    scanf("%d", &nombre2);

    /*Ici l'opération se fait !*/

    if (choix == 1) // Addition
    {
        printf("Le resultat de l'addition de %d et de %d vaut %d !\n", nombre1, nombre2, nombre1 + nombre2);
    }
    else if (choix == 2) // Soustraction
    {
        printf("Le resultat de la soustraction de %d et de %d vaut %d !\n", nombre1, nombre2, nombre1 - nombre2);
    }
    else if (choix == 3) // Multiplication
    {
        printf("Le resultat de la multiplication de %d et de %d vaut %d !\n", nombre1, nombre2, nombre1 * nombre2);
    }
    else if (choix == 4) // Division
    {
        printf("Le resultat de la division de %d et de %d vaut %d !\n", nombre1, nombre2, nombre1 / nombre2);
    }
    else
    {
        printf("Veuillez entrez une opération valide !");
    }

    return 0;
}