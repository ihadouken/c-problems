#include <stdio.h>

#define START 0
#define STEP 10
#define STOP 100

int main() {
    int celcius;
    printf("\033[1;31m[Table]: Fahrenheit values for celius temeratures 0,10,20,30 ... 100\033[0m\n");

    for (celcius = START; celcius <= STOP; celcius += STEP) {
        printf("%3d  ->  %5.1f\n", celcius, ((9.0/5.0)*celcius) + 32);
    }

    return 0;
}
