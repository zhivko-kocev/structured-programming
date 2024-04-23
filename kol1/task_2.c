#include <stdio.h>
/*
Eден природен e „интересен“ ако неговиот обратен број е делив со неговиот број
на цифри. Обратен број е бројот составен од истите цифри, но во обратен редослед
(на пример, 653 е обратен број на бројот 356). Од тастатура се внесува природен
број n ( n > 9). Да се најде и отпечати најголемиот природен број помал од n кој
што е „интересен“. Ако внесениот број не е валиден, да се отпечати соодветна
порака (Brojot ne e validen).
*/
int obraten(int n)
{
    int a = n;

    int obr = a % 10;
    while (a > 0)
    {
        a /= 10;
        obr *= 10;
        obr += (a % 10);
    }
    return obr;
}
int brCifri(int n)
{
    int a = n;

    int brojac = 0;
    while (a > 0)
    {
        brojac += 1;
        a /= 10;
    }
    return brojac;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n > 9)
    {
        for (int i = n - 1; i > 0; i--)

        {
            if (obraten(i) % brCifri(i) == 0)
                printf("%d", obraten(i));
            break;
        }
    }
    else
        printf("Brojot ne e validen");
    return 0;
}