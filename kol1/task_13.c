#include <stdio.h>
/*
Од тастатура се внесува број на студенти кои ќе полагаат колоквиум, а потоа и
индексите (цели броеви) на сите студенти кои ќе полагаат колоквиум. Програмата
треба да ги подели студентите во три групи: студенти со индекси кои завршуваат на
цифрата 0, 1 и 2, студенти со индекси кои завршуваат на цифрата 3, 4, 5 и студенти
со индекси кои завршуваат на цифрата 6, 7, 8, 9. Програмата треба да ги испечати
индексите за секоја група, во истиот редослед како што биле внесени. Максималниот
број на студенти што може да се внесат е 1000.

Напомена: Оваа задача е за материјалот наменет за втор колоквиум и истата се решава со користење на низи.
*/
int main()
{
    int studenti[1000], brStudenti, grupa1[300], grupa2[300], grupa3[300], b1 = 0, b2 = 0, b3 = 0;
    scanf("%d", &brStudenti);
    for (int i = 0; i < brStudenti; i++)
    {
        scanf("%d", &studenti[i]);
    }
    for (int i = 0; i < brStudenti; i++)
    {
        if (studenti[i] % 10 == 1 || studenti[i] % 10 == 2 || studenti[i] % 10 == 0)
        {
            grupa1[b1] = studenti[i];
            b1++;
        }
        if (studenti[i] % 10 == 3 || studenti[i] % 10 == 4 || studenti[i] % 10 == 5)
        {
            grupa2[b2] = studenti[i];
            b2++;
        }
        if (studenti[i] % 10 == 6 || studenti[i] % 10 == 7 || studenti[i] % 10 == 8 || studenti[i] % 10 == 9)
        {
            grupa3[b3] = studenti[i];
            b3++;
        }
    }
    printf("Grupa 1\n");
    for (int i = 0; i < b1; i++)
    {
        printf("%d ", grupa1[i]);
    }
    printf("\n");
    printf("Grupa 2\n");
    for (int i = 0; i < b2; i++)
    {
        printf("%d ", grupa2[i]);
    }
    printf("\n");
    printf("Grupa 3\n");
    for (int i = 0; i < b3; i++)
    {
        printf("%d ", grupa3[i]);
    }
    return 0;
}