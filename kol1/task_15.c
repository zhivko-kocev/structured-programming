#include <stdio.h>
/*
Од тастатура се внесува колку студенти полагале колоквиум и потоа се внесуваат
поените на сите кои полагале. Програмата треба да отпечати средна вредност на
поените на сите студенти кои имале помалку од 50 поени, како и список на
студентите со повеќе од 50 поени. Исто така програмата да отпечати средна вредност
на поените на сите кои положиле со најмалку 50 поени и нивните освоени поени
(редоследот на печатење во двата случаеви треба да биде ист како и редоследот на
внесување). Максималниот број на студенти што може да се внесат е 1000.

Напомена: Оваа задача е за материјалот наменет за втор колоквиум и истата се решава со користење на низи.
*/
int main()
{
    int studenti[1000], brStudenti, polozeni[500], padnati[500], b1 = 0, b2 = 0, sumPadnati = 0, sumPolozeni = 0;
    scanf("%d", &brStudenti);
    for (int i = 0; i < brStudenti; i++)
    {
        scanf("%d", &studenti[i]);
    }
    for (int i = 0; i < brStudenti; i++)
    {
        if (studenti[i] >= 50)
        {
            polozeni[b1] = studenti[i];
            sumPolozeni += studenti[i];
            b1++;
        }
        else
        {
            padnati[b2] = studenti[i];
            sumPadnati += studenti[i];
            b2++;
        }
    }
    printf("Sredna vrednost na padnati %.2f\n", (float)sumPadnati / b2);
    for (int i = 0; i < b2; i++)
    {
        printf("%d ", padnati[i]);
    }
    printf("\n");
    printf("Sredna vrednost na polozeni %.2f\n", (float)sumPolozeni / b1);
    for (int i = 0; i < b1; i++)
    {
        printf("%d ", polozeni[i]);
    }
}