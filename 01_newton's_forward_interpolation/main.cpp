#include <stdio.h>

void forward(float x[20], float y[20][20], int n){

    int i,j;
    float a = 0.5;
    float h,u,sum,p;

    for(j=1; j<n; j++){
        for(i=0; i<n-j; i++){
            y[i][j] = y[i+1][j-1] - y[i][j-1];
        }
    }

    printf("\n The Forward Difference of the table is:\n");

    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<n-i;j++){
            printf("%f \t", y[i][j]);
        }
    }

    p = 1.0;
    sum = y[0][0];
    h = x[1] - x[0];
    u = (a-x[0])/h;

    for(j=1; j<n; j++){
        p = p*(u-j+1)/j;
        sum = sum+p*y[0][j];
    }

    printf("\n The value of y at x = %0.1f is %0.3f.", a, sum);
}

int main(){
    int i, j, n;
    printf("Enter the number of terms.:");
    scanf("%d", &n);

    float x[20], y[20][20];
    printf("Enter the value of x.:");
    for(i=0; i<n; i++){
        scanf("%f", &x[i]);
    }

    printf("Enter the value of y.:");
    for(j=0; j<n; j++){
        scanf("%f",&y[j][0]);
    }

    forward(x, y, n);
    return 0;
}