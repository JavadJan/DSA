#include <stdio.h>
#include <stdlib.h>

typedef struct stack_in_c
{
	int top;
	size_t size;
	int *S;
} t_stack;

void create()
{
	t_stack st;
	printf("Enter the size of stack: ");
	scanf("%d", st.size);
}

int main()
{
	create();
}