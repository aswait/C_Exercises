#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, state;

    state = IN;

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            putchar('\n');
        }
        if (state == IN) {
            putchar(c);
        }
    }

    return 0;
}