#include <stdio.h>
/*
Од стандарден влез се чита природен број N (N <= 100), како и низа од
позитивни цели броеви a[ ] со N елементи.
Да се напише функција int par(a, n) која ќе го врати најмалиот елемент во
низата кој се појавува парен број пати во низата. Доколку нема таков елемент,
функцијата враќа вредност 0.
Напишете програма што ќе ја повика функцијата par за внесената низа a[ ] и ќе
го испечати најмалиот број којшто се појавува парен број пати во низата a[ ].
*/
int brPojavuvanja(int br, int n, int *a)
{
    int brojac = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == br)
        {
            brojac++;
        }
    }
    return brojac;
}
int par(int *a, int n)
{
    int minBr = 0, flag = 1;
    for (int i = 0; i < n; ++i)
    {
        if (brPojavuvanja(a[i], n, a) % 2 == 0)
        {
            if (flag)
            {
                minBr = a[i];
                flag = 0;
                continue;
            }
            if (a[i] < minBr)
            {
                minBr = a[i];
            }
        }
    }
    if (!minBr)
    {
        return 0;
    }
    else
    {
        return minBr;
    }
}
int main()
{
    int niza[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &niza[i]);
    }
    if (par(niza, n))
    {
        printf("Najmaliot element koj se pojavuva paren broj pati e %d", par(niza, n));
    }
    else
    {
        printf("Nitu eden element ne se pojavuva paren broj pati!");
    }
}