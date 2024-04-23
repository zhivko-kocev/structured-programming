#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Во рамките на текстуална датотека matrica.txt се сместени елементите
(целобројни вредности) од една матрица (A). Во првиот ред од датотеката се
запишани бројот на редици n и бројот на колони m на матрицата (n, m < 120).
Потоа, во секој ред од датотеката се запишани елементите од соодветната редица
на матрицата.
Да се испечати колку индексни броеви има во секоја колона поединечно.
Индексен број е број чија вредност е идентична со вредноста што се добива со
спојување на индексот од редицата и колоната на елементот.
*/
void wtf()
{
    FILE *f = fopen("matrica.txt", "w");
    char c;
    while ((c = getchar()) != '#')
    {
        fputc(c, f);
    }
    fclose(f);
}
int indeksenElement(int br1, int br2)
{
    char broj1[20], broj2[20];
    sprintf(broj1, "%d", br1);
    sprintf(broj2, "%d", br2);
    strcat(broj1, broj2);
    int broj = atoi(broj1);
    return broj;
}
int main()
{
    wtf();
    FILE *file = fopen("matrica.txt", "r");
    int m, n, matrica[500][500], vkupnoIndeksni = 0;
    fscanf(file, "%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fscanf(file, "%d", &matrica[i][j]);
        }
    }
    for (int j = 0; j < n; ++j)
    {
        vkupnoIndeksni = 0;
        for (int i = 0; i < m; ++i)
        {
            if (indeksenElement(i, j) == matrica[i][j])
            {
                vkupnoIndeksni++;
            }
        }
        printf("%d\n", vkupnoIndeksni);
    }
    return 0;
}
