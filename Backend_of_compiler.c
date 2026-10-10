
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char icode[30][30], str[30], opr[10];
    int i = 0;

    printf("Enter the intermediate code (type exit to stop):\n");

    do {
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit") != 0);

    printf("\nTarget code generation:\n");

    i = 0;

    while (strcmp(icode[i], "exit") != 0)
    {
        strcpy(str, icode[i]);

        switch (str[3])
        {
            case '+': strcpy(opr, "ADD"); break;
            case '-': strcpy(opr, "SUB"); break;
            case '*': strcpy(opr, "MUL"); break;
            case '/': strcpy(opr, "DIV"); break;
            default:
                printf("Invalid operator\n");
                i++;
                continue;
        }

        printf("MOV %c, R%d\n", str[2], i);
        printf("%s %c, R%d\n", opr, str[4], i);
        printf("MOV R%d, %c\n", i, str[0]);

        i++;
    }
}
