#include <stdio.h>
int main (){
   int a[100][100],n,min,max;
    scanf("%d",&n);
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&a[i][j]);
        }

    }
    min=a[0][0];
    max=a[0][0];
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a[i][j]>max){
                max=a[i][j];
            }
            if(a[i][j]<min){
                min=a[i][j];
            }
        }

    }
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j){
                a[i][j]=max-min;
            }
        }

    }
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ",a[i][j]);
        }
        printf("\n");

    }

}