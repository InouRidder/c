#include <stdio.h>

int main(void)
{

  char number_one[20];
  char number_two[20];
  printf("%s", "What is your first number? \n");
  gets(number_one);
  int i_one = atoi(number_one); //array to integer is type casting from array of characters (~string) to integer

  printf("%s", "What is your first number? \n");
  gets(number_two);
  int i_two = atoi(number_two);

  if (i_two % 2 == 0) {
    printf("%i is even! \n", i_two);
  }

  if (i_one > i_two) {
   printf("%i is larger than %i \n", i_one, i_two);
  } else if (i_one < i_two) {
    printf("%i is smaller than %i \n", i_one, i_two);
  } else {
    printf("%i is equal to %i \n", i_one, i_two);
  }

}
