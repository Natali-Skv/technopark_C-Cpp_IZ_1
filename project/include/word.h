#ifndef PROJECT_INCLUDE_WORD_H_
#define PROJECT_INCLUDE_WORD_H_

#include <stddef.h>
#include <stdio.h>
char *scanner_word(FILE *fin, int max_len);
int scanner_lot_of_words(FILE *fin, char *mass_str[], int mass_size, int max_str_len);
void str_to_lower(char *str);
void q_sort(char *v[], int left, int right, int (*comp)(const char *, const char *));

#endif// PROJECT_INCLUDE_WORD_H_
