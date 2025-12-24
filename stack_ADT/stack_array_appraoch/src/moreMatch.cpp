#include <iostream>
#include "../include/Stack.hpp"

//str[] = "{({}){}[]()}" ;
bool ValidParanthesis(char *exp)
{
	t_data data = {};
	Stack st(strlen(exp));

	for (size_t i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
		{
			char c = exp[i];
			st.push({0, strdup(&c)});
			st.display();
			std::cout << "---------\n" << std::endl;
		}
		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if (st.isEmpty()) return false;
			data = st.pop();
			//st.display();
			std::cout << data.name[0] << exp[i] << " remove: " <<data.name[0]  << std::endl;
			if ((exp[i] - data.name[0] > 2))
			{
				std::cout << exp[i] <<", " << data.name[0] << " " << exp[i] - data.name[0] << std::endl;
				return false;
			}
		}
	}
	return (st.isEmpty() ? true : false);
}