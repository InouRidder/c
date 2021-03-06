#include <cs50.h>
#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <string.h>

int string_length(char * element);
char next_letter();
char head = 0;
// Assuming there is only alphabetical characters, but it can go for any length / variation
char alphabet[53] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int x_position = 0;
int y_position = 0;

int main(int argc, string argv[])
{
  if (argc != 2) {
    printf("Please only a hash to decode \n");
    return 1;
  }
  char * hash_to_match = argv[1];
  char * salt = "50cs";
  char * result_hash;
  int end_of_chars = 0;
  int hash_is_matched = 0;

  char guess[5];
  do {

    char letter = next_letter();
    if (strcmp(&letter, "\0") != 0) {
      guess[x_position] = letter;
      if (x_position > 0) {
        x_position--;
      }
    } else {
      guess[y_position] = ' ';
      x_position++;
      if (x_position > 5) {
        end_of_chars = 1;
      }
    }
    char * result_hash = crypt(guess, salt);
    if (strcmp(hash_to_match, result_hash) != 0) {
      hash_is_matched = 1;
    }

  } while (end_of_chars != 1 || hash_is_matched != 1);

  if (hash_is_matched == 1) {
    printf("MATCHED: %s \n PASSWORD: %s \n", result_hash, guess);
  } else {
    printf("Did not match \n");
  }
}

char next_letter() {
  char let = alphabet[y_position++];
  return let;
}

int string_length(char * element) {
  int count = 0;
  do {
    count++;
  } while(strcmp(&element[count], "\0") != 0);
  return count;
}

// The Shadow Knows
// On most systems running Linux these days is a file called /etc/shadow that contains usernames and passwords. Fortunately, the passwords therein aren’t stored “in the clear” but are instead encrypted using a “one-way hash function.” When a user logs into these systems by typing a username and password, the latter is encrypted with the very same hash function, and the result is compared against the username’s entry in /etc/shadow. If the two hashes match, the user is allowed in. If you’ve ever forgotten some password, you might have been told that tech support can’t look up your password but can change it for you. Odds are that’s because tech support can only see, if anything at all, a hash of your password, not your password itself. But they can create a new hash for you.

// Even though passwords in /etc/shadow are hashed, the hash function is not always that strong. Quite often are adversaries, upon obtaining that file somehow, able to guess (and check) users’ passwords or crack them using brute force (i.e., trying all possible passwords). Below is what /etc/shadow might look like, albeit simplified, wherein each line is formatted as username:hash.

// brian:51.xJagtPnb6s
// bjbrown:50GApilQSG3E2
// emc:502sDZxA/ybHs
// greg:50C6B0oz0HWzo
// jana:50WUNAFdX/yjA
// lloyd:50n0AAUD.pL8g
// malan:50CcfIk1QrPr6
// natmelo:50JIIyhDORqMU
// rob:51v3Nh6ZWGHOQ
// veronica:61v1CDwwP95bY
// walker:508ny6Rw0aRio
// zamyla:50cI2vYkF0YU2

// Safecracker
// Your task is to design and implement a program, crack, that cracks passwords. We’re not going to give too many hints on this one, but to get started you may want to read up on how the crypt function works on Unix/Linux systems, such as this lab environment. To do so, type:

// man crypt
// in the terminal. Take particular note of that program’s mention of “salt”. Per that “man page”, you’ll likely want to put

// #define _XOPEN_SOURCE
// #include <unistd.h>
// at the top of your file in order to use crypt. Use pseudocode.txt as a notepad for ideas as to how you should organize your program!

// Specification
// Your program should accept one and only one command-line argument: a hashed password.
// If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).
// Otherwise, your program must proceed to crack the given password, ideally as quickly as possible, ultimately printing the password in the clear followed by \n, nothing more, nothing less, with main returning 0.
// Assume that each password has been hashed with C’s DES-based (not MD5-based) crypt function.
// Assume that each password is no longer than five (5) characters. Gasp!
// Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase).
// Below, then, is some example behavior.

// $ ./crack
// Usage: ./crack hash
// $ ./crack 50cI2vYkF0YU2
// LOL
