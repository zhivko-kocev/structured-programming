#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
Во дадена датотека dat.txt да се најде најдолгиот ред во кој има барем 2 цифри.
На стандарден излез да се испечатат знаците од најдолгиот ред кои се наоѓаат
помеѓу првата и последната цифра (заедно со тие 2 цифри) во истиот редослед.
Доколку има повеќе такви редови се печати последниот. Се претпоставува дека ниту
еден ред на датотеката не е подолг од 100 знаци.
*/

void wtf()
{
    FILE *f = fopen("dat.txt", "w");
    char c;
    while ((c = getchar()) != EOF)
    {
        fputc(c, f);
    }
    fclose(f);
}

int main()
{
    wtf();
    char red[100], maxRed[100];
    int cifra1, cifra2, flag, krajnaCifra1, krajnaCifra2, vkupnoCifri = 0, dolzinaRed, dolzinaMax = 0;
    FILE *f = fopen("dat.txt", "r");
    while (fgets(red, 100, f) != NULL)
    {
        dolzinaRed = strlen(red);
        flag = 1;
        for (int i = 0; i < dolzinaRed; ++i)
        {
            if (isdigit(red[i]))
            {
                if (flag)
                {
                    cifra1 = i;
                    flag = 0;
                    vkupnoCifri++;
                }
                else
                {
                    vkupnoCifri++;
                    cifra2 = i;
                }
            }
        }
        if (vkupnoCifri > 1 && dolzinaRed >= dolzinaMax)
        {
            dolzinaMax = dolzinaRed;
            strcpy(maxRed, red);
            krajnaCifra1 = cifra1;
            krajnaCifra2 = cifra2;
        }
        vkupnoCifri = 0;
    }
    for (int i = krajnaCifra1; i <= krajnaCifra2; ++i)
    {
        printf("%c", maxRed[i]);
    }
}