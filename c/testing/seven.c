// celcius to fahrenheit

#include <stdio.h>
void main(){
    float c;
    float f;
    printf("enter the temperature in celcius: ");
    scanf("%f", &c);
    f = c * 1.8 + 32;
    printf("the temperature in fahrenheit is: %f", f);
}