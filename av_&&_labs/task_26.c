#include <stdio.h>
int main() {
    int a[100], n, i, j, k, izbrisani = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (i = 0; i < n - izbrisani; ++i)
        for (j = i + 1; j < n - izbrisani; ++j)
            if (a[i] == a[j]) {
                for (k = j; k < n - 1 - izbrisani; ++k)
                    a[k] = a[k + 1];
                izbrisani++;
                --j;
            }
    n -= izbrisani;
    for (i = 0; i < n; ++i)
        printf("%d\t", a[i]);
    return 0;
}