#include <stdio.h>
#include <stdlib.h>
/*
Цик-цак е број за кој што важи дека за секој пар соседни цифри,
тие се наизменично поголеми односно помали една во однос на друга.
На пример, ако бројот x е составен од цифрите a, b, c, d и е, тогаш за нив важи:
a>b, b<c, c>d, d<e или a<b, b>c, c<d, d>e
Пр. 343, 4624, 6231209
Од тастатура се читаат непознат број цели броеви поголеми од или еднакви на
10 (броевите помали од 10 се игнорираат). Читањето завршува во моментот кога ќе
се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.
*/
int main()
{

    int n, x, y, pogolemo, pomalo, tmp, br, i, j;
    while (scanf("%d", &n))
    {
        tmp = n;
        if (n < 10)
        {
            continue;
        }
        i = n % 10;
        j = (n / 10) % 10;
        br = 1;
        if (i < j)
        {
            pomalo = 1;
            pogolemo = 0;
            while (n > 9)
            {
                x = n % 10;
                y = (n / 10) % 10;
                if (pomalo)
                {
                    if (x < y)
                    {
                        pogolemo = 1;
                        pomalo = 0;
                        n /= 10;
                        continue;
                    }
                    else
                    {
                        br = 0;
                        break;
                    }
                }
                if (pogolemo)
                {
                    if (x > y)
                    {
                        pogolemo = 0;
                        pomalo = 1;
                        n /= 10;
                        continue;
                    }
                    else
                    {
                        br = 0;
                        break;
                    }
                }
            }
        }
        if (i > j)
        {
            pogolemo = 1;
            pomalo = 0;
            while (n > 9)
            {
                x = n % 10;
                y = (n / 10) % 10;
                if (pogolemo)
                {
                    if (x > y)
                    {
                        pogolemo = 0;
                        pomalo = 1;
                        n /= 10;
                        continue;
                    }
                    else
                    {
                        br = 0;
                        break;
                    }
                }
                if (pomalo)
                {
                    if (x < y)
                    {
                        pogolemo = 1;
                        pomalo = 0;
                        n /= 10;
                        continue;
                    }
                    else
                    {
                        br = 0;
                        break;
                    }
                }
            }
        }
        if (br && i != j)
        {
            printf("%d\n", tmp);
        }
    }
    return 0;
}