#include <stdio.h>
/*
Благ број е број што е составен само од парни цифри (0, 2, 4, 6, 8).
Во зададен опсег (почетокот m и крајот на опегот n се цели броеви чија
вредност се внесува од тастатура), да се најде и испечати најмалиот „благ број“.
 Ако не постои таков број, да се испечати NE.
*/

int daliEblag(int broj)
{
    while (broj != 0)
    {
        if ((broj % 10) % 2 != 0)
        {
            return 0;
        }

        broj /= 10;
    }
    return 1;
}
int main()
{
    int p, k, a;
    scanf("%d%d", &p, &k);
    for (int i = p; p <= k; p++)
    {
        if (daliEblag(i) == 1)
        {
            printf("%d\n", i);
            a = 1;
            break;
        }
    }
    if (a != 1)
        printf("NE");
}
