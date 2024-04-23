#include <stdio.h>
/*
Во дадена датотека “broevi.txt” се запишани повеќе редови со броеви така што
секој ред започнува со еден цел број (N>=1) што означува колку броеви следуваат
по него во тој ред. Да се напише програма која на СИ за секој ред ќе го испечати
бројот со најголема најзначајна цифра. Читањето на броеви завршува кога ќе се
прочита 0.
*/
int digit(int n)
{
    while (n >= 10)
    {
        n /= 10;
    }
    return n;
}
void wtf()
{
    FILE *f = fopen("broevi.txt", "w");
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
    int n, a[100], max, i, maxi, s;
    FILE *f = fopen("broevi.txt", "r");
    while (fscanf(f, "%d", &n))
    {
        if (n == 0)
            break;
        else
        {
            for (i = 0; i < n; i++)
            {
                fscanf(f, "%d", &a[i]);
            }
            max = 0;
            for (i = 0; i < n; i++)
            {
                s = digit(a[i]);
                if (s > max)
                {
                    max = s;
                    maxi = a[i];
                }
            }
            printf("%d\n", maxi);
        }
    }
    fclose(f);
    return 0;
}