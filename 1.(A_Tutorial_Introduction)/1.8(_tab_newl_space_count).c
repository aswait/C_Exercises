#include <stdio.h>

int main() {
    int c, nl, t, sp;

    nl = 0;
    t = 0;
    sp = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            ++t;
        else if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++sp;
    }
    printf("\nnew_line: %d tabs: %d spaces: %d", nl, t, sp);
}