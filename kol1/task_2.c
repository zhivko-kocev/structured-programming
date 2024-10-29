#include <stdio.h>
/*
Eден природен e „интересен“ ако неговиот обратен број е делив со неговиот број
на цифри. Обратен број е бројот составен од истите цифри, но во обратен редослед
(на пример, 653 е обратен број на бројот 356). Од тастатура се внесува природен
број n ( n > 9). Да се најде и отпечати најголемиот природен број помал од n кој
што е „интересен“. Ако внесениот број не е валиден, да се отпечати соодветна
порака (Brojot ne e validen).
*/

int reversed(int number) {

  int reverse = 0;
  while (number) {
    reverse *= 10;
    reverse += (number % 10);
    number /= 10;
  }
  return reverse;
}

int num_digits(int number) {

  int counter = 0;
  while (number > 0) {
    counter += 1;
    number /= 10;
  }
  return counter;
}

int main() {
  int n;
  scanf("%d", &n);

  if (n < 10) {
    printf("Brojot ne e validen");
    return 0;
  }

  for (int i = n - 1; i > 0; i--) {
    if (reversed(i) % num_digits(i) == 0) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}