#include <stdio.h>
int prostBroj(int x){
    for(int i=2;i<x;i++){
        if(x%i==0){
            return 0;
        }
    }
   return 1;
}
int main() {

    int a[100], n, b[100], b1 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i+=2) {
        b[b1] = (a[i] * 10) + a[i + 1];
        if(i==n-1){
            b[b1]=a[n-1];
            break;
        }
        b1++;
    }
    for (int i = 0; i <= b1; ++i) {
        if (prostBroj(b[i])) {
            printf("brojot %d e prost broj\n", b[i]);
        } else {
            printf("brojot %d NE e prost broj\n", b[i]);
        }
    }

}

