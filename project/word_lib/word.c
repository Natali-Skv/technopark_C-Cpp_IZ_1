#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <word.h>
#define BUF_LEN (256u / sizeof(char))
#define FMT_SIZE (10)

char *scanner_word(FILE *fin, char *buf, int *buf_poz, int buf_len, int max_len) {
    if (!fin || (max_len <= 0) || (buf_len <= 0)) {
        return NULL;
    }
    char *word_buf = malloc((max_len) * sizeof(char));
    if (!word_buf) {
        perror("malloc() for buf failed" __FILE__);
        return NULL;
    }
    char format[FMT_SIZE];
    snprintf(format, sizeof(format), "%%%ds", (max_len - 1));
    if (sscanf(buf + *buf_poz, format, word_buf) != 1) {
        if (fgets(buf, buf_len, fin)) {
            if (sscanf(buf, format, word_buf) != 1) {
                free(word_buf);
                return NULL;
            }
            *buf_poz = 0;
        } else {
            free(word_buf);
            return NULL;
        }
    }
    int word_len = (int) strlen(word_buf);
    *buf_poz += word_len;
    char *word = (char *) malloc((word_len + 1) * sizeof(char));
    if (!word) {
        free(word_buf);
        perror("malloc() failed" __FILE__);
        return NULL;
    }
    memcpy(word, word_buf, (word_len + 1) * sizeof(char));
    free(word_buf);
    return word;
}

int scanner_lot_of_words(FILE *fin, char *mass_word[], int mass_size, int max_word_len) {
    if (!fin || !mass_word || (mass_size <= 0) || (max_word_len <= 0)) {
        return 0;
    }
    char *buf = (char *) malloc(BUF_LEN);
    if (!buf) {
        perror("malloc() for buf failed" __FILE__);
        return 0;
    }
    buf[0] = '\0';
    int buf_poz = 0;
    int word_count = 0;
    while ((word_count < mass_size) &&
           (mass_word[word_count] = scanner_word(fin, buf, &buf_poz, BUF_LEN, max_word_len))) {
        ++word_count;
    }
    free(buf);
    return word_count;
}

void str_to_lower(char *str) {
    if (!str) {
        return;
    }
    for (int i = 0; str[i]; ++i) {
        if (('A' <= str[i]) && (str[i] <= 'Z')) {
            str[i] |= 'a' - 'A';
        }
    }
}

void swap(char *v[], size_t i, size_t j) {
    if (!v) {
        return;
    }
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


void q_sort(char *v[], int left, int right, int (*comp)(const char *, const char *)) {
    if (!v || left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    int last = left;
    for (int i = left + 1; i <= right && v[i] && v[left]; ++i) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    q_sort(v, left, last - 1, comp);
    q_sort(v, last + 1, right, comp);
}
