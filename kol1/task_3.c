#include <stdio.h>
/*
Од стандарден влез се чита еден природен број n. Меѓу природните броеви помали
од n, да се најде оној чиј што збир на делителите е најголем.Во пресметувањето
на збирот на делителите на даден број, да не се зема предвид самиот број.
*/
int sum_dividers(int number) {

  int sum = 0;

  for (int divider = 1; divider < number; divider++) {
    if (number % divider == 0) {
      sum += divider;
    }
  }

  return sum;
}

int main() {

  int n, sum, max_sum = 0, max_num = 0;
  scanf("%d", &n);

  for (int i = 2; i < n; i++) {
    sum = sum_dividers(i);
    if (max_sum < sum) {
      max_sum = sum;
      max_num = i;
    }
  }

  printf("%d", max_num);
  return 0;
}