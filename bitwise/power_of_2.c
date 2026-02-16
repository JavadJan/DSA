#include <stdio.h>

int power_of_2(int n)
{
    int res = 1;
    int i = 1;
    if ((n & (n - 1)) == 0) // if the n was power of 2 e,g., 2, 4, 8, 16 
        return n;
    while (res < n)
        res = res << 1;
    return (res);
}

int main()
{
    int x;


    x = power_of_2(10);
    printf("power of x: %d\n", x);
}

//1 → 2 → 4 → 8 → 16 (stops because 16 ≥ 10).
// least power of 2 that is grather than n
