#include <stdio.h>
int main() {
    int koordinat1A,koordinat2A,koordinat1C,koordinat2C;
    int x,y;
    scanf("%d%d\n",&koordinat1A,&koordinat2A);
    scanf("%d%d\n",&koordinat1C,&koordinat2C);
    for(int i=1;i<=2;i++){
        scanf("%d%d",&x,&y);
        if(x>=koordinat1A&&x<=koordinat1C){
            if(y>=koordinat2A&&y<=koordinat2C){
                printf("DA\n");

            }
        }else {printf("NE\n");

    }
}