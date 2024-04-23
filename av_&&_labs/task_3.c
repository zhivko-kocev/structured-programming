#include <stdio.h>
int main(){
    int a[100],b[100],b1=0,a1=0,n,temp;

    scanf("%d",&n);
    for (int i = 0; i <n ; ++i) {
        scanf("%d",&a[i]);

    }
    for (int i = 0; i < n; ++i) {
        b[b1]=a[i];
        for (int j = i+1; j < n; ++j) {
            if(b[b1]==a[i]){
                b[b1]=a[i];
            }
        }
        ++i;
        b1++;

    }
    for (int i = 0; i < b1; ++i) {
        printf("%d",b[i]);

    }

}
