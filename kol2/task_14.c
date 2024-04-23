#include <stdio.h>
/*
Да се напише програма во која се вчитува матрица од цели броеви A со N редици и
N * 2 колони (N не е поголемо од 50). Програмата треба да ја трансформира
вчитаната матрица во нова матрица B, така што сите елементи десно од N-тата
колона ќе ги префрли под N-тата редица, односно од матрица со димензија N редици
и 2 * N колони ќе се добие матрица со 2 * N редици x N колони.
*/
int main()
{
    int n;
    scanf("%d", &n);
    int matricaa[n][n * 2], matricab[n * 2][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n * 2; ++j)
        {
            scanf("%d", &matricaa[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matricab[i][j] = matricaa[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = n; j < n * 2; ++j)
        {
            matricab[i + n][j - n] = matricaa[i][j];
        }
    }
    for (int i = 0; i < n * 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", matricab[i][j]);
        }
        printf("\n");
    }
}