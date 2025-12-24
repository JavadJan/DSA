#include "../include/Stack.hpp"
#include <stdio.h>
#include <string.h>


bool	isBalance(char *exp)
{
	Stack s(strlen(exp));
	for (size_t i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
			s.push("(");
		else if (exp[i] == ')') // (()))
		{
			if (s.isEmpty())
			{
				s.display();
				return false;
			}
			else
				s.pop();
		}
	}
	s.display();
	std::cout << "isBalance()" << std::endl;
	return (s.isEmpty() ? true : false);
}