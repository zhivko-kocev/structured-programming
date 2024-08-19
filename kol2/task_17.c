#include <stdio.h>
#include <stdlib.h>
/*
Од тастатура се внесуваат димензиите на една матрица (m,n <= 100), а потоа
и елементите од матрицата. Да се трансформира матрицата така што средниот елемент
во секоја редица ќе се замени со разликата (по апсолутна вредност) на сумата на
елементите во првата половина од редицата и сумата на елементите во втората
половина на редицата. Ако матрицата има парен број колони, се менува вредноста
на средните два елемента. Средниот/те елемент/и влегува/ат во сумите (при непарен
 број на колони, средниот елемент влегува во двете суми!). Да се испечати на
 екран променетата матрица.
*/
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

int zbirLeva(int m, int n, int a[][n])
{
    int zbir = 0;
    if (n % 2 == 0)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j < n / 2)
            {
                zbir += a[m][j];
            }
        }
    }
    else
    {
        for (int j = 0; j < n; ++j)
        {
            if (j < n / 2)
            {
                zbir += a[m][j];
            }
        }
    }
    return zbir;
}

int zbirDesna(int m, int n, int a[][n])
{
    int zbir = 0;
    if (n % 2 == 0)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j >= n / 2)
            {
                zbir += a[m][j];
            }
        }
    }
    else
    {
        for (int j = 0; j < n; ++j)
        {
            if (j > n / 2)
            {
                zbir += a[m][j];
            }
        }
    }
    return zbir;
}

void transformiraj(int m, int n, int a[][n])
{
    if (n % 2 == 0)
    {
        for (int i = 0; i < m; ++i)
        {
            int br = abs(zbirLeva(i, n, a) - zbirDesna(i, n, a));
            for (int j = 0; j < n; ++j)
            {
                if (j == n / 2 || j == (n - 1) / 2)
                {
                    a[i][j] = br;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < m; ++i)
        {
            int br = abs(zbirLeva(i, n, a) - zbirDesna(i, n, a));
            for (int j = 0; j < n; ++j)
            {
                if (j == n / 2)
                {
                    a[i][j] = br;
                }
            }
        }
    }
}

void printajMatrica(int m, int n, int a[m][n])
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m, n, matrica[100][100];
    scanf("%d%d", &m, &n);
    vnesiMatrica(m, n, matrica);
    //    transformiraj(m,n,matrica);
    //    printajMatrica(m,n,matrica);
    printf("%d ", zbirLeva(0, n, matrica));
    printf("%d", zbirDesna(0, n, matrica));
}