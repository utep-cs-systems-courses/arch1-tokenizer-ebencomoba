Project 1: Tokenizer
====================
The project consists of a program that receives sentences from the user. It
tokenizes the sentences (divides the sentence into words) and prints back a
lit of these words. This process can be done indefinitely until the user
decides to exit. The program also maintains a history of the sentences that
the user has entered in the past. The user can call this history and a list of
the previous strings will be displayed.

## Makefile
I decided to use a Makefile similar to the one provided in lab 0 since I think
this kind of generalizatio of objects and flags can be useful in the future. I
also checked how to establish the dependencies of each object file separately.

## Uimain
It is the interface the user will see. It expresses the function of the
program and allows the user to decide wheter to exit the program, show the
history or tokenize a new string.

## Tokenizer
tokenizer.h, the header file, only contains the definitions of the functions,
which are implemented in tokenizer.c. I will decribe them below:
1. **space_char** Receives as input a character and returns whether it is a space
character or not.
2. **non_space_char** Same as previous, but this time it fill return true if
something other than space character and zero terminator is detected.
3. **word_start** It receives a pointer to a character and returns the first
pointer that points to a non space character or a zero terminator if there are
no words left. I used non_space_char to detect the first non space character.
4. **word_terminator** Same as previous, but it returns the first pointer that
points to a space character or a zero terminator if the string had ended. I
used space_char to detect the first space character.
5. **count_words** It receives a pointer to a character and counts the number of
words in the string. I used word_terminator and word_start to detect the start
and end of each word.
6. **copy_str** It receives a pointer to a character and the length of the word
to copy. I searched for memory with malloc and then allocated the copy of the
string there. Returns the pointer the start of the string.
7. **tokenize** It receives a pointer to a character. It counts the number of
words and calls malloc to create an array of pointers that will point to each
of the tokens. Then, it copies each token from the string. Returns a pointer
to the pointers.
8. **print_tokens** It receives a pointer to pointers to a character. Bt
traversing the pointers, it prints each character. I organized to that it
produces a list of the tokens.
9. **free_tokens** It receves a pointer to a pointers to a character. It
traverses each pointer and frees the pointers produced by malloc. Then, it
frees the input pointer as well.

## History
history.h, cointains the definitions of the functions used to keep a record of
the strings entered by the user. Functions implemented in history,c, that I
will describe below:
1. **init_history** It initializes the linked list that contains the history.
2. **copy_string** It is a function I decided to add, that receives a pointer
to a character and copies the full string, It returns the pointer to the newly
allocated string.
3. **add_history** It receives pointer to the List and a pointer to a
character. It adds a new Item to the List containing a copy of the user's
string.
4. **get_history** It receives a pointer to the List and an integer. It reurns
a pointer to a character of the string contained in the Item n of the list.
5. **print_history** It receives a pointer to the list and traverses the
contents of the List, printing the string of each Item containd in the form of
a list of sentences.
6. **free_history** It receives a pointer to the List. It traverses the list,
freeing the memory used for the copy of the string and for the Item
itself. Then, it also frees the memory used for the list.
