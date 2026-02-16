#include <stdio.h>

int mul(int a, int b)
{
	return (a * b);
}

int add(int a, int b)
{
	int sum = a + b;
	return (sum);
}

void exec(int (*func)(int, int))
{
	printf("get:%d\n", func(4 , 5));	
}

int main()
{
	//int (*func)(int, int);
	//func = &add;
	//printf("sum: %d", func(2, 4));
	exec(&mul);
	exec(&add);
	return (0);
}
