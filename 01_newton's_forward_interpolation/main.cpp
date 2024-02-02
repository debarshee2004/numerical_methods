#include <stdio.h>

/**
 * The function forward calculates the forward difference table for a given set of x and y values,
 * and then uses the table to interpolate the y-value at a specified point (a).
 * @param x - An array containing the x values.
 * @param y - A 2D array representing the y values. y[i][0] corresponds to the initial function values.
 * @param n - The number of terms or data points.
 */
void forward(float x[20], float y[20][20], int n) {
    int i, j;
    float a = 0.5;
    float h, u, sum, p;

    // Calculate the Forward Difference Table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
            // printf(" i=%d , j=%d, y=%f \n",i,j,y[i][j]);
        }
    }

    printf("\n The Forward Difference of the table is:\n");

    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n - i; j++) {
            printf("%f \t", y[i][j]);
        }
    }

    // Interpolate the y-value at the specified point (a) using the Forward Difference Table
    p = 1.0;
    sum = y[0][0];
    h = x[1] - x[0];
    u = (a - x[0]) / h;

    for (j = 1; j < n; j++) {
        p = p * (u - j + 1) / j;
        sum = sum + p * y[0][j];
        // printf(" i=%d , j=%d, p=%f, sum=%f \n",i,j,p,sum);
    }

    printf("\n The value of y at x = %0.1f is %0.3f.", a, sum);
}

/**
 * The main function takes user input for the number of terms, x values, and y values,
 * and then calls the forward function to perform interpolation and display the result.
 * @return 0 indicating successful execution.
 */
int main() {
    int i, j, n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    float x[20], y[20][20];
    printf("Enter the value of x: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the value of y: ");
    for (j = 0; j < n; j++) {
        scanf("%f", &y[j][0]);
    }

    forward(x, y, n);
    return 0;
}
