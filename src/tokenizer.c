#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return (c == ' ' || c == '\t');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  return (c != ' ' && c != '\t' && c != '\0');
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  /* If we see a non_space char, we found the start of the word */
  while (*str) {
    if (non_space_char(*str)) {
      return str;
    }
    str++;
  }
  return '\0';
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  /* If we see a space char, we found the end of the word */
  while (*str) {
    if (space_char(*str)) {
      return str;
    }
    str++;
  }
  return '\0';
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  /* We find the number of words with word_start
     and end them with word terminator */
  int numWords = 0;
  while (*str) {
    str = word_start(str);
    numWords++;
    str = word_terminator(str);
  }
  return numWords;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  /* We make space for the string and copy the chars to it */
  char *token_ptr = malloc((len+1) * sizeof(char));
  for (int counter = 0; counter < len; counter) {
    *(token_ptr + counter) = *(inStr + counter);
  }
  *(token_ptr + len) = '\0';
  return token_ptr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  /* We print all tokens */
  int counter = 0;
  while (**tokens) {
    printf("tokens[%d] = \"%s\"\n", counter, *tokens);
    counter++;
    tokens++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  /* We free the memory from the tokens and the token vector */
  while (**tokens) {
    free(*tokens);
    tokens++;
  }
  free(tokens);
}
