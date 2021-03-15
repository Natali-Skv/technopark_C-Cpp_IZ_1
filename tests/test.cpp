#include <cstdlib>
#include <cstring>
#include <fstream>
#include <gtest/gtest.h>
extern "C" {
#include <word.h>
}

#define MAX_LEN 256
#define MAX_LEN_FMT "255"
#define MAX_NUM_WORDS 256

TEST(scanner_word, test1) {
    const char *file_name = "../tests/input_emulator/f1";
    FILE *fin1 = fopen(file_name, "r");
    FILE *fin2 = fopen(file_name, "r");
    ASSERT_FALSE(!fin1 || !fin2);
    char *word_exp = new char[MAX_LEN];
    char *word_curr = nullptr;
    while (fscanf(fin1, "%" MAX_LEN_FMT "s", word_exp) == 1) {
        EXPECT_STREQ(word_curr = scanner_word(fin2, MAX_LEN), word_exp);
        free(word_curr);
    }
    delete[](word_exp);
    if (fclose(fin1) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
    if (fclose(fin2) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}

TEST(scanner_word, test2) {
    const char *file_name = "../tests/input_emulator/f2";
    FILE *fin1 = fopen(file_name, "r");
    FILE *fin2 = fopen(file_name, "r");
    ASSERT_FALSE(!fin1 || !fin2);
    char *word_exp = new char[MAX_LEN];
    char *word_curr = nullptr;
    while (fscanf(fin1, "%" MAX_LEN_FMT "s", word_exp) == 1) {
        EXPECT_STREQ(word_curr = scanner_word(fin2, MAX_LEN), word_exp);
        free(word_curr);
    }
    delete[](word_exp);
    if (fclose(fin1) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
    if (fclose(fin2) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}

TEST(scanner_word, test3) {
    const char *file_name = "../tests/input_emulator/f3";
    FILE *fin1 = fopen(file_name, "r");
    FILE *fin2 = fopen(file_name, "r");
    ASSERT_FALSE(!fin1 || !fin2);
    char *word_exp = new char[MAX_LEN];
    char *word_curr = nullptr;
    while (fscanf(fin1, "%" MAX_LEN_FMT "s", word_exp) == 1) {
        EXPECT_STREQ(word_curr = scanner_word(fin2, MAX_LEN), word_exp);
        free(word_curr);
    }
    delete[](word_exp);
    if (fclose(fin1) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
    if (fclose(fin2) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}


TEST(scanner_lot_of_words, test1) {
    const char *file_name = "../tests/input_emulator/f1";
    FILE *fin1 = fopen(file_name, "r");
    FILE *fin2 = fopen(file_name, "r");
    ASSERT_FALSE(!fin1 || !fin2);
    char *str_exp = new char[MAX_LEN];
    char **mass_strs = new char *[MAX_NUM_WORDS];
    int num_strs = scanner_lot_of_words(fin1, mass_strs, MAX_NUM_WORDS, MAX_LEN);

    for (int i = 0; i < num_strs; ++i) {
        EXPECT_TRUE(fscanf(fin2, "%" MAX_LEN_FMT "s", str_exp) == 1);
        EXPECT_STREQ(mass_strs[i], str_exp);
    }
    EXPECT_TRUE((fscanf(fin2, "%" MAX_LEN_FMT "s", str_exp) == EOF) || (num_strs == MAX_NUM_WORDS));

    for (int i = 0; i < num_strs; ++i) {
        free(mass_strs[i]);
    }
    delete[](mass_strs);
    delete[](str_exp);
    if (fclose(fin1) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
    if (fclose(fin2) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}


TEST(scanner_lot_of_words, test2) {
    const char *file_name = "../tests/input_emulator/f2";
    FILE *fin1 = fopen(file_name, "r");
    FILE *fin2 = fopen(file_name, "r");
    char *str_exp = new char[MAX_LEN];
    char **mass_strs = new char *[MAX_NUM_WORDS];
    ASSERT_FALSE(!fin1 || !fin2);
    int num_strs = scanner_lot_of_words(fin1, mass_strs, MAX_NUM_WORDS, MAX_LEN);

    for (int i = 0; i < num_strs; ++i) {
        EXPECT_TRUE(fscanf(fin2, "%" MAX_LEN_FMT "s", str_exp) == 1);
        EXPECT_STREQ(mass_strs[i], str_exp);
    }
    EXPECT_TRUE((fscanf(fin2, "%" MAX_LEN_FMT "s", str_exp) == EOF) || (num_strs == MAX_NUM_WORDS));

    for (int i = 0; i < num_strs; ++i) {
        free(mass_strs[i]);
    }
    delete[](mass_strs);
    delete[](str_exp);
    if (fclose(fin1) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
    if (fclose(fin2) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}
TEST(scanner_lot_of_words, test3) {
    const char *file_name = "../tests/input_emulator/f3";
    FILE *fin1 = fopen(file_name, "r");
    FILE *fin2 = fopen(file_name, "r");
    char *str_exp = new char[MAX_LEN];
    char **mass_strs = new char *[MAX_NUM_WORDS];
    ASSERT_FALSE(!fin1 || !fin2);
    int num_strs = scanner_lot_of_words(fin1, mass_strs, MAX_NUM_WORDS, MAX_LEN);

    for (int i = 0; i < num_strs; ++i) {
        EXPECT_TRUE(fscanf(fin2, "%" MAX_LEN_FMT "s", str_exp) == 1);
        EXPECT_STREQ(mass_strs[i], str_exp);
    }
    EXPECT_TRUE((fscanf(fin2, "%" MAX_LEN_FMT "s", str_exp) == EOF) || (num_strs == MAX_NUM_WORDS));

    for (int i = 0; i < num_strs; ++i) {
        free(mass_strs[i]);
    }
    delete[](mass_strs);
    delete[](str_exp);
    if (fclose(fin1) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
    if (fclose(fin2) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}

TEST(str_to_lower, test1) {
    char s1[] = "QWERTYUIOP qwerTYUIOp A1S2D3F4g5h5H6";
    const char *s1_exp = "qwertyuiop qwertyuiop a1s2d3f4g5h5h6\0";

    str_to_lower(s1);
    EXPECT_STREQ(s1, s1_exp);

    char s2[] = "azxc 12345678900987654321";
    const char *s2_exp = "azxc 12345678900987654321";
    str_to_lower(s2);
    EXPECT_STREQ(s2, s2_exp);

    char s3[] = "";
    const char *s3_exp = "";
    str_to_lower(s3);
    EXPECT_STREQ(s3, s3_exp);

    char s4[] = "///...???12341234ASDFASDFasdf!@#$!@#$@#$@34";
    const char *s4_exp = "///...???12341234asdfasdfasdf!@#$!@#$@#$@34";
    str_to_lower(s4);
    EXPECT_STREQ(s4, s4_exp);
}

TEST(qsort, test1) {
    const char *file_name = "../tests/input_emulator/f1";
    FILE *fin = fopen(file_name, "r");
    ASSERT_FALSE(!fin);
    char **mass_strs = new char *[MAX_NUM_WORDS];
    int num_strs = scanner_lot_of_words(fin, mass_strs, MAX_NUM_WORDS, MAX_LEN);

    q_sort(mass_strs, 0, num_strs - 1, strcmp);
    for (int i = 1; i < num_strs; ++i) {
        EXPECT_TRUE(strcmp(mass_strs[i], mass_strs[i - 1]) >= 0);
    }

    for (int i = 0; i < num_strs; ++i) {
        free(mass_strs[i]);
    }
    delete[](mass_strs);
    if (fclose(fin) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}

TEST(qsort, test2) {
    const char *file_name = "../tests/input_emulator/f2";
    FILE *fin = fopen(file_name, "r");
    ASSERT_FALSE(!fin);
    char **mass_strs = new char *[MAX_NUM_WORDS];
    int num_strs = scanner_lot_of_words(fin, mass_strs, MAX_NUM_WORDS, MAX_LEN);

    q_sort(mass_strs, 0, num_strs - 1, strcmp);
    for (int i = 1; i < num_strs; ++i) {
        EXPECT_TRUE(strcmp(mass_strs[i], mass_strs[i - 1]) >= 0);
    }

    for (int i = 0; i < num_strs; ++i) {
        free(mass_strs[i]);
    }
    delete[](mass_strs);
    if (fclose(fin) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}

TEST(qsort, test3) {
    const char *file_name = "../tests/input_emulator/f3";
    FILE *fin = fopen(file_name, "r");
    ASSERT_FALSE(!fin);
    char **mass_strs = new char *[MAX_NUM_WORDS];
    int num_strs = scanner_lot_of_words(fin, mass_strs, MAX_NUM_WORDS, MAX_LEN);

    q_sort(mass_strs, 0, num_strs - 1, strcmp);
    for (int i = 1; i < num_strs; ++i) {
        EXPECT_TRUE(strcmp(mass_strs[i], mass_strs[i - 1]) >= 0);
    }

    for (int i = 0; i < num_strs; ++i) {
        free(mass_strs[i]);
    }
    delete[](mass_strs);
    if (fclose(fin) == EOF) {
        std::cerr << "error of closing file: " << file_name << std::endl;
    };
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}