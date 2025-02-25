#include <stdio.h>

int main(void){

    int a, b;
    char op;

    printf("Entrez une opération (+, -, *, /) : ");
    scanf("%c", &op);

    printf("Entrez deux nombres : ");
    scanf("%d %d", &a, &b);

    switch(op){
        case '+':
            printf("%d + %d = %d\n", a, b, a+b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a-b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a*b);
            break;
        case '/':
            if(b == 0){
                printf("Division par zéro impossible\n");
            }else{
                printf("%d / %d = %d\n", a, b, a/b);
            }
            break;
        default:
            printf("Opération invalide\n");
    }

    return 0;
}