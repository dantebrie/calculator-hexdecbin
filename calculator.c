#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void head(void), menu(int option), decToBin(void), decToHexa(void), binToDec(void), binToHexa(void), hexaToDec(void), hexaToBin(void);

struct Calculator
{
    int num;
    char alpha[30];
    int total_alpha;
    int quotient;
    int remainder;
    char values[100][100];
    int n;
}value;

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
        printf("\nBinary to hexadecimal.\n");
        binToHexa();
        break;

    case 5:
        printf("\nHexadecimal to decimal.\n");
        hexaToDec();
        break;

    case 6:
        printf("\nHexadecimal to binary");
        hexaToBin();
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
    printf("Enter a decimal value to convert: ");
    scanf("%d", &value.num);

    printf("\n\n");

    value.n = 0;

    value.quotient = value.num / 2;
    value.remainder = value.num % 2;

    while (value.num != 0)
    {
        sprintf(value.values[value.n], "%d", value.remainder);

        printf("Quocient: %d / Divisor: 2\n", value.num);
        printf("Remainder: %d\n\n", value.remainder);

        value.num = value.quotient;
        value.quotient = value.num / 2;
        value.remainder = value.num % 2;

        value.n++;
    }

    printf("Result: ");
    for (int i = value.n - 1; i >= 0; i--)
    {
        printf("%s", value.values[i]);
    }

    printf("\n\n");
}

void decToHexa(void) {

    printf("Enter a decimal value to convert: ");
    scanf("%d", &value.num);

    printf("\n\n");

    value.n = 0;

    value.quotient = value.num / 16;
    value.remainder = value.num % 16;

    while (value.num != 0) 
    {
        value.quotient = value.num / 16;
        value.remainder = value.num % 16;

        sprintf(value.values[value.n], "%d", value.remainder);

        if (value.remainder >= 10 && value.remainder <= 15) 
        {
            value.values[value.n][0] = 'A' + (value.remainder - 10);
        }

        printf("Quotient: %d / Divisor: 16\n", value.num);
        printf("Remainder: %d\n\n", value.remainder);

        value.num = value.quotient;
        value.n++;
    }

    printf("Result: ");
    for (int j = value.n - 1; j >= 0; j--) 
    {
        printf("%s", value.values[j]);
    }

    printf("\n\n");
}

void binToDec(void)
{
    printf("Enter a binary value: ");
    scanf("%s", value.alpha);

    value.total_alpha = strlen(value.alpha);
    value.num = 0;

    for (int i = value.total_alpha - 1, b = 0; i >= 0; i--, b++)
    {
        if (value.alpha[i] == '1')
            value.num += pow(2, b);
    }
    
    printf("\n\n");

    printf("Result: %d", value.num);

    printf("\n\n");

}

void binToHexa(void)
{
    printf("Enter a binary value: ");
    scanf("%s", value.alpha);

    value.total_alpha = strlen(value.alpha);
    value.num = 0;

    for (int i = value.total_alpha - 1, d = 0; i >= 0; i--, d++)
    {
        if (value.alpha[i] == '1')
            value.num += pow(2, d);
    }

    value.n = 0;

    while (value.num != 0)
    {
        value.quotient = value.num / 16;
        value.remainder = value.num % 16;

        if (value.remainder < 10)
        {
            sprintf(value.values[value.n], "%d", value.remainder);
        }
        else if(value.remainder >= 10  && value.remainder <= 15)
        {
            value.values[value.n][0] = 'A' + (value.remainder - 10);
        }
        
        value.num = value.quotient;

        value.n++;
    }
    
    printf("Result: ");
    for (int d = value.n - 1; d >= 0; d--)
    {
        printf("%s", value.values[d]);
    }

    printf("\n\n");
}

void hexaToDec(void)
{
    printf("Enter a hexadecimal value: ");
    scanf("%s", value.alpha);

    value.total_alpha = strlen(value.alpha);

    for (int h = 0; h < value.total_alpha; h++)
    {
        value.alpha[h] = toupper(value.alpha[h]);
    }
    
    sscanf(value.alpha, "%x", &value.num);

    printf("Result: %d", value.num);

    printf("\n\n");
}

void hexaToBin (void)
{
    printf("Enter a hexadecimal value: ");
    scanf("%s", value.alpha);
    
    value.total_alpha = strlen(value.alpha);

    for (int g = 0; g < value.total_alpha; g++)
    {
        value.alpha[g] = toupper(value.alpha[g]);
    }
    
    printf("\n\n");

    sscanf(value.alpha, "%x", &value.num);

    while (value.num != 0)
    {
        value.quotient = value.num / 2;
        value.remainder = value.num % 2;

        sprintf(value.values[value.n], "%d", value.remainder);

        value.num = value.quotient;

        value.n++;
    }
    
    printf("Result: ");
    for (int c = value.n - 1; c >= 0; c--)
    {
        printf("%s", value.values[c]);
    }
    
    printf("\n\n");
}