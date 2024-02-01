#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * The program uses the Bisection method to find the root of a given function f(x).
 * The function to be solved is defined as f(x) = x^3 - x - 4.
 */

#define f(x) ((x*x*x)-x-4)

int main() {
    float a, b, c, h;

    // Input the initial values of 'a' and 'b'
    printf("Enter the value of a and b: \n");
    scanf("%f", &a);
    scanf("%f", &b);

    // Check if the initial values bracket the root
    if (f(a) * f(b) > 0) {
        printf("Initial values do not bracket the root. Exiting...\n");
        return 0;
    } else {
        // Bisection method to find the root
        do {
            c = (a + b) / 2;
            if (f(c) < 0) {
                a = c;
            } else {
                b = c;
            }
            h = (b + a) / 2;
            printf("%f\n", h);
        } while (fabs(h - c) > 0.001);

        // Output the root
        printf("\nThe root is %f\n", h);
    }

    return 0;
}
