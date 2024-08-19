#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c,prethoden,pocetok,kraj;
    int najmnogu=0,momentalno,flag=1;
    while(1) {
        scanf("%c",&c);
        if (c < 'a' || c > 'z') {
            break;
        }

        if (flag)
        {
            flag=0;
        }
        else
        {
            if(abs(prethoden-c!=0))
            {
                if(prethoden<c)
                {
                    pocetok=prethoden+1;
                    kraj=c-1;

                }
                else
                {
                    pocetok=c+1;
                    kraj=prethoden-1;
                }
                for(momentalno=0;pocetok<=kraj;pocetok++,momentalno++)
                    printf("%c",pocetok);
                printf("%d",momentalno);
                najmnogu++;
            }
        }
        prethoden=c;
    }
    printf("Vkupno :%d",najmnogu );
}