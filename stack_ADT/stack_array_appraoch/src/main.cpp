#include "../include/Stack.hpp"

int main()
{
	//t_truck A[3] = {{34, "javad"}, {39, "Reza"}, {33, "Hoseein"}};
	
	Stack s(3);
	if(s.isEmpty())
		std::cout << "stack is empty\n";
	s.push({34, "javad"});
	s.push({39, "Reza"});
	s.push({33, "Hoseein"});
	s.pop();
	if (s.isFull())
		std::cout << "stack is full\n";
	s.display();

	
	std::cout << "\n\n---------------------\n";
	/* Match paranthesis */
	char exp[] = "{({}){}[]()}" ;
	if (isBalance(exp))
		std::cout << "Matched ()" << std::endl;
	else
		std::cout << "Not Matched ()" << std::endl;

	char str[] = "{({}){}[]()}" ;
	if (ValidParanthesis(str))
		std::cout << "match " << std::endl;
	else
		std::cout << "No Matched" << std::endl;
}