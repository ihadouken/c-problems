#include <stdio.h>

/* This is a modified version of hello world that converts a bunch of fahrenheit temperatures converted to their celcius values. */
float F2C(float f);

int main() {
    float fahr, celcius;
    int start, stop, step;
    
    start = 0;  // Start value of temperatures' table.
    stop = 100; // End value of temperatures' table.
    step = 10;  // The difference between successive celcius values.

    fahr = start;
    printf("[Table]: Values for fahrenheit temperatures 0,10,20,30, ... 100 in the celcius scale.\n");
    while (fahr <= stop) {
        celcius = F2C(fahr);
        printf("%3.0f\t%5.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
    return 0;
}

float F2C(float f) {
   return (5.0/9.0) * (f - 32);
}
