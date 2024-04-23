#include <stdio.h>
int main()
{
    int p1, p2, p3, c1, c2, A,i,vkupno=0;
    scanf("%d%d%d%d%d\n",&p1,&c1,&p2,&c2,&p3);
    for(i=1;i<4;i++)
    {
        scanf("%d",&A);

    int poeni=0;
    while(A>0)
    {
        if(A<=c1&&A>0)
        {poeni=A*p1; vkupno+=poeni;break;}
        if(A<=c2 && A>c1)
        {poeni=A*p2;vkupno+=poeni;break;}
        if(A>c2)
        {poeni=A*p3;vkupno+=poeni;break;}
    }
        }
    printf("%d",vkupno);

    return 0;
}