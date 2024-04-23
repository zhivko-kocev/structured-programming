#include <stdio.h>
int sumaCifri(int n){
    if(!n) return 0;
    return n%10 + sumaCifri(n/10);

}
int rastecki(int n){
   while(n){
       if((n%10)<=(n/10)%10){
           return -1;
       }
       n/=10;
   }
   return 1;

}
void printajBr(int br[],int n){
    for(int i=0;i<n;i++){
        if(rastecki(br[i])==1){
            printf("%d(suma:%d)\n",br[i], sumaCifri(br[i]));
        }
    }

}
int main(){
    int n,br[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&br[i]);
    }
    printajBr(br,n);


}