#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int nombre1, nombre2, choix; // Déclaration des variables que je vais utiliser !

    printf("Bienvenue dans le calculateur ! \n"); // Acceuil
    printf("Choisissez votre operation ! \n");

    printf("Entrez votre premier nombre.\n"); // Demande du premier nombre
    scanf("%d", &nombre1);

    printf("1. Addition \n 2. Soustraction \n 3. Multiplication \n 4. Division \n"); // Choix de l'opération
    scanf("%d", &choix);

    printf("Entrez votre deuxieme nombre pour que le calcul s'éxécute !\n"); // Demande du deuxième nombre et exécution
    scanf("%d", &nombre2);

    /*Ici l'opération se fait !*/

    switch (choix)
    {
    case 1: // Addition
        printf("Le resultat de l'addition de %d et de %d vaut %d !\n", nombre1, nombre2, nombre1 + nombre2);
        break;

    case 2: // Soustraction
        printf("Le resultat de la soustraction de %d et de %d vaut %d !\n", nombre1, nombre2, nombre1 - nombre2);
        break;

    case 3: // Multilication
        printf("Le resultat de la multiplication de %d et de %d vaut %d !\n", nombre1, nombre2, nombre1 * nombre2);
        break;

    case 4: // Division

        if (nombre2 == 0) // Vérification si nombre2 n'est pas égal à 0 pour ne pas provoquer une erreur
        {
            printf("Impossible de diviser par 0...\n");
            break;
        }
        else
        {
            printf("Le resultat de la division de %d et de %d vaut %d !\n", nombre1, nombre2, nombre1 / nombre2);
            break;
        }

    default:
        printf("Entrez une valeur valide");
        break;
    }

    return 0;
}