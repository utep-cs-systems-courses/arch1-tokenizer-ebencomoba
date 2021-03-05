#include <stdio.h>
#include <stdlib.h>
#include "history.h"
/*
typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;
*/

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *hist_ptr = (List*) malloc(sizeof(List));
  List history;
  *hist_ptr = history;
  return hist_ptr;
}

/* Copy the contents of string src to dest */
char* copy_string(char *src)
{
  // We obtain the length of src and create space for it
  int length = 0;
  char *temp_ptr = src;
  while (*temp_ptr) {
    length++;
    temp_ptr++;
  }
  char *dest = (char*) malloc(sizeof(char) * (length+1));
  // We copy its contents to dest and return
  for (int count = 0; count < length; count++) {
    *(dest + count) = *(src + count);
  }
  *(dest + length) = '\0';
  return dest;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  // Create the node and copy the string
  Item *new_item = (Item*) malloc(sizeof(Item));  
  new_item->str = copy_string(str);
  // If head is empty, put it in head
  if (!list->root) {
    list->root = new_item;
    new_item->id = 0;
    return;
  }
  // Else, we put it in tail
  Item *tail = list->root;
  while (tail->next) {
    tail = tail->next;
  }
  tail->next = new_item;
  new_item->id = (tail->id) + 1;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  // We traverse until id is 0 (meaning we found item #id)
  Item *temp_item = list->root;
  while (id) {
    temp_item = temp_item->next;
    id--;
  }
  return temp_item->str;
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  if (!list->root) {
    puts("Empty history");
    return;
  }
  // We traverse printing the id and string of each Item
  Item *temp_item = list->root;
  while (temp_item) {
    printf("(%d) \"%s\"\n", temp_item->id, temp_item->str);
    temp_item = temp_item->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *curr_item = list->root;
  Item *next_item;
  while (curr_item) {
    next_item = curr_item->next;
    free(curr_item->str);
    free(curr_item);
    curr_item = next_item;
  }
  free(list);
}
