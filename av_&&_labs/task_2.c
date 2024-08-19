#include <stdio.h>
int faktoriel(int n){
    if(n==1)return 1;
    return n*faktoriel(n-1);
}
int suma(int k){
    int s=0;
    for(int i=1;i<=k;i++){
        s+=i;
    }
    return s;
}
int main(){
    int k,rez=0;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        rez+= faktoriel(suma(i));
    }
    printf("%d",rez);
}