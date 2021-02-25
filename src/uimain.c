#include <stdio.h>      //Working with strings
#include <stdlib.h>
#include "tokenizer.h"

int main () {
  puts("Welcome");
  puts("I will be a temporary UI while we work on this project");

  while(1) {       /*Infinite loop */
    printf("\nWrite your sentence or enter q to quit:\n> ");
    /* We obtaing a sentence of max length 100,
       leaving space to zero-terminate it */
    char sentence[100];
    char *ptr = sentence;
    int counter = 0;
    char c;
    while ((c = getchar()) != '\n' && counter < 99) {
      *(ptr + counter) = c;
      counter++;
    }
    *(ptr + counter) = '\0';
    /* If the user quits, we exit the loop */
    if (sentence[0] == 'q' && sentence[1] == '\0') {
      puts("\nThank you!");
      break;
    }
    else {
      printf("You wrote: %s\n", sentence);
      char **tokenVector = tokenize(ptr);
      print_tokens(tokenVector);
      free_tokens(tokenVector);
    }
  }
  return 0;
}
