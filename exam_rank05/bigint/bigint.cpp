/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:09:43 by tabading          #+#    #+#             */
/*   Updated: 2025/07/22 15:28:15 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp"

// operator overload ================================

// assign ---------------------------------

bigint& bigint::operator+=(const bigint& b)
{
	this->addition(b.getter());
	return (*this);
}

bigint& bigint::operator<<=(int shift)
{
	add(shift);
	return (*this);
}

bigint& bigint::operator>>=(const bigint& b)
{
	unsigned int i = 0;
	std::string a = b.getter();
	int shift = 0;

	while (i < a.length())
	{
		shift = shift * 10 + a[i] - '0';
		i++;
	}
	take(shift);
	return (*this);
}

// addition ---------------------------------

bigint bigint::operator+(const bigint& b)const
{
	bigint res(*this);

	res.addition(b.getter());
	return(res);
}

bigint& bigint::operator++(void)
{
	this->addition("1");
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint res = *this;
	this->addition("1");
	return (res);
}

// digitshift ---------------------------------

bigint bigint::operator<<(int shift)
{
	bigint res = *this;

	res.add(shift);
	return (res);
}

bigint bigint::operator>>(int shift)
{
	bigint res = *this;

	res.take(shift);
	return (res);
}

// comparison

bool bigint::operator==(const bigint& b)
{
	if (getter().compare(b.getter()) == 0)
		return (true);
	return (false);
}

bool bigint::operator!=(const bigint& b)
{
	return(!(*this == b));
}

bool bigint::operator<(const bigint& b)
{
	if (getter().compare(b.getter()) > 0)
		return (true);
	return (false);
}

bool bigint::operator<=(const bigint& b)
{
	if (*this == b)
		return (true);
	return ((*this < b));
}

bool bigint::operator>(const bigint& b)
{
	return (!(*this < b));
}

bool bigint::operator>=(const bigint& b)
{
	if (*this == b)
		return (true);
	return ((*this > b));
}
