#include <stdio.h>
int divisibleByK(int n,int k){
    if(n%k==0){return 1;}
    else{return 0;}
}
int nextDivisibleByK(int n,int k){
    if(divisibleByK(n+1,k)){return n+1;}
    return nextDivisibleByK(n+1,k);
}
int main(){
    int interval1,interval2,k;
    scanf("%d%d%d",&interval1,&interval2,&k);
    for(int i=interval1;i<=interval2;i++){
        printf("%d--->%d\n",i, nextDivisibleByK(i+1,k));
    }
}