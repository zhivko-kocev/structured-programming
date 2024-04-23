#include <stdio.h>
void sort(int *a,int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(*(a+i)>*(a+j))
            {
                int temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
}
int main(){
    int n,niza[100];
    scanf("%d",&n);
    for (int i = 0; i < n ; i++) {
        scanf("%d",&niza[i]);
    }
    sort(niza,n);
    printf("\n");
    for (int i = 0; i < n ; i++) {
        printf("%d ",niza[i]);
    }

}