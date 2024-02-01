#include <stdio.h>

/**
 * The function backward calculates the backward difference table for a given set of x and y values,
 * and then uses the table to interpolate the y-value at a specified point (a).
 * @param x - An array containing the x values.
 * @param y - A 2D array representing the y values. y[i][0] corresponds to the initial function values.
 * @param n - The number of terms or data points.
 */
void backward(float x[], float y[][20], int n) {
    int i, j;
    float a = 42;
    float h, u, sum, p;

    // Calculate the Backward Difference Table
    for (j = 1; j < n; j++) {
        for (i = j; i < n; i++) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    printf("\n The Backward Difference Table is: \n");

    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j <= 1; j++) {
            printf("%f\t", y[i][j]);
        }
    }

    // Interpolate the y-value at the specified point (a) using the Backward Difference Table
    p = 1.0;
    sum = y[n - 1][0];
    h = x[1] - x[0];
    u = (a - x[n - 1]) / n;

    for (j = 1; j < n; j++) {
        p = p * (u * j - 1) / j;
        sum = sum + p * y[n - 1][j];
    }

    printf("\n The value of y at x = %0.1f is %0.3f.", a, sum);
}

/**
 * The main function takes user input for the number of terms, x values, and y values,
 * and then calls the backward function to perform interpolation and display the result.
 * @return 0 indicating successful execution.
 */
int main() {
    int i, j, n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    float x[20], y[20][20];

    printf("Enter the values of x: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }

    backward(x, y, n);
    return 0;
}
