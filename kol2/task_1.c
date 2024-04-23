#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
Дадена е текстуална датотека text.txt.

Да се избројат и испечатат сите последнователни појавувања на соседни самогласки
во датотеката. Појавата на големи и мали букви да се игнорира. Пронајдените парови
самогласки да се испечатат на екран, секој во нов ред со мали букви. Потоа во нов
ред се печати бројот на појавувања на паровите самогласки.
*/
int daliE(char c)
{
    c = tolower(c);
    if (isalpha(c))
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

void writeToFile()
{
    FILE *f = fopen("text.txt", "w");
    char c;
    while ((c = getchar()) != '#')
    {
        fputc(c, f);
    }
    fclose(f);
}

int main()
{

    writeToFile();

    FILE *f = fopen("text.txt", "r");
    char samoglaska, prethodna;
    int brojac = 0, flag = 1;
    while ((samoglaska = fgetc(f)) != EOF)
    {
        if (flag)
        {
            prethodna = samoglaska;
            flag = 0;
            continue;
        }
        if (daliE(samoglaska) && daliE(prethodna))
        {
            printf("%c%c", tolower(prethodna), tolower(samoglaska));
            printf("\n");
            brojac++;
            prethodna = samoglaska;
        }
        else
        {
            prethodna = samoglaska;
        }
    }
    fclose(f);
    printf("%d", brojac);

    return 0;
}
