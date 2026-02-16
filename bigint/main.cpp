#include "./Bigint.hpp"

int main()
{
	const Bigint a(42);
	Bigint b(21), c, d(1337), e(d);

	std::cout << "\033[1;36m [PRINT ALL VARS] \033[0m" << std::endl;
	std::cout << "a " << a << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "c " << c << std::endl;
	std::cout << "d " << d << std::endl;
	std::cout << "e " << e << std::endl;

	
}