#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
Во рамките на текстуална датотека matrica.txt се сместени елементите од една
матрица (A), составена од природни броеви. Во првиот ред од датотеката се
запишани бројот на редици N и бројот на колони M на матрицата (N, M < 100).
Потоа, во секој ред од датотеката се запишани елементите од соодветната редица
на матрицата.
За секоја редица, да се испечати индексот на редицата и бројот на штосни броеви
во таа редица во формат indeks_na_redica: broj_na_stosni_broevi_vo_taa_redica
(види тест пример).
Штосен број е број чија парност е иста со парноста на збирот од индексите на
редицата и колоната на елементот.
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

int main()
{
    wtf();
    int n, m, matrica[100][100];
    FILE *f = fopen("matrica.txt", "r");
    fscanf(f, "%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            fscanf(f, "%d", &matrica[i][j]);
        }
    }
    fclose(f);
    for (int i = 0; i < n; ++i)
    {
        int brStosni = 0;
        for (int j = 0; j < m; ++j)
        {
            if ((matrica[i][j] % 2 == 0 && (i + j) % 2 == 0) || (matrica[i][j] % 2 != 0 && (i + j) % 2 != 0))
            {
                brStosni++;
            }
        }
        printf("%d : %d\n", i, brStosni);
    }
    return 0;
}
