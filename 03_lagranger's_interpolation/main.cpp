#include <stdio.h>

int main(){
    float x[100], y[100], a, s=1, t=1, k=0;
    int n, i, j, d=1;

    printf("Enter the terms in the table");
    scanf("%d", &n);

    printf("Enter the respective values of the variable `x`:\n");
    for(i=0; i<n; i++){
        scanf("%f",&x[i]);
    }

    printf("Enter the respective values of the variable `y`:\n");
    for(i=0; i<n; i++){
        scanf("%f",&y[i]);
    }

    printf("Enter the table you entered is as follows:\n");
    for(i=0; i<n; i++){
        printf("%f\t%f\n", x[i], y[i]);
    }

    while(d==1){
        printf("Enter the value of the `x` to find the respective value of `y`:\n");
        scanf("%f", &a);
        for(i=0; i<n; i++){
            s=1;
            t=1;
            for(j=0; j<n; j++){
                if(j!=1){
                    s=s*(a-x[j]);
                    t=t*(x[i]-x[j]);
                }
            }
            k=k+((s/t)*y[i]);
        }
        printf("The respective value of the variable `y` is: %f", k);
    }
}