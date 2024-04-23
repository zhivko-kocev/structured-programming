#include <stdio.h>
#include <stdlib.h>
int main(){
    char c,prethodna,pocetok,kraj,flag=1,brojac=0,n;
    while (1)
    {
        scanf("%c",&c);
        if(c>='A'&&c<='Z'){
            break;
        }
        if(flag){
            prethodna=c;
            flag=0;
            continue;
        }
        if(abs(prethodna-c)!=1)
        {
            if(prethodna>c)
            {
                pocetok=c+1;
                kraj=prethodna-1;

            }else{
                pocetok=prethodna+1;
                kraj=c-1;
            }

        for(n=0;pocetok<=kraj;pocetok++,n++)
        {
            printf("%c",pocetok);

        }
        printf(" %d\n",n);
        brojac++;
        }
        prethodna=c;
    }
    printf("%d",brojac);
}