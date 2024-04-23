#include <stdio.h>
int interesen(int n){
    while(n>10){
    if((n%10)%2==0){
        if(((n/10)%10)%2==0){
            return 0;
        }
    }
        if((n%10)%2!=0){
            if(((n/10)%10)%2!=0){
                return 0;
            }
        }
        n/=10;}
    return 1;
}
void printArray(int niza[],int n){
    if(n==0){return;}
    if(interesen(niza[n-1])){
        printf("%d\n",niza[n-1]);
    }
    printArray(niza,n-1);
}
int main(){
    int niza[100],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&niza[i]);
    }
    printArray(niza,n);

}