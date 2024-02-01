#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * The program uses the Regula Falsi (False Position) method to find the root of a given function f(x).
 * The function to be solved is defined as f(x) = x^3 - 9x + 1.
 */

#define f(x) (pow(x,3) - (9*x) + 1)

int main() {
    float a, b, c, d, h;

    // Input the initial values of 'a' and 'b'
    printf("Enter the value of a:");
    scanf("%f", &a);
    printf("\nEnter the value of b:");
    scanf("%f", &b);

    // Check if the initial values bracket the root
    if (f(a) * f(b) > 0) {
        printf("Initial values do not bracket the root. Exiting...\n");
        return 0;
    } else {
        // Regula Falsi method to find the root
        do {
            c = a - ((f(a) * (b - a)) / (f(b) - f(a)));

            if (f(c) > 0) {
                a = c;
            } else {
                b = c;
            }

            h = a - ((f(a) * (b - a)) / (f(b) - f(a)));
            printf("%f\n", h);
        } while (fabs(h - c) > 0.0001);

        // Output the root
        printf("\n%f", h);
    }

    return 0;
}
