#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    a = a ^ b; // ^ XOR
    b = a ^ b;
    a = a ^ b;
    printf("a: %d and b: %d\n", a, b);
}

/* 
int a = 6;
int b = 3

1) a = a ^ b; 
	5 XOR 3 =>	0101 == 5
				0011 == 3
				0110 == 6
	a = 6;

2) b = a ^ b;
	6 XOR b =>	0110
				0011
				b = 0101 = 5

3) a = a ^ b =>	0110
				0101
				a = 0011 = 3

XOR is used bitwise to swap two number

*/