#include <stdio.h>

#define MAX_LINE 1000


int get_line(char line[], int max_line);
void copy(char to[], char from[]);

int main() {
    int len, max_len, i;
    char line[MAX_LINE], longest[MAX_LINE];

    max_len = 0;

    while ((len = get_line(line, MAX_LINE)) > 0) {
        if (len > max_len) {
            max_len = len;
            copy(longest, line);
        }
    }

    for (i = 0; i < max_len; ++i) {
        printf("%c", longest[i]);
    }

    return 0;
}

int get_line(char line[], int max_line) {
    int c, i;

    for (i = 0; i < max_line - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}