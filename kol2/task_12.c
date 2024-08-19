#include <stdio.h>
/*
Да се напише рекурзивна функција која ќе го најде бројот на позитивни броеви
од целобројна низа. Функцијата како аргумент ја прима низата, за која се бара
бројот на позитивни броеви и вкупниот број на елементи, кои ги има таа низа.
Функцијата е зададена со следниот прототип:
int BrojPozitivni(int niza[], int n);
Да се напише и функција main() за тестирање на функцијата BrojPozitivni.


*/
int BrojPozitivni(int niza[], int n);
int main()
{
    int niza[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &niza[i]);
    }
    printf("%d", BrojPozitivni(niza, n));
}
int BrojPozitivni(int niza[], int n)
{

    if (n < 0)
    {
        return 0;
    }
    if (niza[n - 1] < 0)
    {
        return 1 + BrojPozitivni(niza, n - 1);
    }
    else
    {
        return 0 + BrojPozitivni(niza, n - 1);
    }
}