#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Од тастатура се внесува цел број M, а потоа M низи од цели броеви.
За секоја низа прво се внесува бројот на елементи во низата N (N<=100), а потоа
и елементите на низата.
Секоја од внесените низи треба да се трансформира според следново правило:
Ако првиот елемент од низата е позитивен број, тоа значи сите елементи од низата
(вклучувајќи го и првиот) да се поместат за онолку места во десно, колку што е
вредноста на елементот, празнините што ќе настанат во низата да се пополнат со
елементи со вредност нула.
Ако првиот елемент од низата е негативен број, тоа значи сите елементи од низата
(вклучувајќи го и првиот) да се поместат за онолку места во лево, колку што е
вредноста на елементот, празнините што ќе настанат во низата да се пополнат со
елементи со вредност нула.
При поместување на елементите, бројот на елементите во низата останува непроменет.
На крајот да се испечатат трансформираните низи како и тоа колку од влезните низи
останале празни, односно по трансформацијата имаат само елементи со вредност нула.
Трансформацијата на низите да се реализира во посебна функција. Решенијата без
користење функција ќе бидат оценети со најмногу 40% од поените.


*/
void shiftArrayToR(int *niza, int n, int pomesti)
{
    while (pomesti)
    {
        int temp = niza[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            niza[i] = niza[i - 1];
        }
        niza[0] = temp;
        pomesti--;
    }
}

void shiftArrayToL(int *niza, int n, int pomesti)
{
    while (pomesti)
    {
        int temp = niza[0];
        for (int i = 0; i < n - 1; i++)
        {
            niza[i] = niza[i + 1];
        }
        niza[n - 1] = temp;
        pomesti--;
    }
}

void printArray(int *niza, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", niza[i]);
    }
    printf("\n");
}

void readArray(int *niza, int n)
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &niza[i]);
    }
}

int main()
{
    int n, m, counter = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int niza[100] = {0};
        scanf("%d", &n);
        readArray(niza, n);
        int pomestuvanja = niza[0];
        if (abs(pomestuvanja) >= n)
        {
            counter++;
            for (int j = 0; j < n; ++j)
            {
                printf("0 ");
            }
            printf("\n");
            continue;
        }
        if (niza[0] >= 0)
        {
            shiftArrayToR(niza, n, niza[0]);
            for (int j = 0; j < pomestuvanja; ++j)
            {
                niza[j] = 0;
            }
        }
        else
        {
            shiftArrayToL(niza, n, abs(pomestuvanja));
            for (int j = n - 1; j >= n - abs(pomestuvanja); --j)
            {
                niza[j] = 0;
            }
        }
        printArray(niza, n);
    }
    printf("%d", counter);
}
