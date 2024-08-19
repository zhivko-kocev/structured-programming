#include <stdio.h>
int main(){
int n;
scanf("%d",&n);
    int br=n-1;
    for(int i=1;i<=2*n-1;i++){
    for(int j=1;j<=n;j++){
        if(i>1&&j==1){
            printf("|");
        }
        if(i%2!=0&&j<=(n-br)){
        printf("* ");
        }
    }
        if(i%2==0){
            br--;
        }
        printf("\n");
}
}
