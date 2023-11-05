#include <stdio.h>

#define MAX 1000

int get_line(char line[], int lim);

int main() {
    char line[MAX];
    int i, length;

    while ((length = get_line(line, MAX)) > 0) {
        --length;
        for (i = length - 1; i > 0; --i) {
            if (line[i] == '\t' || line[i] == ' ') {
                --length;
            } else {
                i = 0;
            }
        }

        if (length != 0) {
            for (i = 0; i < length; ++i) {
                printf("%c", line[i]);
            }
            printf("\n");
        }
    }
}

int get_line(char line[], int lim) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim - 1; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}