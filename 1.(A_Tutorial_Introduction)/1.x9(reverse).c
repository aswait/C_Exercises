#include <stdio.h>

#define MAX 1000

void reverse(char input_string[], int length);

int main() {
    char string[MAX];
    int c, i;
    i = 0;

    while ((c = getchar()) != EOF) {
        string[i] = c;
        ++i;
        if (c == '\n') {
            string[i] = '\0';
            reverse(string, i - 1);
            printf("%s", string);
            i = 0;
        }
    }
}

void reverse(char input_string[], int length) {
    char temp[MAX];
    int i, n;

    n = length;

    for (i = 0; length != 0; ++i) {
        temp[length - 1] = input_string[i];
        --length;
    }

    for (i = 0; n != 0; ++i) {
        input_string[i] = temp[i];
        --n;
    }
}