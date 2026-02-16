/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:51:42 by tabading          #+#    #+#             */
/*   Updated: 2025/07/25 17:03:14 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>

// unsigned = not negativ => null check
class bigint
{
	private:
		std::string _num;

	public:
	// constructor
		bigint(void);
		bigint(long long num);
		bigint(const bigint& b);
	// destructor
		~bigint(void);

	// operator overload
		// assign
		bigint& operator=(const bigint& b);
		bigint& operator+=(const bigint& b);
		bigint& operator<<=(int shift);
		bigint& operator>>=(const bigint& b);
		// addition
		bigint operator+(const bigint& b)const;
		bigint& operator++(void);
		bigint operator++(int);
		// digitshift
		bigint operator<<(int shift);
		bigint operator>>(int shift);
		// comparison
		bool operator==(const bigint& b);
		bool operator!=(const bigint& b);
		bool operator<(const bigint& b);
		bool operator<=(const bigint& b);
		bool operator>(const bigint& b);
		bool operator>=(const bigint& b);

	// helper
		// get set
		std::string getter(void)const;
		void setter(const std::string& num);
		// string math
		void addition(const std::string& num);
		void add(int amount);
		void take(int amount);

};

int	nbr_len(int n);
std::string	ft_itoa(unsigned int n);
std::ostream& operator<<(std::ostream& o, const bigint& b);

#endif