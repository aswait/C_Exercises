#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double celsius(double fahr);

int main() {
    double fahr;
    fahr = LOWER;

    while (fahr <= UPPER) {
        printf("%3.0lf %6.1lf\n", fahr, celsius(fahr));

        fahr += STEP;
    }
}

double celsius(double fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}