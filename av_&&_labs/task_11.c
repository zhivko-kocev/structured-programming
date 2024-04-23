#include <stdio.h>
#include <string.h>
int brPojavuvanja(char *a,char c){
    int brojac=0;
    for (int i = 0; i < strlen(a); ++i) {
        if(a[i]==c){brojac++;}
    }
    return brojac;
}
int main(){
    int n,k,brojac=0;
    char red[100],c;
    scanf("%d %d",&n,&k);
    scanf(" %c\n",&c);
    for (int i = 0; i < n; ++i) {
        fgets(red,100,stdin);
        if(brPojavuvanja(red,c)==k){
            puts(red);
            brojac++;
        }
    }
    if(!brojac){ printf("NONE");}
    return 0;
}