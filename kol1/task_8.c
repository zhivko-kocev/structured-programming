#include <stdio.h>
/*
Од стандарден влез се внесуваат два цели броја N и Х.
Да се најде најблискот број помал од N коj е тотално различен од бројот Х.
Еден број е тотално различен од друг ако и само ако во него не се појавува
ниту една од цифрите на другиот број.Задачата да се реши без употреба на
низи и матрици.
*/
int totalnoRazlicen(int broj1, int broj2)
{
    int flag = 1;
    while (broj1 > 0)
    {
        int temp = broj2;
        while (temp > 0)
        {
            if (broj1 % 10 == temp % 10)
            {
                flag = 0;
                return flag;
            }
            else
                temp /= 10;
        }
        broj1 /= 10;
    }
    return flag;
}
int main()
{
    int N, X, i;
    scanf("%d%d", &N, &X);
    for (i = N - 1; i > 0; i--)
    {
        if (totalnoRazlicen(i, X))
        {
            printf("%d", i);
            return 0;
        }
        else
            printf("0");
    }
}
