#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void head(void), menu(int option), decToBin(void), decToHexa(void), binToDec(void);


int main()
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
        printf("\nDecimal to hexadecimal.\n");
        decToHexa();
        break;

    case 3:
        printf("\nBinary to decimal.\n");
        binToDec();
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
    int valor_decimal, resto_binario, quo_decimal, b = 0;
    char binarios[100][100];

    printf("Enter a decimal value to convert: ");
    scanf("%d", &valor_decimal);

    printf("\n\n");

    quo_decimal = valor_decimal / 2;
    resto_binario = valor_decimal % 2;

    while (valor_decimal != 0)
    {
        sprintf(binarios[b], "%d", resto_binario);

        printf("Quocient: %d / Divisor: 2\n", valor_decimal);
        printf("Remainder: %d\n\n", resto_binario);

        valor_decimal = quo_decimal;
        quo_decimal = valor_decimal / 2;
        resto_binario = valor_decimal % 2;

        b++;
    }

    printf("Result: ");
    for (int i = b - 1; i >= 0; i--)
    {
        printf("%s", binarios[i]);
    }

    printf("\n\n");
}

void decToHexa(void) {
    int num_decimal, quoc_decimal, resto_hexa, h = 0;
    char hexa[100][100];

    printf("Enter a decimal value to convert: ");
    scanf("%d", &num_decimal);

    printf("\n\n");

    quoc_decimal = num_decimal / 16;
    resto_hexa = num_decimal % 16;

    while (num_decimal != 0) 
    {
        quoc_decimal = num_decimal / 16;
        resto_hexa = num_decimal % 16;

        sprintf(hexa[h], "%d", resto_hexa);

        if (resto_hexa >= 10 && resto_hexa <= 15) 
        {
            hexa[h][0] = 'A' + (resto_hexa - 10);
        }

        printf("Quotient: %d / Divisor: 16\n", num_decimal);
        printf("Remainder: %d\n\n", resto_hexa);

        num_decimal = quoc_decimal;
        h++;
    }

    printf("Result: ");
    for (int j = h - 1; j >= 0; j--) 
    {
        printf("%s", hexa[j]);
    }

    printf("\n\n");
}

void binToDec(void)
{

}