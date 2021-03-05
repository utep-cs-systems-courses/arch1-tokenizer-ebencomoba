#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main () {
  puts("Welcome");
  puts("Here you can type a sentence and it will be converted to tokens.");
  puts("Furthermore, you can see your previous sentences.");
  List *history = init_history();
  

  while(1) {       /*Infinite loop */
    printf("\nWrite your sentence, enter q to quit or enter h to see the history:\n> ");
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
      free_history(history);
      break;
    }
    else if (sentence[0] == 'h' && sentence[1] == '\0') {
      puts("\nHere is your history:");
      print_history(history);
    }
    else {
      printf("You wrote: %s\n", sentence);
      add_history(history, sentence);
      char **tokenVector = tokenize(ptr);
      print_tokens(tokenVector);
      free_tokens(tokenVector);
    }
  }
  return 0;
}
