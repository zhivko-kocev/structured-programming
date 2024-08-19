#include <stdio.h>
int main(){
    int a[100],temp[100],br=0;
    for(int i=0;i<100;i++){
        if(scanf("%d",&a[i])){ br++; continue;}
        else{break;}
    }
    for(int i=0;i<br;i++){
        temp[i]=a[i];
    }
    for(int i=0;i<br;i++){
        for(int j=i+1;j<br;j++){
            if(temp[j]==a[i]){
                temp[j]+=j-i;
            }

        }
    }
    for (int i = 0; i < br; i++) {
        printf("%d ",temp[i]);

    }
}