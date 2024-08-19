#include <stdio.h>
#include <math.h>
/*
Од тастатура се внесуваат димензиите на една матрица (m, n <= 100), а потоа и
елементите од матрицата. Да се генерира низа (со најмногу m) така што секој
елемент од низата се добива со наоѓање на елементот во секоја редица од матрицата
што е најоддалечен од аритметичката средина во рамки на таа редица. Ако постојат
повеќе елементи што се најоддалечени од аритметичката средина, тогаш се зема
предвид првиот. Редоследот на запишување на елементите во низата одговара на
редоследот на редиците.
*/
int main()
{
    int m, n, i, niza[100];
    float matrica[100][100], aSredina, br;
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%f", &matrica[i][j]);
        }
    }
    for (i = 0; i < m; ++i)
    {
        float sum = 0;
        for (int j = 0; j < n; ++j)
        {
            sum += matrica[i][j];
        }
        aSredina = sum / (float)n;
        float max = fabsf(matrica[i][0] - aSredina);
        br = matrica[i][0];
        for (int z = 1; z < n; ++z)
        {
            if (max < fabsf(matrica[i][z] - aSredina))
            {
                br = matrica[i][z];
                max = fabsf(matrica[i][z] - aSredina);
            }
        }
        niza[i] = br;
    }
    for (int j = 0; j < m; ++j)
    {
        printf("%d", niza[j]);
    }
}