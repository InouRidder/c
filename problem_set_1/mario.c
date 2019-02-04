#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Make mario's pyramid (assignment 2 of CS50 lecture week 1's problemset)

int get_user_number(void);
void print_pyramid(int);
void print_leading_spaces(int n);

int main(void)
{
  print_pyramid(get_user_number());
}

int get_user_number(void) {
  int n;
  do {
    char answer[10];
    printf("What is your number? \n");
    gets(answer);
    n = atoi(answer);
  } while(n > 8 || n < 1);
  return n;
}

void print_leading_spaces(int n) {
  for(int i = 0; i < n; i++) {
    printf(" ");
  }
}

void print_pyramid(int n) {
  char str[8] = "";

  printf("Height: %i \n", n);
  for(int i = 1; i <= n; i++) {
    strcat(str, "#");
    print_leading_spaces(n - i);
    printf("%s  %s \n", str, str);
  }
}

