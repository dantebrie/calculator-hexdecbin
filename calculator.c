#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void options(int option), decToBin(void), decToHexa(void), binToDec(void), binToHexa(void), hexaToDec(void), hexaToBin(void);
int menu();

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
        op = menu();
        system("cls");

    }while (op);

    return 0;
}

int menu()
{
    int op;

    printf("\t\t\t  Hello! Choose a option below: \n\n");
    printf("\t\t\t====================================\n");
    printf("\t\t\t| 1 - Decimal to binary            |\n");
    printf("\t\t\t|----------------------------------|\n");
    printf("\t\t\t| 2 - Decimal to hexadecimal       |\n");
    printf("\t\t\t|----------------------------------|\n");
    printf("\t\t\t| 3 - Binary to decimal            |\n");
    printf("\t\t\t|----------------------------------|\n");
    printf("\t\t\t| 4 - Binary to hexadecimal        |\n");
    printf("\t\t\t|----------------------------------|\n");
    printf("\t\t\t| 5 - Hexadecimal to decimal       |\n");
    printf("\t\t\t|----------------------------------|\n");
    printf("\t\t\t| 6 - Hexadecimal to binary        |\n");
    printf("\t\t\t|----------------------------------|\n");
    printf("\t\t\t| 0 - Exit                         |\n");
    printf("\t\t\t====================================\n\n");
    printf("\t\t\t  Which option do you want? ");
    scanf("%d", &op);

    system("cls");

    options(op);

    system("pause");

    return op;
}
void options(int option)
{
    switch (option)
    {
    case 1:
        decToBin();
        break;

    case 2:
        decToHexa();
        break;

    case 3:
        binToDec();
        break;

    case 4:
        binToHexa();
        break;

    case 5:
        hexaToDec();
        break;

    case 6:
        hexaToBin();
        break;

    case 0:
        printf("\n\033[4;33m In case I don't see you... good afternoon, good evening, and good night!");
        printf("\n\033[0m");
        abort();
        break;

    default:
        printf("\nThis is not a valid option!\n");
        break;
    }
}

void decToBin(void)
{
    printf("===============================================================\n");
    printf("\033[4;31m You have chosen Decimal to Binary conversion!");
    printf("\033[0m\n\n");
    printf("\033[31m Enter a decimal value to convert: ");
    printf("\033[0m");
    scanf("%d", &value.num);

    printf("\n\n");

    value.n = 0;

    value.quotient = value.num / 2;
    value.remainder = value.num % 2;

    while (value.num != 0)
    {
        sprintf(value.values[value.n], "%d", value.remainder);

        printf("\033[31m Quotient: ");
        printf("\033[0m%d / ", value.num);
        printf("\033[31m Divisor: ");
        printf("\033[0m2\n");
        printf("\033[31m Remainder: ");
        printf("\033[0m%d\n", value.remainder);
        printf("-------------------------------------\n\n");
        value.num = value.quotient;
        value.quotient = value.num / 2;
        value.remainder = value.num % 2;

        value.n++;
    }

    printf("\n");
    printf("\033[31m Value converted: ");
    for (int i = value.n - 1; i >= 0; i--)
    {
        printf("\033[0;4m%s", value.values[i]);
        continue;
    }

    printf("\n\033[0m===============================================================\n");
}

void decToHexa(void) {

    printf("===============================================================\n");
    printf("\033[4;33m You have chosen Decimal to Hexadecimal conversion!");
    printf("\033[0m\n\n");
    printf("\033[33m Enter a decimal value to convert: ");
    printf("\033[0m");
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

        printf("\033[33m Quotient: ");
        printf("\033[0m%d / ", value.num);
        printf("\033[33m Divisor: ");
        printf("\033[0m16\n");
        printf("\033[33m Remainder: ");
        printf("\033[0m%d\n\n", value.remainder);
        printf("-------------------------------------\n\n");

        value.num = value.quotient;
        value.n++;
    }
    printf("\n");

    printf("\033[33m Value converted: ");
    for (int j = value.n - 1; j >= 0; j--) 
    {
        printf("\033[0;4m%s", value.values[j]);
        continue;
    }

    printf("\n\033[0m===============================================================\n");
}

void binToDec(void)
{
    printf("===============================================================\n");
    printf("\033[4;34m You have chosen Binary to Decimal conversion!");
    printf("\033[0m\n\n");
    printf("\033[34m Enter a binary value: ");
    printf("\033[0m");
    scanf("%s", value.alpha);

    value.total_alpha = strlen(value.alpha);
    value.num = 0;

    for (int i = value.total_alpha - 1, b = 0; i >= 0; i--, b++)
    {
        if (value.alpha[i] == '1')
            value.num += pow(2, b);
    }

    printf("\n");
    printf("\033[34m Value converted: ");
    printf("\033[0;4m%d", value.num);
    printf("\n\033[0m===============================================================\n");
}

void binToHexa(void)
{
    printf("===============================================================\n");
    printf("\033[4;32m You have chosen Binary to Hexadecimal conversion!");
    printf("\033[0m\n\n");
    printf("\033[32m Enter a binary value: ");
    printf("\033[0m");
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
    
    printf("\n");
    printf("\033[32m Value converted: ");
    for (int d = value.n - 1; d >= 0; d--)
    {
        printf("\033[0;4m%s", value.values[d]);
        continue;
    }
    printf("\n\033[0m===============================================================\n");
}

void hexaToDec(void)
{
    printf("===============================================================\n");
    printf("\033[4;35m You have chosen Hexadecimal to Decimal conversion!");
    printf("\033[0m\n\n");
    printf("\033[35m Enter a hexadecimal value: ");
    printf("\033[0m");
    scanf("%s", value.alpha);

    value.total_alpha = strlen(value.alpha);

    for (int h = 0; h < value.total_alpha; h++)
    {
        value.alpha[h] = toupper(value.alpha[h]);
    }
    
    sscanf(value.alpha, "%x", &value.num);

    printf("\n");
    printf("\033[35m Value converted: ");
    printf("\033[0;4m%d", value.num);
    printf("\n\033[0m===============================================================\n");
}

void hexaToBin (void)
{
    printf("===============================================================\n");
    printf("\033[4;36m You have chosen Hexadecimal to Binary conversion!");
    printf("\033[0m\n\n");
    printf("\033[36m Enter a hexadecimal value: ");
    printf("\033[0m");
    scanf("%s", value.alpha);
    
    value.total_alpha = strlen(value.alpha);

    for (int g = 0; g < value.total_alpha; g++)
    {
        value.alpha[g] = toupper(value.alpha[g]);
    }

    sscanf(value.alpha, "%x", &value.num);

    while (value.num != 0)
    {
        value.quotient = value.num / 2;
        value.remainder = value.num % 2;

        sprintf(value.values[value.n], "%d", value.remainder);

        value.num = value.quotient;

        value.n++;
    }
    
    printf("\n\n");

    printf("\033[36m Value converted: ");
    for (int c = value.n - 1; c >= 0; c--)
    {
        printf("\033[0;4m%s", value.values[c]);
        continue;
    }
    printf("\n\033[0m===============================================================\n");
}