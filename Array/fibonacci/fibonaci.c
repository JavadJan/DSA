#include <stdio.h>

int fibonacci(int num)
{

	if (num == 0 || num == 1)
		return (num);
	else
		return (fibonacci (num - 1) + fibonacci(num - 2));
}

int main()
{
	int n = fibonacci(3);
	printf("result: %d\n", n);
}

/* 
spoudo code: 
fibonacci(int num)
{
	if (num == 0 || num == 1)
		return (num)
	else 
		return (fibonacci(num -1) + fibonacci(num - 2))
}
*/