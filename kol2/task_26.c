#include <stdio.h>
/*
Од стандарден влез се чита природен број N (N <= 100), како и низа a[ ] од N цели броеви.
Да се напише функција void premesti(а, n) која го преместува секој пронајден
негативен број на крајот на низата. По преместувањето редоследот на позитивните
броеви треба да остане ист како и во оригиналната низа, а истото важи и за редоследот на негативните.
Нaпишете програма која ќе ја повика функцијата premesti за внесената низа a[ ]
и потоа ќе ја испечати новодобиената низа.
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void premesti(int *a, int n)
{
    int pocetok = n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            pocetok = i;
            break;
        }
    }
    for (int i = pocetok; i < n; i++)
    {
        if (a[i] >= 0)
        {
            int temp = i;
            while (temp != pocetok)
            {
                swap(&a[temp - 1], &a[temp]);
                temp--;
            }
            pocetok++;
        }
    }
}
int main()
{
    int niza[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &niza[i]);
    }
    premesti(niza, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", niza[i]);
    }
}