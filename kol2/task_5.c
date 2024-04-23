#include <stdio.h>
#include <string.h>
/*
Дадена е текстуална датотека (livce.txt) која претставува ливче во спортска обложувалница.
На почетокот во датотеката, во посебен ред е запишана сумата на уплата (цел број).
Потоа во секој ред од датотеката е запишан по еден тип во следниот формат:
ab12 1 1.25
Првиот број е шифрата на типот (низа од знаци која не е подолга од 9 знаци),
вториот број е типот (може да биде 1, 0 или 2) додека третиот број е коефициентот (реален број).
Ваша задача е да се испечати типот со најголем коефициент како и можната добивка
на ливчето. Доколку има повеќе типови со ист максимален коефициент, да се испечати првиот.
Можната добивка се пресметува како производ на сите коефициенти со сумата на уплата.
*/
void wf()
{
    FILE *f = fopen("livce.txt", "w");
    char c;
    while ((c = getchar()) != '#')
    {
        fputc(c, f);
    }
    fclose(f);
}

int main()
{
    wf();
    FILE *f = fopen("livce.txt", "r");
    char sifra[10], maxSifra[10];
    int tip, uplata, maxTip;
    float kvota, maxKvota = 0, vkupno = 1;
    fscanf(f, "%d", &uplata);
    while (fscanf(f, "%s%d%f", sifra, &tip, &kvota) != EOF)
    {
        if (kvota > maxKvota)
        {
            maxKvota = kvota;
            maxTip = tip;
            strcpy(maxSifra, sifra);
        }
        vkupno *= kvota;
    }
    printf("%s %d %.2lf\n%.2lf", maxSifra, maxTip, maxKvota, vkupno * (float)uplata);

    return 0;
}