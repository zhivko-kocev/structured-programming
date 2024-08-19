#include <stdio.h>
#include <string.h>
/*
Четиринасочник претставува матрица во која се испишани зборови хоризонотално и
вертикално, одлево-надесно и оддесно-налево. Притоа секој елемент од матрицата
претставува буква од англиската азбука.

пример скриени зборови: HAIR, OLE (прецртани), FISH, TOE (подвлечени)

T H A I R E
E S N K N E
M I M J O L
M F S P S T
I F G E L O
X U T Y O E
Во датотеката input.txt е сместена квадратна матрица од знаци(3 <= n <= 50).
Во првиот ред е дефиниран бројот на редици (колони) на матрицата и во секој
преостанат ред е внесен еден ред од матрицата (види пример).
По читањето на матрицата, од стандарден влез се внесува збор составен од максимум 10 букви.

Ваша задача е да определите дали тој збор се наоѓа во четиринасочникот
(хоризонтално или вертикално, одлево-надесно или оддесно-налево).
Потребно е да се испечати локацијата (ред, колона) на првата и последната буква од зборот.
Доколку зборот повеќепати се наоѓа во четеринасочникот, треба да се испечати првото појавување,
гледано елемент по елемент како што се чита матрицата.

Доколку не се пронајде зборот, тогаш се печати Not Found.
*/
void wtf()
{
    FILE *f = fopen("input.txt", "w");

    int n, i, j;
    char el;
    scanf("%d", &n);

    fprintf(f, "%d\n", n);
    char a = getchar();

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            el = getchar();
            getchar();
            fprintf(f, "%c  ", el);
        }
        fputc('\n', f);
    }
    fclose(f);

    return;
}
int proveriLevo(char matrica[100][100], int z, int k, int dolzina, char *zbor, int *kraj1, int *kraj2)
{
    int b = 0;
    for (int i = k; i >= 0; --i)
    {
        if (matrica[z][i] != zbor[b])
        {
            return 0;
        }
        if (b == dolzina - 1)
        {
            *kraj1 = z;
            *kraj2 = i;
            return 1;
        }
        b++;
    }
    if (b != dolzina - 1)
    {
        return 0;
    }
}
int proveriDesno(int n, char matrica[100][100], int z, int k, int dolzina, char *zbor, int *kraj1, int *kraj2)
{
    int b = 0;
    for (int i = k; i < n; ++i)
    {
        if (matrica[z][i] != zbor[b])
        {
            return 0;
        }
        if (b == dolzina - 1)
        {
            *kraj1 = z;
            *kraj2 = i;
            return 1;
        }
        b++;
    }
    if (b != dolzina - 1)
    {
        return 0;
    }
}
int proveriGore(char matrica[100][100], int z, int k, int dolzina, char *zbor, int *kraj1, int *kraj2)
{
    int b = 0;
    for (int i = z; i >= 0; --i)
    {
        if (matrica[i][k] != zbor[b])
        {
            return 0;
        }
        if (b == dolzina - 1)
        {
            *kraj1 = i;
            *kraj2 = k;
            return 1;
        }
        b++;
    }
    if (b != dolzina - 1)
    {
        return 0;
    }
}
int proveriDole(int n, char matrica[100][100], int z, int k, int dolzina, char *zbor, int *kraj1, int *kraj2)
{
    int b = 0;
    for (int i = z; i < n; ++i)
    {
        if (matrica[i][k] != zbor[b])
        {
            return 0;
        }
        if (b == dolzina - 1)
        {
            *kraj1 = i;
            *kraj2 = k;
            return 1;
        }
        b++;
    }
    if (b != dolzina - 1)
    {
        return 0;
    }
}
int main()
{
    wtf();
    char zbor[11], matrica[100][100], momNiza[100];
    int size, dolzinaZbor, kraj1, kraj2, b = 0, levo, desno, gore, dole;
    scanf("%s", zbor);
    dolzinaZbor = strlen(zbor);
    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%d", &size);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            fscanf(f, " %c", &matrica[i][j]);
        }
    }
    fclose(f);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (matrica[i][j] == zbor[b])
            {
                if (proveriLevo(matrica, i, j, dolzinaZbor, zbor, &kraj1, &kraj2))
                {
                    printf("%d, %d -> %d, %d", i, j, kraj1, kraj2);
                    return 0;
                }
                if (proveriGore(matrica, i, j, dolzinaZbor, zbor, &kraj1, &kraj2))
                {
                    printf("%d, %d -> %d, %d", i, j, kraj1, kraj2);
                    return 0;
                }
                if (proveriDesno(size, matrica, i, j, dolzinaZbor, zbor, &kraj1, &kraj2))
                {
                    printf("%d, %d -> %d, %d", i, j, kraj1, kraj2);
                    return 0;
                }
                if (proveriDole(size, matrica, i, j, dolzinaZbor, zbor, &kraj1, &kraj2))
                {
                    printf("%d, %d -> %d, %d", i, j, kraj1, kraj2);
                    return 0;
                }
            }
        }
    }
    printf("Not found");
}
