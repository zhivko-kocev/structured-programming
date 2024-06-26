#include <stdio.h>
#include <stdlib.h>
/*
Да се напише програма која вчитува матрица со димензии MxN (макс. 100x100).
На почетокот се внесуваат димензиите на матрицата, а потоа и елементите на
матрицата кои се само вредностите 1 и 0. Програмата треба да изброи и отпечати на
СИ во колку од редиците и колоните има барем 3 последователни елементи со вредност 1.
*/
int main()
{
    int i, j, m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int kol = 0, red = 0, br;
    for (i = 0; i < m; i++)
    {
        br = 0;
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                br++;
            }
            if (a[i][j] == 0 && br < 3)
            {
                br = 0;
            }
        }
        if (br > 2)
        {
            red++;
        }
    }

    for (i = 0; i < n; i++)
    {
        br = 0;
        for (j = 0; j < m; j++)
        {
            if (a[j][i] == 1)
            {
                br++;
            }
            if (a[j][i] == 0 && br < 3)
            {
                br = 0;
            }
        }
        if (br > 2)
        {
            kol++;
        }
    }
    // printf("KOL:%d\n",kol);
    printf("%d", red + kol);
    return 0;
}