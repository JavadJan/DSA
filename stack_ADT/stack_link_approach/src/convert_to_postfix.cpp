#include "../include/Stack.hpp"

int isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 0;
	return 1;
}

int prec(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
}
char *convert(char *infix)
{
	struct Stack st;
	int i,j=0;
	char *postfix = new char[strlen(infix) + 1];
	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (prec(infix[i]) > prec(st.stackTop()[0]) || st.isEmpty())
			{

				st.push(infix[i++])
			}
		}
	}
	
}