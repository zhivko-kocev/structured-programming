#include <stdio.h>
/*
Од тастатура се читаат 2 позитивни цели броеви. Доколку се внесе барем еден
негативен број или 0 треба да се печати „Invalid input“.
Треба да се определи дали помалиот број “е парен еквивалент” од поголемиот број.
Еден број “е парен еквивалент” на друг број, ако и само ако неговите цифри се
наоѓаат на парните позиции од другиот број, во истиот редослед. Соодветно да се
испечатат пораки „PAREN“ и „NE“.
Позициите треба да се сметаат оддесно-налево (најмалку значајната цифра е на
позиција 1)
*/
int equivalent(int num1, int num2) {

  int temp;

  if (num1 > num2) {

    temp = num2;

    while (temp) {

      if (temp % 10 == (num1 / 10) % 10) {

        temp /= 10;
        num1 /= 100;

      } else {
        return 1;
      }
    }

  } else {

    temp = num1;

    while (temp) {

      if (temp % 10 == (num2 / 10) % 10) {

        temp /= 10;
        num2 /= 100;

      } else {
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  int num1, num2;
  scanf("%d %d", &num1, &num2);

  if (num1 <= 0 || num2 <= 0) {

    printf("Invalid input");
    return 0;
  }

  printf("%s", (!equivalent(num1, num2)) ? "PAREN" : "NE");
  return 0;
}
