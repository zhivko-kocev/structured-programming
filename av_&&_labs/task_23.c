#include <stdio.h>
int main(){
    int broj,m,prethoden,flag=1,brojac=1,brojacCifri,temp,brojacPrethoden;
    scanf("%d",&m);
    while (scanf("%d",&broj)){

        brojacCifri=0;
        temp=broj;
        while (temp){

            brojacCifri++;
            temp/=10;
        }

        if(flag){
            prethoden=broj;
            brojacPrethoden=brojacCifri;
            flag=0;
            continue;
        }
        if(prethoden<broj&&brojacPrethoden==m && brojacCifri==m){
            brojac++;
        }
        else {
            if(brojac>=2) {
                printf("%d ", brojac);
                brojac = 1;
            }
        }
        prethoden=broj;
        brojacPrethoden=brojacCifri;
    }
    if(brojac>=2) {
        printf("%d", brojac);
    }

}