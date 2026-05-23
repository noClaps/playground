#include <stdio.h>

const double FREEZING_PT = 32.0;
const double SCALE_FACTOR = 5.0 / 9.0;

int main() {
    printf("Enter Fahrenheit temperature: ");

    double input;
    scanf("%lf", &input);

    double celcius = (input - FREEZING_PT) * SCALE_FACTOR;
    printf("Celsius equivalent: %.1lf\n", celcius);
}
