#include <string.h>
#include <stdio.h>
#include <ctype.h>
int broiSvrznici(char *niza){
    int brojac = 0,brojBukvi=0;
    for (int i = 0; i < strlen(niza); ++i) {
        if(isalpha(niza[i])){
            brojBukvi++;
        }else{
            if(brojBukvi<=3&&brojBukvi>0){
                brojac++;
                brojBukvi=0;
            }else{
                brojBukvi=0;
            }
        }
    }
    return brojac;
}

int main (){
    char niza[100],maxniza[100];
    int maxDolzina=0;
    while (fgets(niza,100,stdin)){
        if(broiSvrznici(niza)>maxDolzina){
            maxDolzina= broiSvrznici(niza);
            strcpy(maxniza,niza);
        }
    }
    printf("%d: ",maxDolzina);
    puts(maxniza);
    return 0;
}