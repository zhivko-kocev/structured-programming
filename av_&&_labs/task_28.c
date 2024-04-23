/*U niza ako elemenot e paren da se zgoleme za 1 ako e neparen da se namale
 * za 1 i posle da ja ispecates taa niza*/
#include <stdio.h>

int main ()
{
    int a[100],n,k,b[100],b1=0;
    scanf("%d",&n);
    for( int i = 0;i<n;i++)
    {scanf("%d",&a[i]);}
    scanf("%d",&k);
    for (int i = 0; i < n; ++i) {
        if(a[i]<k&&a[i]){
            b[b1]=a[i];
            b1++;
        }

    }
    for (int i = 0; i <n ; ++i) {
        if(a[i]>=k){
            b[b1]=a[i];
            b1++;
        }
    }

    for(int i=0;i<n;i++)
    {printf("%d ",b[i]);}
}