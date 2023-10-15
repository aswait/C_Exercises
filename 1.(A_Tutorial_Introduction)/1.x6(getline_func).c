#include <stdio.h>

#define MAX 1000

int get_line(char string[], int lim);
void copy(char to[], char from[]);

int main() {
    int length, max_length;
    char line[MAX], max_line[MAX];
    int c;

    while ((length = get_line(line, MAX)) > 0) {
        if (line[MAX - 1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n') {
                ++length;
            }
            ++length;
        }
        if (length > max_length) {
            max_length = length;
            copy(max_line, line);
        }
    }
    if (max_length > 0) {
        printf("\n%s", max_line);
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


void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
