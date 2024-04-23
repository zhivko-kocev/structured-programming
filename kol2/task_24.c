#include <stdio.h>
#include <math.h>
/*
Еден елемент се заматува ако се најде аритметичка средина на елементот и сите
негови соседи. Сосед на еден елемент се сите елементи кои припаѓаат на матрицата
и се  околу истиот елемент (хоризонтално, вертикално и дијагонално).
Во датотеката input.txt е сместена матрица од реални броеви (3 < n,m < 50).
Во првиот ред се дефинирани бројот на редици и колони на матрицата и во секој
преостанат ред е внесен еден ред од матрицата (види пример).По читањето на
матрицата, од стандарден влез се внесуваат и 2 пара координати на матрицата
(ред и колона) кои го репрезентираат горниот-лев и долниот-десен елемент од
регионот. Потребно е да генеирате нова матрица во која ќе ги заматите сите
елементи кои припаѓаат на регионот.
Новодобиената матрица, во истиот формат, треба да се запише во датотеката output.txt.
*/

#define MAX 50

void printFile()
{

    FILE *f = fopen("output.txt", "r");
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
void wtf()
{
    FILE *f = fopen("input.txt", "w");

    int row, column, i, j;
    float el;
    scanf("%d %d", &row, &column);

    fprintf(f, "%d %d\n", row, column);

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < column; ++j)
        {
            scanf("%f", &el);
            fprintf(f, "%.2f ", el);
        }
        fputc('\n', f);
    }
    fclose(f);

    return;
}
double aritmetickaSredina(double matrica[100][100], int m, int n, int i, int j)
{
    double sum = 0;
    if (i == 0 && j == 0)
    {
        sum = matrica[i][j] + matrica[i][j + 1] + matrica[i + 1][j] + matrica[i + 1][j + 1];
        sum /= 4;
    }
    // levo gore kjos
    else if (i == 0 && j == n - 1)
    {
        sum = matrica[i][j] + matrica[i][j - 1] + matrica[i + 1][j] + matrica[i + 1][j - 1];
        sum /= 4;
    }
    // desno gore kjos
    else if (i == m - 1 && j == 0)
    {
        sum = matrica[i][j] + matrica[i - 1][j] + matrica[i][j + 1] + matrica[i - 1][j + 1];
        sum /= 4;
    }
    // levo dole kjos
    else if (i == m - 1 && j == n - 1)
    {
        sum = matrica[i][j] + matrica[i - 1][j] + matrica[i][j - 1] + matrica[i - 1][j - 1];
        sum /= 4;
    }
    // desno dole kjos
    else if (i == 0 && (j > 0 && j < n - 1))
    {
        sum = matrica[i][j] + matrica[i][j + 1] + matrica[i][j - 1] + matrica[i + 1][j] +
              matrica[i + 1][j + 1] + matrica[i + 1][j - 1];
        sum /= 6;
    }
    // gorna strana
    else if (i == m - 1 && (j > 0 && j < n - 1))
    {
        sum = matrica[i][j] + matrica[i][j + 1] + matrica[i][j - 1] + matrica[i - 1][j] +
              matrica[i - 1][j - 1] + matrica[i - 1][j + 1];
        sum /= 6;
    }
    // dolna strana
    else if (j == 0 && (i > 0 && i < m - 1))
    {
        sum = matrica[i][j] + matrica[i][j + 1] + matrica[i - 1][j] + matrica[i + 1][j] +
              matrica[i + 1][j + 1] + matrica[i - 1][j + 1];
        sum /= 6;
    }
    // leva strana
    else if (j == n - 1 && (i > 0 && i < m - 1))
    {
        sum = matrica[i][j] + matrica[i][j - 1] + matrica[i - 1][j] + matrica[i + 1][j] +
              matrica[i + 1][j - 1] + matrica[i - 1][j - 1];
        sum /= 6;
    }
    // desna strana
    else
    {
        sum = matrica[i][j] + matrica[i][j + 1] + matrica[i][j - 1] + matrica[i + 1][j] + matrica[i - 1][j] +
              matrica[i + 1][j + 1] + matrica[i + 1][j - 1] + matrica[i - 1][j + 1] + matrica[i - 1][j - 1];
        sum /= 9;
    }
    return sum;
}

int main()
{
    wtf();
    FILE *f = fopen("input.txt", "r");
    double matrica[100][100], matricab[100][100];
    int m, n, xkoordinat1, ykoordinat1, xkoordinat2, ykoordinat2;
    fscanf(f, "%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fscanf(f, "%lf", &matrica[i][j]);
        }
    }
    fclose(f);
    scanf("%d%d", &xkoordinat1, &ykoordinat1);
    scanf("%d%d", &xkoordinat2, &ykoordinat2);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matricab[i][j] = matrica[i][j];
        }
    }
    for (int i = xkoordinat1; i <= xkoordinat2; ++i)
    {
        for (int j = ykoordinat1; j <= ykoordinat2; ++j)
        {
            matricab[i][j] = aritmetickaSredina(matrica, m, n, i, j);
        }
    }
    FILE *kraj = fopen("output.txt", "w");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fprintf(f, "%.2lf ", matricab[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(kraj);
    printFile();
    return 0;
}