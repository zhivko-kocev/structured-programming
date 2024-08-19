#include <stdio.h>
/*
Цик-цак е број за кој важи дека за секој пар соседни цифри во бројот важи дека
едната е помала од 5, а другата е поголема или еднаква на 5. На пример, ако
бројот x е составен од цифрите a, b, c и d, тогаш за нив важи:
a<5, b>=5, c<5, d>=5 или a>=5, b<5, c>=5, d<5
Пр.  508294, 2638, 81
Од тастатура се читаат непознат број на цели броеви поголеми од или еднакви на
10 (броевите помали од 10 се игнорираат). Читањето завршува во моментот кога ќе
се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.
*/
int main()
{

    int n, x, pogolemo, pomalo, tmp, br, i, j;
    while (scanf("%d", &n))
    {
        tmp = n;
        if (n < 10)
        {
            continue;
        }
        i = n % 10;
        br = 1;
        if (i < 5)
        {
            pomalo = 1;
            pogolemo = 0;
            while (n)
            {
                x = n % 10;
                if (pomalo)
                {
                    if (x < 5)
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
                    if (x >= 5)
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
        if (i >= 5)
        {
            pogolemo = 1;
            pomalo = 0;
            while (n)
            {
                x = n % 10;
                if (pogolemo)
                {
                    if (x >= 5)
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
                    if (x < 5)
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
        if (br)
        {
            printf("%d\n", tmp);
        }
    }
    return 0;
}