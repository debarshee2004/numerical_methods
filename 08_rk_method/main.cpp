#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x,y) (y*y - x*x)/(y*y + x*x)

int main(){
    float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
    int i, n;

    printf("Enter Initial Condition:\n");
    scanf("%f %f", &x0, &y0);

    printf("Enter calculation point:\n");
    scanf("%f", &xn);
    printf("Enter the number of steps:\n");
    scanf("%d",&n);

    h=(xn-x0)/n;
    printf("\tx0\t\ty0\t\tyn\n");
    for(i=0;i<=n;i++){
        k1=h*(f(x0,y0));
        k2=h*(f((x0+h/2),y0+(k1/2)));
        k3=h*(f((x0+h/2),(y0+(k2/2))));
        k4=h*(f((x0+h),(y0+(k3))));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        yn = y0+h;

        printf("\t%f\t%f\t%f\n", x0, y0, yn);

        x0=x0+h;
        y0=yn;
    }

    printf("\nValue of y at x=%f is %f.", xn, yn);
}