#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) ((x*x*x)-x-4)

int main(){
    float a, b, c, h;

    printf("Enter the value of a and b: \n");
    scanf("%f", &a);
    scanf("%f", &b);

    if(f(a)*f(b) > 0){
        return 0;
    }
    else{
        do{
            c = (a+b)/2;
            if(f(c)<0){
                a=c;
            }
            else{
                b=c;
            }
            h=(b+a)/2;
            printf("%f\n", h);
        }while(fabs(h-c)>0.001);
        printf("\nThe root is %f\n", h);
    }
}