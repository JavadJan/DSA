#include <stdio.h>

int main()
{
    int i = 1;
    int x = 0;

    while (i < 100)
    {
        x = i & 1;
        if ( x == 0)
            printf("even %d\n", i);
        else
            printf("odd: %d\n", i);
        i++;
    }
}