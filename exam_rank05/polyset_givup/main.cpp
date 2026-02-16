/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:08:21 by tabading          #+#    #+#             */
/*   Updated: 2025/07/31 13:40:46 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/bag.hpp"
# include "includes/array_bag.hpp"
# include "includes/tree_bag.hpp"
# include "includes/searchable_bag.hpp"
# include "my_class_includes/searchable_tree_bag.hpp"
# include "my_class_includes/searchable_array_bag.hpp"
# include "my_class_includes/set.hpp"
# include <cstdlib>

/*

============================ just give up ============================

you will find various classes:
	- bag
	- searchable_bag 
	- array_bag 
	- tree_bag 

First part: 
	- implement 2 classes "searchable_array_bag" & "searchable_tree_bag" 
		that will inherit from array_bag & tree_bag respectivly
	- and implement the searchable_bag abstract class

Second part:
	- Implement the class "set" that will wrap a searchable_bag and
		turn it into a set

- You will find a main that must compile with your code
- all your classes must be in canonical orthodox form
- don't forget the consts

*/

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

