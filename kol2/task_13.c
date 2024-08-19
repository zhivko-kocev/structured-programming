#include <stdio.h>
/*
Oд стандарден влез се вчитува еден цел број X, димензии на матрица M и N
(цели броеви), како и елементите на матрицата со димензии M x N (цели броеви).
Да се напише програма што ќе ги промени редиците на матрицата на следниот начин:
Ако збирот на елементите од редот е поголем од X, елементите на тој ред добиваат вредност 1
Ако збирот на елементите од редот е помал од X, елементите на тој ред добиваат вредност -1
Ако збирот на елементите од редот е еднаков на X, елементите на тој ред добиваат вредност 0
Променетата матрица да се испечати на екран.
*/
int sumaRedovi(int m, int n, int a[][n])
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += a[m][i];
    }
    return suma;
}
void vnesiMatrica(int m, int n, int a[m][n])
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void printajMatrica(int m, int n, int a[m][n])
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void transformacija(int x, int m, int n, int a[][n])
{
    for (int i = 0; i < m; ++i)
    {
        int br = sumaRedovi(i, n, a);
        for (int j = 0; j < n; ++j)
        {
            if (x > br)
            {
                a[i][j] = -1;
            }
            if (x < br)
            {
                a[i][j] = 1;
            }
            if (x == br)
            {
                a[i][j] = 0;
            }
        }
    }
}
int main()
{
    int x, m, n, matrica[100][100];
    scanf("%d", &x);
    scanf("%d%d", &m, &n);
    vnesiMatrica(m, n, matrica);
    transformacija(x, m, n, matrica);
    printajMatrica(m, n, matrica);
}