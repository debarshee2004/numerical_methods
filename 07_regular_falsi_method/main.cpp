#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (pow(x,3) - (9*x) + 1)

int main(){
    float a, b, c, d, h;
    printf("Enter the value of a:");
    scanf("%f", &a);
    printf("\nEnter the value of b:");
    scanf("%f", &b);

    if(f(a)*f(b)>0){
        return 0;
    }else{
        do{
            c=a-((f(a)*(b-a))/(f(b)-f(a)));

            if(f(c)>0){
                a=c;
            }else{
                b=c;
            }

            h=a-((f(a)*(b-a))/(f(b)-f(a)));
            printf("%f\n", h);
        }while(fabs(h-c)>0.0001);
        printf("\n%f",h);
    }
    return 0;
}