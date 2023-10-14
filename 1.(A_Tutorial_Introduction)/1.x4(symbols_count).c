#include <stdio.h>

#define NMAX 200
#define IN 1
#define OUT 0

int main() {
    char symbols[NMAX];
    int symbols_count[NMAX];
    int max_count, i, c, count, state;

    max_count = 0;
    count = 0;

    for (i = 0; i < NMAX; ++i) {
        symbols[i] = 0;
        symbols_count[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        for (i = 0; i < NMAX; ++i) {
            if (c == symbols[i]) {
                ++symbols_count[i];
                if (symbols_count[i] > max_count) {
                    max_count = symbols_count[i];
                }
                state = IN;
                break;
            } else {
                state = OUT;
            }
        }
        if (state == OUT){
            symbols[count] = c;
            symbols_count[count] = 1;
            ++count;
        }
    }

    printf("\n");
    for (i = 0; i < count; ++i) {
        if (symbols[i] == '\n')
            printf("\\n");
        else if (symbols[i] == '\t')
            printf("\\t");
        else
            printf("%-2c", symbols[i]);
    }
    printf("\n");

    while (max_count) {
        for (i = 0; i < count; ++i) {
            if (symbols_count[i] == max_count) {
                printf("* ");
                --symbols_count[i];
            } else {
                printf("  ");
            }
        }
        printf("\n");
        --max_count;
    }
}
