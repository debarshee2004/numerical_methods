#include<stdio.h>
#include<math.h>

#define f(x) 1/(1+pow(x,2))

int main(){
    float lower, upper, integration=0.0, stepSize, k;
    int i, subInterval;

    printf("Enter lower limit of integration:");
    scanf("%f",&lower);
    printf("\nEnter upper limit of integration:");
    scanf("%f",&upper);
    printf("\nEnter number of intervals:");
    scanf("%d", &subInterval);

    stepSize = (upper - lower)/subInterval;

    integration = f(lower)+f(upper);
    for(i=1; i<=subInterval-1; i++){
        k = lower + i*stepSize;
        if(i%2==0)
            integration += 2*(f(k));
        else
            integration += 4*(f(k));
    }

    integration = integration*stepSize/2;
    printf("\nRequired value of integration is: %0.3f", integration);
    return 0;
}