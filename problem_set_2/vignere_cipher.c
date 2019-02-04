#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int string_length(char * element);
char ceasar_shift(char c, int shift);

int main(int argc, char * argv[])
{
  if (argc != 2) {
    printf("Please supply a code word");
    return 1;
  }

  char * name = "Hello";
  char * permutations_c = argv[1];
  int secret_length = string_length(permutations_c);
  int length = string_length(name);

  char new_word[length];

  for(int i = 0, n = length; i < n; i++ ) {
    int permut = (int)permutations_c[i % secret_length] % 48;
    new_word[i] = ceasar_shift(name[i], permut - 1);
  }
  printf("%s", new_word);
}

int string_length(char * element) {
  int count = 0;
  do {
    count++;
  } while(strcmp(&element[count], "\0") != 0);
  return count;
}

char ceasar_shift(char c, int shift) {
  if (!isalpha(c)) {
    return c;
  }
  char new_c = ((int) c) + (shift % 26);
  return new_c;

}

