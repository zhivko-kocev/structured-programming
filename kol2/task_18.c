#include <stdio.h>
/*
За квадратна матрица А со димензии n x n, од стандарден влез се внесува бројот
n (n > 2) и елементите на матрицата (реални броеви). Нека X e збирот од
елементите под главната дијагонала во матрицата А. Нека Y е збирот од елементите
под споредната дијагонала во матрицата А. Да се креира нова матрица B на следниот начин:
сите елементи од главната дијагонала во матрицата B треба да имаат вредност X
сите елементи од споредната дијагонала во матрицата B треба да имаат вредност Y
ако даден елемент припаѓа и на главната и на споредната дијагонала во матрицата
B, тогаш неговата вредност e X+Y
сите останати елементи во матрицата B имаат вредност 0
*/
float zbirGlavna(int n, float m[n][n])
{
    float suma = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                suma += m[i][j];
            }
        }
    }
    return suma;
}
float zbirSporedna(int n, float m[n][n])
{
    float suma = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j > n - 1)
            {
                suma += m[i][j];
            }
        }
    }
    return suma;
}
void vnesiMatrica(int n, float m[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &m[i][j]);
        }
    }
}
void novaMatrica(int n, float m[n][n], float b[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && i + j == n - 1)
            {
                b[i][j] = zbirGlavna(n, m) + zbirSporedna(n, m);
                continue;
            }
            if (i == j && i + j != n)
            {
                b[i][j] = zbirGlavna(n, m);
                continue;
            }
            if (i != j && i + j == n)
            {
                b[i][j] = zbirSporedna(n, m);
                continue;
            }
            b[i][j] = 0;
        }
    }
}
void pecatiMatrica(int n, float m[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f", m[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    float matrica[100][100], b[100][100];
    int n;
    scanf("%d", &n);
    vnesiMatrica(n, matrica);
    novaMatrica(n, matrica, b);
    pecatiMatrica(n, b);
}