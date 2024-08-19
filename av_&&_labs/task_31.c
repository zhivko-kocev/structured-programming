#include <stdio.h>
#include <math.h>
int main(){
    int a[100][100],n,m,j,i,min1,max1;
    float b[100][100];
    scanf("%d%d",&n,&m);
    for (i = 0; i < n ; i++) {
        for ( j = 0; j < m ; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for ( j = 0; j < m ; j++) {
        max1=a[0][j];
        min1=a[0][j];
        for ( i = 0; i < n ; i++) {
            if(a[i][j]>max1){max1=a[i][j];}
            if(a[i][j]<min1){min1=a[i][j];}
        }
            for (int p = 0; p < n; ++p) {
                b[p][j]=(float)(a[p][j]-min1)/(max1-min1);

            }


    }
    for (i = 0; i < n ; i++) {
        for ( j = 0; j < m ; j++) {
            printf("%.2f ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
