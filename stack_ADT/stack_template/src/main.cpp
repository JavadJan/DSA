#include "../include/Stack.hpp"

struct person{
	std::string name;
	int age;
};

int main()
{
	//t_truck A[3] = {{34, "javad"}, {39, "Reza"}, {33, "Hoseein"}};
	
	//std::cout << "\n\nwith link-list\n";
	Stack<std::string> s0;
	try
	{
		std::string name =  s0.pop();
		s0.push("javad");
		s0.push("najla");
		s0.display();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
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
	
	std::cout << "\n\n-------[TEST POSTFIX:] a + c * d - f/e" << std::endl;

	char* result = convert("a + c * d - f/e");
	std::cout << result << std::endl;
	char* res = convert("a + c * d");
	std::cout << res << std::endl;
	delete[] result;

	Stack<person> p;
	p.push({"javad", 34});
	person pp = p.pop();
	std::cout << pp.name << ", " << pp.age << std::endl;

	std::cout << "\n\n[TEST: ]----------test the bracket\n";
	char *br = InToPostfix_bracket("(a + b) * h - c^d^f");
	std::cout << br << std::endl;

	std::cout << "\n\n[TEST: ]----------test the bracket\n";
	char *postfix = convert("3+4*9");
	std::cout << "res " << postfix << ": " << eval(postfix) << std::endl;
}