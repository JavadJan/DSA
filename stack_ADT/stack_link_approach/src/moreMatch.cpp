#include <iostream>
#include "../include/Stack.hpp"

//str[] = "{({}){}[]()}" ;
bool ValidParanthesis(char *exp)
{
	Stack st;

	for (size_t i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
		{
			char c = exp[i];
			struct st_list lst = {0, c, NULL};
			st.push(lst);
			st.display();
			std::cout << "---------\n" << std::endl;
		}
		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if (st.isEmpty()) return false;
			std::string p = st.pop();
			//st.display();
			std::cout << p << exp[i] << " remove: " <<p  << std::endl;
			if ((exp[i] - p[0] > 2))
			{
				std::cout << exp[i] <<", " <<p << " " << exp[i] - p[0] << std::endl;
				return false;
			}
		}
	}
	return (st.isEmpty() ? true : false);
}