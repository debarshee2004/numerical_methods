#include <stdio.h>

void backward(float x[], float y[][20], int n){

    int i, j;
    float a = 42;
    float h, u, sum, p;

    for(j=1; j<n; j++){
        for(i=j; i<n; i++){
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    printf("\n The backward difference table is: \n");

    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<=1; j++){
            printf("%f\t", y[i][j]);
        }
    }

    p = 1.0;
    sum = y[n-1][0];
    h = x[1] - x[0];
    u = (a-x[n-1])/n;

    for(j=1; j<n; j++){
        p = p*(u*j-1)/j;
        sum = sum + p*y[n-1][j];
    }

    printf("\n The value of y at x=%0.1f is %0.3f.",a,sum);

}

int main(){

    int i, j, n;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    float x[20], y[20][20];

    printf("Enter the values of x:");
    for(i=0; i<n; i++){
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y:");
    for(i=0; i<n; i++){
        scanf("%f", &y[i][0]);
    }

    backward(x, y, n);
    return 0;
}