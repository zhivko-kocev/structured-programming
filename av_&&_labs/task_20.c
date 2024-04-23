#include <stdio.h>
int main(){
    int n,maxPerimeter=0,index;

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a+b>c&&b+c>a&&c+a>b)
        {printf("Moze\n");}
        else
        { printf("Ne moze\n");
            continue;}

        if(a+b+c>maxPerimeter)
        {
            maxPerimeter=a+b+c;
            index=i;
        }
    }
    printf("Najgolem perimetar: %d, reden broj %d",maxPerimeter,index);



}