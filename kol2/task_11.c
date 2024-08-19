#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
Да се напише програма во која од дадена датотека со име "input.txt" за секој
ред ќе се отпечати бројот на цифри во тој ред, знакот :, па самите цифри
подредени според ASCII кодот во растечки редослед. Редовите во датотеката не се
подолги од 100 знаци.
*/
void sort(char *a)
{
    for (int i = 0; i < strlen(a) - 1; i++)
    {
        for (int j = i + 1; j < strlen(a); j++)
        {
            if (*(a + i) > *(a + j))
            {
                char temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}
int vkupnoCifri(char *a)
{
    int brojac = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (isdigit(a[i]))
        {
            brojac++;
        }
    }
    return brojac;
}
void wtf()
{
    FILE *f = fopen("input.txt", "w");
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
    FILE *f = fopen("input.txt", "r");
    char red[101], nov[101] = {0};
    int j = 0;
    while (fgets(red, 101, f) != NULL)
    {
        for (int i = 0; i < strlen(red); ++i)
        {
            if (isdigit(red[i]))
            {
                nov[j] = red[i];
                j++;
            }
        }
        sort(nov);
        printf("%d:%s\n", vkupnoCifri(red), nov);
    }

    return 0;
}
