// Program to approximate value of pi using the Nilakantha series.
// Takes an argument to see how many terms of the series need to be included in the calculation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function that will accept arguments and return failure if argument not provided
// Also parse to extract number of terms.
int main(int argc, char** argv);

// Function that computes the series
double estimate(int n);

//Function that returns the nth term
double value(int n);

//Print error messages
void logError(const char* error);

int main(int argc, char** argv) {
    if (argc != 2) {
        return EXIT_FAILURE;
    }

    char* endptr;
    int n = strtol(argv[1], &endptr, 10);

    //check that the input is legal
    //check for cases like 10.5 or 10ans
    char* endptr2 = argv[1] + strlen(argv[1]);
    if (endptr != endptr2) {
        logError("User provided non integer value");
        return EXIT_FAILURE;
    }

    if (n <= 0) {
        logError("User provided nonpositive number");
        return EXIT_FAILURE;
    }

    printf("Esitmate of pi using the nilakantha series and %d terms is:\n", n);
    printf("%f", estimate(n));

    return EXIT_SUCCESS;
}

double estimate(int n) {
    double sign = -1.0;
    double est = 3.0;
    for(int i = 1; i <= n; i++) {
        sign = sign * -1.0;
        est = est + (sign * value(i));
    }
    return est;
}

double value (int n) {
    double val = 4.0 / ((2.0 * n) * (2.0 * n + 1.0) * (2.0 * n + 2.0));
    return val;
}

void logError(const char* error_text) {
  fprintf(stderr, "ERROR: %s\n", error_text);
}

