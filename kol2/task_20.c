#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
Од стандарден влез се чита цел број N (N<=100) и потоа N низи од знаци.
Низите знаци содржат букви, цифри и специјални знаци (без знаци за празно место),
а секоја од нив не е подолга од 80 знаци.
Да се напише програма со која што на стандарден излез ќе се отпечати најдолгата
низа, којашто е палиндром (се чита исто од од лево на десно и од десно на лево) и
што содржи барем еден специјален знак. Ако нема такви низи, се печати "Nema!".
Ако има две или повеќе низи што го задоволуваат овој услов, се печати првата
низа којашто го задоволува условот.


*/
int daliImaSpec(char *a)
{
    int flag = 0;
    for (int i = 0; i < strlen(a); ++i)
    {
        if (!isalnum(a[i]) && !isspace(a[i]))
        {
            flag = 1;
        }
    }
    return flag;
}
int palindrom(char *a)
{
    int n = strlen(a), flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n - i - 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main()
{
    int n, dolzina, maxDolzina = 0, br = 0;
    char niza[81], najdolga[81];
    scanf("%d", &n);
    if (n > 100)
    {
        return 0;
    }
    while (n)
    {
        scanf("%s", niza);
        if (daliImaSpec(niza))
        {
            br++;
            if (palindrom(niza))
            {
                dolzina = strlen(niza);
                if (dolzina > maxDolzina)
                {
                    maxDolzina = dolzina;
                    strcpy(najdolga, niza);
                }
            }
        }
        n--;
    }
    if (!br)
    {
        printf("Nema!");
    }
    else
    {
        printf("%s", najdolga);
    }
}