/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:09:39 by tabading          #+#    #+#             */
/*   Updated: 2025/07/25 17:13:15 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp"

// constructor ================================

bigint::bigint(void) : _num("0") {}
bigint::bigint(long long num)
{
	if (num < 0) 
		setter("0");
	else
		setter(ft_itoa(num));
}
bigint::bigint(const bigint& b) {	*this = b; }

// destructor ================================

bigint::~bigint(void) {}

// operator overload ================================

// assign
bigint& bigint::operator=(const bigint& b)
{
	if (this != &b)
		setter( b.getter() );
	return (*this);
}


// helper ================================

// get set

std::string bigint::getter(void)const {	return (this->_num); }
void bigint::setter(const std::string& num) {	this->_num = num; }

// string math

void bigint::addition(const std::string& num)
{
	std::string one = this->getter();
	std::string two = num;
	std::string res;
	int i = 0;
	int len;

	if (one.length() > two.length())
	{
		len = one.length();
		while (two.length() < one.length())
			two.insert(0, "0");
	}
	else
	{
		len = two.length();
		while (one.length() < two.length())
			one.insert(0, "0");
	}

	i = len - 1;
	int e = 0;
	while (i >= 0)
	{
		int r((one[i] - '0') + (two[i] - '0') + e);
		e = 0;
		if (r > 9)
		{
			e = 1;
			r -= 10;
		}
		char bb[2] = { '0', 0};
		bb[0] = r + '0';
		res.insert(0, bb);
		i--;
	}
	if (e == 1)
		res.insert(0, "1");
	setter(res);
}

void bigint::add(int amount)
{
	int i = 0;

	while (i < amount)
	{
		this->_num.append("0");
		i++;
	}
}

void bigint::take(int amount)
{
	int len = this->_num.length() - 1;

	this->_num.erase(len - amount, amount);
}


// non class ================================

int	nbr_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

std::string	ft_itoa(unsigned int n)
{
	std::string	ptr;
	std::string base = "0123456789";
	int i = 0;
	int len = nbr_len(n);

	while (i < len)
	{
		ptr.append("0");
		i++;
	}
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		if (n > 0)
			ptr[--len] = base[n % 10];
		else
			ptr[--len] = base[n % 10 * -1];
		n /= 10;
	}
	return (ptr);
}

std::ostream& operator<<(std::ostream& o, const bigint& b)
{
	o << b.getter();
	return (o);
}

//std::stringstream ss(n);
