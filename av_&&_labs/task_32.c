#include <stdio.h>
int main(){
    int niza[100][100],n,red,kolona;
    scanf("%d",&n);
    if(n%2!=0){ printf("GRESKA");return 0;}
    for (red = 0; red < n ; red++) {
        for ( kolona = 0; kolona < n; kolona++) {
            scanf("%d",&niza[red][kolona]);
        }
    }
    for (red = 0; red < n ; red++) {
        for ( kolona = 0; kolona < n/2 ; kolona++) {
            niza[red][kolona]+=niza[red][n-1-kolona];
        }
    }
    for (red = 0; red < n/2 ; red++) {
        for ( kolona = 0; kolona < n ; kolona++){
            niza[red][kolona]+=niza[n-1-red][kolona];
        }
    }
    for (red = 0; red < n/2 ; red++) {
        for ( kolona = 0; kolona < n/2 ; kolona++) {
            printf("%d ",niza[red][kolona]);
        }
        printf("\n");
    }
    return 0;
}
