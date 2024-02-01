#include <stdio.h>
#include <math.h>

/**
 * The program calculates the numerical integration of a function using the trapezoidal rule.
 * The function to be integrated is defined as f(x) = 1 / (1 + x^2).
 */
#define f(x) 1 / (1 + pow(x, 2))

int main() {
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    // Input the lower limit of integration
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);

    // Input the upper limit of integration
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);

    // Input the number of intervals
    printf("Enter number of intervals: ");
    scanf("%d", &subInterval);

    // Calculate the step size
    stepSize = (upper - lower) / subInterval;

    // Trapezoidal rule for numerical integration
    integration = f(lower) + f(upper);
    for (i = 1; i < subInterval; i++) {
        k = lower + i * stepSize;
        integration += 2 * f(k);
    }

    integration = integration * stepSize / 2;
    printf("\nRequired value of integration is: %0.3f", integration);

    return 0;
}
