#include <stdio.h>
int daliMoze(int a,int b,int c)
{
    if (a + b > c && a + c > b && b + c > a)
    return 1;
    else
        return 0;
}
int main()
{
    int n,a,b,c,perimetar,maxP=0,maxIndeks=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (daliMoze(a, b, c)) { printf("Moze\n");
            perimetar = a + b + c;
            if (perimetar > maxP)
            {
                maxP=perimetar;
                maxIndeks=i;
            }
        }
        else printf("Ne Moze\n");

    }
    printf("%d %d",maxP,maxIndeks);

    }

