#include <stdio.h>
/*
Од тастатура се читаат непознат број позитивни цели броеви се додека не се внесе
нешто различно од број. За секој број треба да се пресмета збирот на цифрата со
максимална вредност од претходно внесениот број  и сумата на цифрите на тековниот
број (за првиот внесен број се пресметува само сумата на неговите цифри). За секој
внесен број резултатот треба да се испечати во следниот формат:

[број]: [сумата на цифрите на бројот + максималната цифра од претходниот број]

342: 9   //3+4+2

345: 16 //3+4+5+4

123: 11 //1+2+3+5

456: 18 //4+5+6+3
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
int sumaNaCifri(int broj)
{
    int suma = 0, cifra;
    while (broj)
    {
        cifra = broj % 10;
        suma += cifra;
        broj /= 10;
    }
    return suma;
}
int main()
{
    int broj, flag = 1;
    while (scanf("%d", &broj))
    {
        int temp;
        if (flag)
        {
            temp = najglemaCifra(broj);
            printf("%d: %d\n", broj, sumaNaCifri(broj));
            flag = 0;
            continue;
        }

        printf("%d: %d\n", broj, sumaNaCifri(broj) + temp);
        temp = najglemaCifra(broj);
    }
    return 0;
}