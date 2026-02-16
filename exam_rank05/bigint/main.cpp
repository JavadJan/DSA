/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:49:07 by tabading          #+#    #+#             */
/*   Updated: 2025/07/29 13:46:03 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp"

/*
create a class bigint that will store an arbitrary precicion unsigned int.
your class must support addition, comparison, digit shifting.
- printable with << no leading 0.
*/

int main(void)
{
	const bigint a(42);
	bigint b(21), c, d(1337), e(d);

	std::cout << "\033[1;36m [PRINT ALL VARS] \033[0m" << std::endl;
	std::cout << "a " << a << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "c " << c << std::endl;
	std::cout << "d " << d << std::endl;
	std::cout << "e " << e << std::endl;
	
	std::cout << "\033[1;36m [TEST OVERRIDES] \033[0m" << std::endl;
	std::cout << "(a + b) = " << a + b << " | (63)" << std::endl; // operator+
	std::cout << "(c += a) = " << (c += a) << " | (42)" << std::endl; // operator++(int)
	
	
	std::cout << "\033[1;36m [TEST INC DEC] \033[0m" << std::endl;
	std::cout << b++ << " | print (21) is (22)" << std::endl; // operator+(void)
	std::cout << ++b << " | print (23) is (23)" << std::endl; // operator+(int)
	
	
	std::cout << "\033[1;36m [TEST DIGIT SHIFTING] \033[0m" << std::endl;
	std::cout << "((b << 10) + 42) = " << (b << 10) + 42 << " | (230000000042)" << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << " | (13370000)" << std::endl;
	std::cout << "(d >>= (const bigint)2) = " << (d >>= (const bigint)2) << " | (133700)" << std::endl;


	std::cout << "\033[1;36m [TEST UBERSCHLAG] \033[0m" << std::endl;
	b = 99;
	c = 10;
	std::cout << "b " << b << std::endl;
	std::cout << "c " << c << std::endl;
	std::cout << "(b + c) = " << (b + c) << " | (109)" << std::endl;
	
	
	std::cout << "\033[1;36m [TEST COMPARISON] \033[0m" << std::endl;
	std::cout << "d " << d << std::endl;
	std::cout << "a " << a << std::endl;
	if (d < a)
		std::cout << "(d < a) true" << std::endl;
	else
		std::cout << "(d < a) false" << std::endl;
	if (d > a)
		std::cout << "(d > a) true" << std::endl;
	else
		std::cout << "(d > a) false" << std::endl;
	if (d == a)
		std::cout << "(d == a) true" << std::endl;
	else
		std::cout << "(d == a) false" << std::endl;
	if (d != a)
		std::cout << "(d != a) true" << std::endl;
	else
		std::cout << "(d != a) false" << std::endl;
	if (d <= a)
		std::cout << "(d <= a) true" << std::endl;
	else
		std::cout << "(d <= a) false" << std::endl;
	if (d >= a)
		std::cout << "(d >= a) true" << std::endl;
	else
		std::cout << "(d >= a) false" << std::endl;
	
	return(0);
}