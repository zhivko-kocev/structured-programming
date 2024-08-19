#include <stdio.h>
/*
Од стандарден влез се чита еден природен број n. Меѓу природните броеви помали
од n, да се најде оној чиј што збир на делителите е најголем.Во пресметувањето
на збирот на делителите на даден број, да не се зема предвид самиот број.
*/
int main()
{
    int n, br, delitel, suma, broj, max = 0;
    scanf("%d", &n);
    for (br = 2; br < n; br++)
    {
        suma = 0;
        for (delitel = 1; delitel < br; delitel++)
        {
            if (br % delitel == 0)
            {
                suma += delitel;
            }
        }
        if (max < suma)
        {
            max = suma;
            broj = br;
        }
    }
    printf("%d", broj);
    return 0;
}