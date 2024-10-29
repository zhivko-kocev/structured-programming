#include <stdio.h>

int is_sweet(int num) {

  while (num) {

    if ((num % 10) % 2 != 0) {
      return 0;
    }

    num /= 10;
  }

  return 1;
}

int main() {

  int m, n;
  scanf("%d %d", &m, &n);

  for (int i = m; i <= n; i++) {

    if (is_sweet(i)) {
      printf("%d", i);
      return 0;
    }
  }

  printf("NE");
  return 0;
}