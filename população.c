//população

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int população = get_int("n: ");

    float a = (float) população / 3;

    float b = (float) população / 4;

    float y = (float) população + (float) a - (float) b;

    printf("%f\n", y);
}