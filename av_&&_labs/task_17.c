//Да се напише програма, каде што за даден број N внесен преку тастатура, ќе испечати: "Tik" доколку е делив со 3,
// "Tak" доколку е делив со 5, "Tik - Tak" доколку е делив со 3 и со 5.
//Доколку бројот не е делив со 3 ни со 5, тогаш да се испечати "Losh Broj". (Без наводници, ставени се за читливост)

#include <stdio.h>
int main ()
{
    int broj;
    scanf("%d",&broj);
    (broj%3==0&&broj%5==0)? printf("Tik - Tak"):(broj%3==0&&broj%5!=0)?
    printf("Tik"):(broj%3!=0&&broj%5==0)? printf("Tak"): printf("Losh Broj");


}