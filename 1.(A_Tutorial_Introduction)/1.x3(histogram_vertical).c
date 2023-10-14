#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXN 100

int main() {
    int words_count, max_length, words[MAXN];
    int c, i, state, word_length;

    words_count = 0;
    word_length = 0;
    max_length = 0;

    for (i = 0; i < MAXN; ++i) {
        words[i] = 0;
    }

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == '\n' || c == ' ') {
            if (state == IN) {
                state = OUT;
                words[words_count - 1] = word_length;

                if (word_length > max_length) {
                    max_length = word_length;
                }
            }
        } else if (state == OUT) {
            state = IN;
            word_length = 1;
            ++words_count;
        } else
            ++word_length;
    }

    putchar('\n');
    for (i = 0; i < words_count; ++i) {
        printf("%-3d", i + 1);
    }

    putchar('\n');
    while (max_length) {
        for (i = 0; i < words_count; ++i){
            if (words[i] == max_length) {
                printf("*  ");
                --words[i];
            } else {
                printf("   ");
            }
        }
        --max_length;
        putchar('\n');
    }

}
