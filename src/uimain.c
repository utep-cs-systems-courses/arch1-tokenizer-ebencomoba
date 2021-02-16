#include <stdio.h>                //Working with strings

int main () {
  puts("Welcome");
  puts("I will be a temporary UI while we work on this project");
  puts("Meanwhile, I will repeat what you write");

  while(1) {       /*Infinite loop */
    char sentence[70];
    printf("\nWrite your sentence or enter q to quit:\n> ");
    fgets(sentence, 70, stdin);
    if (sentence[0] == 'q' && sentence[1] == '\n') {
      puts("\nThank you!");
      break;
    }
    else
      printf("You wrote: %s", sentence);
  }
  return 0;
}
