#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
Од стандарден влез се чита цел број N (N<100) и потоа N низи од знаци.
Низите знаци содржат букви, цифри и специјални знаци, а секоја од нив не е
поголема од 50 знаци.
Да се напише програма што ќе ги отпечати на екран сите низи од знаци во кои се
содржи поднизата А1c  најмалку 2 пати (пр. A1c01АA1c92, 12A1cwwA1cxy,
аA1cwA1cA1ccA1cxab) според редоследот како што се прочитани од влезот.
При печатење на зборовите, сите алфабетски знаци треба да се испечатат со мали
букви.
*/
int pojavuvanja(char *niza, char *podniza)
{
    int dolzina1 = strlen(niza), dolzina2 = strlen(podniza), brojac = 0;
    for (int i = 0; i < dolzina1; i++)
    {
        int flag = 1;
        for (int j = 0; j < dolzina2; j++)
        {
            if (tolower(niza[i + j]) != podniza[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            brojac++;
            i += dolzina2 - 1;
        }
    }
    return brojac;
}
int main()
{
    char niza[100], podniza[] = {"a1c"};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        fgets(niza, 100, stdin);
        if (pojavuvanja(niza, podniza) > 1)
        {
            for (int j = 0; j < strlen(niza); j++)
            {
                niza[j] = tolower(niza[j]);
            }
            puts(niza);
        }
    }
}