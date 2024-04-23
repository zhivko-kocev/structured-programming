#include <stdio.h>
int main(){
    int casovi,minuti,sekundi,c2;
    scanf("%d%d%d",&casovi,&minuti,&sekundi);
    c2=casovi;
if(casovi>12){
    casovi-=12;
}
if(casovi==12){
    casovi=12;
}
if(casovi==0){
    casovi=12;
}
printf("%02d:%02d:%02d",casovi,minuti,sekundi);
if(c2>12){
    printf("PM");
}
if(c2==12){
    printf("NOON");

}
if(c2<12){
    printf("AM");
}
}