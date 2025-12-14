#include <iostream>
#include "../include/Stack.hpp"

//str[] = "{({}){}[]()}" ;
bool ValidParanthesis(char *exp)
{
	Stack<char> st;

	for (size_t i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
		{
			st.push(exp[i]);
			//st.display();
			//std::cout << "---------\n" << std::endl;
		}
		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if (st.isEmpty()) return false;
			char p = st.pop();
			//st.display();
			std::cout << p << exp[i] << " remove: " <<p  << std::endl;
			if ((exp[i] - p > 2))
			{
				std::cout << exp[i] <<", " <<p << " " << exp[i] - p << std::endl;
				return false;
			}
		}
	}
	return (st.isEmpty() ? true : false);
}