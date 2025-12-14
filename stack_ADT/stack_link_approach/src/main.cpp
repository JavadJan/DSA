#include "../include/Stack.hpp"

int main()
{
	//t_truck A[3] = {{34, "javad"}, {39, "Reza"}, {33, "Hoseein"}};
	
	//std::cout << "\n\nwith link-list\n";
	Stack s0;
	std::string name =  s0.pop();
	s0.push({34, "javad", NULL});
	s0.push({5, "najla", NULL});
	s0.display();
	std::cout << "\n\n---------------------\n";
	/* Match paranthesis */
	char exp[] = "({({}){}[]()}()" ;
	if (isBalance(exp))
		std::cout << "Matched ()" << std::endl;
	else
		std::cout << "Not Matched ()" << std::endl;

	char str[] = "({({}){}[]()}{}())" ;
	if (ValidParanthesis(str))
		std::cout << "match " << std::endl;
	else
		std::cout << "No Matched" << std::endl;
}