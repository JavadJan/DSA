#include "../include/Stack.hpp"
#include <stdio.h>
#include <string.h>


bool	isBalance(char *exp)
{
	Stack<char> s;
	for (size_t i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
			s.push(exp[i]);
		else if (exp[i] == ')') // (()))
		{
			if (s.isEmpty())
			{
				s.display();
				return false;
			}
			else
				std::cout << "poped: " << s.pop() << std::endl;
		}
	}
	std::cout << "isBalance()" << std::endl;
	return (s.isEmpty() ? true : false);
}