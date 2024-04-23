#include <stdio.h>
/*
За еден природен број а велиме дека е порамнување на друг природен број b
ако и само ако цифрите еднакви на 9 во бројот b се заменети со цифрата 7 во бројот а.
Пример. Бројот 734775 е порамнување на бројот 934795.
Од стандарден влез се внесуваат непознат број на цели броеви (не повеќе од 100),
се додека не се внесе нешто што не може да се интерпретира како цел број.
Ваша задача е да ги отпечатите најмалите 5 од порамнувањата на сите внесени
броеви, по редослед од најмалиот кон најголемиот.
Забелешка: Доколку се внесат помалку од 5 броеви, тогаш печатите толку броеви
колку што се соодветно внесени.
Наоѓањето на порамнувањето на даден број треба да се реализира во посебна
рекурзивна функција poramnet(int a).
Пример.
За броевите: 9592, 69403, 100007, 6, 987, 6977, 33439,
треба да се најдат нивните порамнувања ( тоа се: 7572, 67403, 100007, 6, 787, 6777 и 33437, соодветно),
и да се отпечатат најмалите 5 од нив по овој редослед: 6 787 6777 7572 33437.
ЗАБРАНЕТО е користење на глобални променливи.
*/
int poramnet(int n)
{
    if (!n)
    {
        return 0;
    }
    if (n % 10 == 9)
    {
        return 7 + 10 * poramnet(n / 10);
    }
    else
    {
        return n % 10 + 10 * poramnet(n / 10);
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n, niza[100], i = 0;
    while (scanf("%d", &n))
    {
        niza[i] = poramnet(n);
        i++;
    }
    insertionSort(niza, i);
    if (i <= 4)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", niza[j]);
        }
    }
    else
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", niza[j]);
        }
    }
}