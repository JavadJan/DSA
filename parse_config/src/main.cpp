#include "../include/Config.hpp"
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "not file\n";
		return 1;
	}
	try
	{
		/* code */
		std::vector<Config> configs = parserConfig(av[1]);

        for (size_t i = 0; i < configs.size(); ++i)
        {
            printConfig(configs[i]);
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}