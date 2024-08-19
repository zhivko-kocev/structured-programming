#include <stdio.h>
/*
Од тастатура се читаат непознат број на позитивни цели броеви (со максимум 5 цифри)
се додека не се внесе нешто различно од број. За секој број треба да се најде
позицијата (од десно на лево) на првото појавување на најголемата цифра во
составот на бројот (цифрата на единици се наоѓа на позиција 0). Потоа, да се
испечати статистика за позициите на најдените цифри со максимална вредност во
следниот формат:

[позиција]: [вкупно броеви чија максимална цифра се наоѓа на таа позиција]

0: 2

1: 3

2: 1

3: 1

4: 1


за броевите 97654 48654 12345 12343 1263 12443 12643 12777
*/
int najglemaCifra(int broj)
{
    int max = 0;
    while (broj)
    {
        if (broj % 10 > max)
        {
            max = broj % 10;
        }
        broj /= 10;
    }
    return max;
}
int mestoNaCifra(int broj)
{
    int brojac = 0;
    while (broj)
    {

        if (najglemaCifra(broj) == broj % 10)
        {
            break;
        }
        brojac++;
        broj /= 10;
    }

    return brojac;
}

int main()
{
    int broj, brojac0 = 0, brojac1 = 0, brojac2 = 0, brojac3 = 0, brojac4 = 0;
    while (scanf("%d", &broj))
    {
        if (broj < 99999)
        {
            if (mestoNaCifra(broj) == 0)
                brojac0++;
            if (mestoNaCifra(broj) == 1)
                brojac1++;
            if (mestoNaCifra(broj) == 2)
                brojac2++;
            if (mestoNaCifra(broj) == 3)
                brojac3++;
            if (mestoNaCifra(broj) == 4)
                brojac4++;
        }
    }
    printf("0: %d\n"
           "1: %d\n"
           "2: %d\n"
           "3: %d\n"
           "4: %d",
           brojac0, brojac1, brojac2, brojac3, brojac4);
    return 0;
}