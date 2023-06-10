#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void head(void), menu(int option), decToBin(void), decToHexa(void);


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
    system("cls");

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
    int dec_num1, rest_div, dec_quot1, b = 0;
    char rest_1[100], num_bin[100][100];

    printf("Enter a decimal value to convert: ");
    scanf("%d", &dec_num1);

    printf("\n\n");

    dec_quot1 = dec_num1 / 2;
    rest_div = dec_num1 % 2;

    printf("\n\n");
    
    while (dec_num1 != 0)
    {
        sprintf(rest_1, "%d", rest_div);
        strcpy(num_bin[b], rest_1);

        printf("Quotient: %d / Diviser: 2\n", dec_num1);
        printf("Rest: %d\n\n", rest_div);

        dec_num1 = dec_quot1;
        dec_quot1 = dec_num1 / 2;
        rest_div = dec_num1 % 2;

        b++;
    }
    
    printf("Result: ");
    for (int i = b - 1; i >= 0; i--)
    {
        printf("%s", num_bin[i]);
    }
    
    printf("\n\n");
}

void decToHexa(void)
{
    int valor_dec, quotient, rest;

    printf("Enter a decimal value to convert: ");
    scanf("%d", &valor_dec);

    quotient = valor_dec / 16;
    rest = valor_dec % 16;

    printf("\n\n");

    while (valor_dec != 0)
    {
        printf("Quotient: %d / Diviser: 16\n", valor_dec);
        printf("Rest: %d\n\n", rest);
        valor_dec = quotient;
        quotient = valor_dec / 16;
        rest = valor_dec % 16;
    }
    
    printf("Result: ");
}