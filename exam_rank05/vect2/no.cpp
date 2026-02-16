/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:05:22 by codespace         #+#    #+#             */
/*   Updated: 2025/07/17 17:03:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vect2.hpp"

/*
CONTENT

- constructor
- destructor
- copy overload 
- getter 
- setter 
- print overloads
*/

//  constructor

vect2::vect2(void) : _num0(0), _num1(0) {}

vect2::vect2(int num0, int num1) : _num0(num0), _num1(num1) {}

vect2::vect2(const vect2& b) { *this = b; }

// destructor

vect2::~vect2(void) {}

// copy overload 

vect2&	vect2::operator=(const vect2& b)
{
	if (this != &b)
	{
		setN0(b.getN0());
		setN1(b.getN1());
	}
	return (*this);
}

// getter

int		vect2::getN0(void)const { return(this->_num0); }
int		vect2::getN1(void)const { return(this->_num1); }

// setter

void	vect2::setN0(int num) { this->_num0 = num; }
void	vect2::setN1(int num) { this->_num1 = num; }

// print overloads

std::ostream& operator<<(std::ostream& o, const vect2& b)
{
	o << "{" << b.getN0() << ", " << b.getN1() << "}";
	return(o);
}

int&		vect2::operator[](int num)
{
	if (num == 0)
		return (this->_num0);
	return (this->_num1);
}