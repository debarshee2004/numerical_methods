#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * The program implements the Fourth Order Runge-Kutta method to solve a first-order ordinary
 * differential equation (ODE).
 * The ODE is defined as f(x, y) = (y^2 - x^2) / (y^2 + x^2).
 */

#define f(x, y) (y*y - x*x) / (y*y + x*x)

int main() {
    float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
    int i, n;

    // Input initial condition
    printf("Enter Initial Condition (x0 y0): \n");
    scanf("%f %f", &x0, &y0);

    // Input calculation point
    printf("Enter calculation point (xn): \n");
    scanf("%f", &xn);

    // Input the number of steps
    printf("Enter the number of steps: \n");
    scanf("%d", &n);

    // Calculate step size
    h = (xn - x0) / n;

    printf("\tx0\t\ty0\t\tyn\n");

    for (i = 0; i <= n; i++) {
        // Runge-Kutta method
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        // Update y0 and x0
        yn = y0 + k;
        printf("\t%f\t%f\t%f\n", x0, y0, yn);
        x0 = x0 + h;
        y0 = yn;
    }

    printf("\nValue of y at x = %f is %f.\n", xn, yn);
    return 0;
}
