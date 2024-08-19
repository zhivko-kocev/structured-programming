#include <stdio.h>
/*
Од тастатура се внесуваат димензиите m и n на матрица од цели броеви, Аmxn,
( 0 < m, n < 30 ) и нејзините елементи. Потоа се внесуваат два цели броја r и k
(индекси на редица/колона од матрицата, т.е. 0 <= r < m и 0 <= k < n).
Да се напише програма која ja трансформира матрицата А така што елементите над
редицата r и лево од колоната k се заменуваат со минималната вредност од матрицата А.
Новодобиената матрица да се запише во датотека "matrica.txt".
*/
void printFile()
{
    FILE *f = fopen("matrica.txt", "r");
    char line[1000];
    while (!feof(f))
    {
        fgets(line, 1000, f);
        if (feof(f))
            break;
        printf("%s", line);
    }
    fclose(f);
}
void transform(int m, int n, int r, int k, int matrica[m][n], int min)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < r && j < k)
            {
                matrica[i][j] = min;
            }
        }
    }
}

int main()
{
    int m, n, r, k, matrica[100][100], min;
    scanf("%d%d", &m, &n);
    scanf("%d%d", &r, &k);
    if (m < 0 || n > 30)
    {
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrica[i][j]);
        }
    }
    min = matrica[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrica[i][j] < min)
            {
                min = matrica[i][j];
            }
        }
    }
    transform(m, n, r, k, matrica, min);
    FILE *f = fopen("matrica.txt", "w");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(f, "%d ", matrica[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    printFile();
    return 0;
}