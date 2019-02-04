// check(4003600000000014) == 20
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <cs50.h>
#include <math.h>

int sum_of_num(int num);
int result(int num);
void card_type(int first_character);

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Please enter your credit card details \n");
    return 0;
  }

  string credit = argv[1];
  int length = strlen(credit);
  int remainder_digits = 0;
  int sum = 0;

  for(int i = 0; i < length; i += 2) {
    sum += sum_of_num((credit[i] - '0') * 2);
    remainder_digits += (credit[i+1] - '0');
  }

  int total = sum + remainder_digits;

  printf("Number: %s \n", credit);
  int valid = result(total);
  if (valid == 1) {
    card_type(credit[0] - '0');
  }
}

int sum_of_num(int num) {
  if (num > 9) {
    return num - 9;
  } else {
    return num;
  }
}

int result(int num) {
  int result = num % 10;
  if (result == 0) {
    printf("%s", "Is valid! \n");
    return 1;
  } else {
    printf("%s", "Is invalid! \n");
    return 0;
  }
}

void card_type(int first_character) {
  if (first_character == 3) {
    printf("AMERICAN EXPRESS \n");
  } else if (first_character == 4) {
    printf("VISA \n");
  } else if (first_character == 5) {
    printf("MasterCard \n");
  }
}

// All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55; and all Visa numbers start with 4


// In the ASCII table the difference between the num and string is the equivalent of the represented value:
// for instance: '0' has an ASCII value of 48
// '8' has an ASCII value of 56, the difference is the value of the sought for number.
// Hence, to cast an integer you can do '8' - '0' which will convert to ASCII values -> which returns 56 - 48 = 8 (of int)

// 3

// To convert character digit to corresponding integer. Do as shown below:

// char c = '8';
// int i = '8' - '0';
// 8 = 56 - 48
// Logic behind the calculation above is to play with ASCII values. ASCII value of character 8 is 56, ASCII value of character 0 is 48. ASCII value of integer 8 is 8.

// If we subtract two characters, subtraction will happen between ASCII of characters.

// int i = 56 - 48;
// i = 8;
















// 5413483712605763


// 5  1  4  3  7
// *  *  *  *  *

// 1 + 0 + 2 +  8 + 6 + 1 + 4

// 9 * 2 = 18

// 12      14      16      18
// 1 + 2   1 + 4   1 + 6   1 + 8

// 3       5       7       9


