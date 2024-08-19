#include <stdio.h>
int paren(int n){
    if(n%2==0){return 1;}
    else {return 0;}
}
int promenaBr(int n){
    if(!n) return 0;
    int c=n%10;
    if(paren(c)){c=0;}
    else{c-=1;}
    return c+10* promenaBr(n/10);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("Brojot e: %d", promenaBr(n));
}