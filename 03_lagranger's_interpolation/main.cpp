#include <stdio.h>

/**
 * The program takes a set of data points (x, y) and allows the user to input a value of x
 * for which it interpolates and outputs the corresponding value of y using Lagrange's Interpolation.
 */
int main() {
    float x[100], y[100], a, s = 1, t = 1, k = 0;
    int n, i, j, d = 1;

    // Input the number of terms in the table
    printf("Enter the number of terms in the table: ");
    scanf("%d", &n);

    // Input the values of variable 'x'
    printf("Enter the respective values of the variable 'x':\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    // Input the values of variable 'y'
    printf("Enter the respective values of the variable 'y':\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    // Display the entered table
    printf("The table you entered is as follows:\n");
    for (i = 0; i < n; i++) {
        printf("%f\t%f\n", x[i], y[i]);
    }

    // Infinite loop to allow multiple interpolations
    while (d == 1) {
        // Input the value of 'x' to find the respective value of 'y'
        printf("Enter the value of 'x' to find the respective value of 'y':\n");
        scanf("%f", &a);

        // Lagrange's Interpolation Formula
        for (i = 0; i < n; i++) {
            s = 1;
            t = 1;
            for (j = 0; j < n; j++) {
                if (j != i) {
                    s = s * (a - x[j]);
                    t = t * (x[i] - x[j]);
                }
            }
            k = k + ((s / t) * y[i]);
        }

        // Output the interpolated value of 'y'
        printf("The respective value of the variable 'y' is: %f\n", k);

        // Prompt user to continue or exit
        printf("Do you want to interpolate another value? (Enter 1 for Yes, 0 for No): ");
        scanf("%d", &d);
        
        // Reset k for the next interpolation
        k = 0;
    }

    return 0;
}
