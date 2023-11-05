#include <stdio.h>

#define MAX 1000

int get_line(char string[], int lim);

int main() {
    int length;
    char line[MAX];
    int c;

    while((length = get_line(line, MAX)) > 0) {
        if (line[MAX - 1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n') {
                ++length;
            }
            ++length;
        }
        if (length - 1 > 80) {
            printf("%s", line);
        }
    }
}

int get_line(char string[], int lim) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim - 1; ++i) {
        string[i] = c;
    }
    if (c == '\n') {
        string[i] = c;
        ++i;
    }
    string[i] = '\0';
    return i;
}