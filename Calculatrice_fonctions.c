#include <stdio.h>

int addition(int a, int b)
{
    return a + b;
}

int soustraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}

int main(void)
{
    int plus = addition(50, 40);
    printf("Résultat vaut: %d\n", plus);

    int moin = soustraction(78, 25);
    printf("Résultat vaut: %d\n", moin);

    int fois = multiplication(10, 2);
    printf("Résultat vaut: %d\n", fois);

    int divise = division(80, 2);
    printf("Résultat vaut: %d\n", divise);

    return 0;
}