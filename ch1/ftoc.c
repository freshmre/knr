#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a = 245;
    int b = 10;
    div_t r = div(a, b);
    printf("quotient: %d remainder: %d\n", r.quot, r.rem);
}
