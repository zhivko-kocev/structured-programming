
#include <stdio.h>
int obraten(int n){
    int obr=0;
    while(n){
        obr*=10;
        obr+=(n%10);
        n/=10;
    }
    return obr;

}
int palindrom(int n){
    if(n== obraten(n)){return 1;}
    else{return 0;}

}
int cifri(int n){
    int c=n%10;
    if(!n){return 1;}
    if(c==0||c==1||c==2||c==3||c==4){
        return cifri(n/10);
    }
    else return 0;
}
int main(){
    int interval1,interval2;
    scanf("%d%d",&interval1,&interval2);
    for(int i=interval1;i<=interval2;i++){
        if(palindrom(i)&& cifri(i)){
            printf("%d\n",i);
        }
    }


}
