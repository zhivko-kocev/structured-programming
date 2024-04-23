#include <stdio.h>
int main(){
    int a[100][100],n,i,j,br=1,max=0,flag=1,prethoden;
    scanf("%d",&n);
    for (i = 0; i < n ; i++) {
        for (j = 0; j < n ; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (i = 0; i < n ; i++) {
        for (j = 0; j < n ; j++) {
            if(flag){
                prethoden=a[i][j];
                flag=0;
                continue;
            }
            if(a[i][j]>prethoden){
                br++;
            }
            if(max<br){
                max=br;
            }
            prethoden=a[i][j];
        }
        br=0;
    }
    printf("%d",max);
    return 0;
}
