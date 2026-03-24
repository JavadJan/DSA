
# include "../includes/bag.hpp"
# include "../includes/array_bag.hpp"
# include "../includes/tree_bag.hpp"
# include "../includes/searchable_bag.hpp"
# include "../includes/searchable_tree_bag.hpp"
# include "../includes/searchable_array_bag.hpp"
# include "../includes/set.hpp"
# include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);

	std::cout << "\033[1;33m─── [Constructor test] ─────────\033[0m\n\n";
	    
	searchable_bag *a = new searchable_array_bag;
	searchable_bag *t = new searchable_tree_bag;

	std::cout << "\n\033[1;33m─── [Insert test] ─────────\033[0m\n\n";
	for (int i = 1; i < argc; i++)
	{
		a->insert(atoi(argv[i]));
		t->insert(atoi(argv[i]));
	}
	    
	std::cout << "\n\033[1;33m─── [Print test] ─────────\033[0m\n\n";
	a->print();
	t->print();

	std::cout << "\n\033[1;33m─── [Has test] ─────────\033[0m\n\n";
	for (int i = 1; i < argc; i++)
	{
		std::cout << "a, check for " << atoi(argv[i]) << "| " << a->has(atoi(argv[i])) << std::endl;
		std::cout << "t, check for " << atoi(argv[i]) << "| " << t->has(atoi(argv[i])) << std::endl;
	}
	std::cout << "a, check for " << 22 << "| " << a->has(22) << std::endl;
	std::cout << "t, check for " << 22 << "| " << t->has(22) << std::endl;

	std::cout << "\n\033[1;33m─── [Clear test] ─────────\033[0m\n\n";
	a->clear();
	t->clear();
		
	std::cout << "\n\033[1;33m─── [Make tmp test] ─────────\033[0m\n\n";
	const searchable_array_bag tmp(static_cast <searchable_array_bag&>(*a));
	set sa(*a);

	delete a;
	delete t;
	/*
	set st(*t);
	
	for (int i = 1; i < argc; i++)
	{
		sa->insert(atoi(argv[i]));
		st->insert(atoi(argv[i]));
	}

	sa.has(atoi(argv[1]));
	sa.print();
	sa.get_bag.print();
	st.print();
	sa.clear();

	int arr[] = {1, 2, 3, 4};
	sa.insert(arr, 4);
	*/
	return (0);
}