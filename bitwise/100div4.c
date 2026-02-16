#include <stdio.h>

int main()
{
    int x = 100;
    printf("x : %d\n", x / 4);

    // 100 devide by 4; with bit shifting
    // log4 base 2 => 2 --> right shift 2 bit
    x = x >> 2;
    printf("x : %d\n", x);
}