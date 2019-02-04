#include <stdio.h>
#include <string.h>

int string_length(char * element);
char ceasar_shift(char c, int shift);

int main(int argc, char * argv[])
{
  if (argc != 3) {
    printf("Please supply 2 arguments");
    return 1;
  }

  char * name = argv[1];
  int permutation = (int)*argv[2] - (int)48;

  int length = string_length(name);
  char new_word[length];

  for(int i = 0, n = string_length(name); i < n; i++ ) {
    new_word[i] = ceasar_shift(name[i], permutation);
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
  char new_c = ((int) c) + (shift % 26);
  return new_c;
}

