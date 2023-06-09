#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void head(void), menu(int option), decToBin(void);


int main(int argc, char const *argv[])
{
    int op;

    do
    {
        head();
        printf("Hello! Choose a option below: \n\n");
        printf("1 - Decimal to binary\n");
        printf("2 - Decimal to hexadecimal\n");
        printf("3 - Binary to decimal\n");
        printf("4 - Binary to hexadecimal\n");
        printf("5 - Hexadecimal to decimal\n");
        printf("6 - Hexadecimal to binary\n");
        printf("0 - Exit\n\n");

        printf("Which option do you want? ");
        scanf("%d", &op);

        fflush(stdin);

        menu(op);

    }while (op);

    return 0;
}

void head(void)
{
    printf("=========================================\n");
    printf("=====          CALCULATOR           =====\n");
    printf("=========================================\n");
    printf("\n\n");
}

void menu(int option)
{
    switch (option)
    {
    case 1:
        printf("\nDecimal to binary.\n");
        decToBin();
        break;
    
    case 2:
        break;

    case 3:
        break;

    case 4:
        break;
    
    case 5:
        break;
    
    case 6:
        break;
    
    case 0:
        printf("\nGood bye, partner ...\n");
        abort();
        break;

    default:
        printf("\nNo entered valid option!\n");
        break;
    }
}

void decToBin(void)
{
    int valor, resto, quociente = 1, b = 0;
    char restos[100], binarios[100][100];

    printf("Enter a decimal value to convert: ");
    scanf("%d", &valor);

    printf("\n\n");

    quociente = valor / 2;
    resto = valor % 2;

    while (valor != 0)
    {
        sprintf(restos, "%d", resto);
        strcpy(binarios[b], restos);

        printf("Quocient: %d / Diviser: 2\n", valor);
        printf("Rest: %d\n\n", resto);

        valor = quociente;
        quociente = valor / 2;
        resto = valor % 2;

        b++;
    }
    
    printf("Result: ");
    for (int i = b - 1; i >= 0; i--)
    {
        printf("%s", binarios[i]);
    }
    
    printf("\n\n");
}