#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256
#define MAX_NUM_WORDS 256

int main() {
    char **mass_str = (char **) malloc(MAX_NUM_WORDS * sizeof(char *));
    if (!mass_str) {
        perror("malloc() failed ");
        return 0;
    }
    int num_strs = scanner_lot_of_words(stdin, mass_str, MAX_NUM_WORDS, MAX_LEN);

    if (!num_strs) {
        perror("scanner_lot_of_words() failed ");
        return 0;
    }
    for (int i = 0; i < num_strs; ++i) {
        str_to_lower(mass_str[i]);
    }

    q_sort(mass_str, 0, num_strs - 1, strcmp);

    for (int i = 0; i < num_strs; ++i) {
        printf("%s\n", mass_str[i]);
    }
    for (int i = 0; i < num_strs; ++i) {
        free(mass_str[i]);
    }
    free(mass_str);
}
