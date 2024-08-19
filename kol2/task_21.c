#include <stdio.h>
#include <math.h>
/*
Од тастатура се чита природен број N (N < 400).
Да се напише програма којашто формира квадратна матрица што ги содржи броевите
од 1 до N по растечки редослед на следниот начин: во првата колона во правец од
горе надолу, па продолжува во втората колона од долу нагоре, па продолжува во
третата колона од горе надолу итн. Да се избере најмалата димензија на матрицата
во која ќе ги собере сите броеви до N. Доколку има преостанати празни места,
тие да се пополнат со нули.
Формираната матрица да се запише во датотека "shema.txt".
*/
void printFile()
{
    FILE *f = fopen("shema.txt", "r");
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

int main()
{
    int br, brojac = 1;
    scanf("%d", &br);
    int n = ceil(sqrt(br));
    int matrix[n][n];
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                if (brojac > br)
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    matrix[i][j] = brojac;
                    ++brojac;
                }
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; --i)
            {
                if (brojac > br)
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    matrix[i][j] = brojac;
                    ++brojac;
                }
            }
        }
    }
    FILE *f = fopen("shema.txt", "w");
    if (f == NULL)
    {
        printf("file could not be opened");
        return -1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fprintf(f, "%d ", matrix[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    printFile();
    return 0;
}