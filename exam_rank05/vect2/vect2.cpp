/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:05:22 by codespace         #+#    #+#             */
/*   Updated: 2025/08/01 13:09:30 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vect2.hpp"

/*

CONTENT

- assignment
- increment decrement
- arrithmic
- comp
- not a mem
*/


vect2& vect2::operator+=(const vect2& b)
{
	setN0(getN0() + b.getN0());
	setN1(getN1() + b.getN1());
	return(*this);
}

vect2& vect2::operator-=(const vect2& b)
{
	setN0(getN0() - b.getN0());
	setN1(getN1() - b.getN1());
	return(*this);
}

vect2& vect2::operator*=(const int num)
{
	setN0(getN0() * num);
	setN1(getN1() * num);
	return (*this);
}


// increment decrement

vect2 vect2::operator++(int)
{
	vect2 old = *this;
	this->setN0(this->_num0 + 1);
	this->setN1(this->_num1 + 1);
	return(old);
}

vect2& vect2::operator++(void)
{
	this->setN0(this->_num0 + 1);
	this->setN1(this->_num1 + 1);
	return(*this);
}

vect2 vect2::operator--(int)
{
	vect2 old = *this;
	this->setN0(this->_num0 - 1);
	this->setN1(this->_num1 - 1);
	return(old);
}

vect2& vect2::operator--(void)
{
	this->setN0(this->_num0 - 1);
	this->setN1(this->_num1 - 1);
	return(*this);
}

// arithmetic

vect2 vect2::operator+(const vect2& b)const
{
	vect2 res;
	res.setN0(getN0() + b.getN0());
	res.setN1(getN1() + b.getN1());
	return (res);
}

vect2 vect2::operator-(const vect2& b)const
{
	vect2 res;
	res.setN0(getN0() - b.getN0());
	res.setN1(getN1() - b.getN1());
	return (res);
}

vect2 vect2::operator-(void)const
{
	vect2 res(-getN0(), -getN1());
	return (res);
}

vect2 vect2::operator*(const int num)const
{
	vect2 res;
	res.setN0(getN0() * num);
	res.setN1(getN1() * num);
	return (res);
}

// comp

bool vect2::operator==(const vect2& b) const
{
	if (getN0() == b.getN0() && getN1() == b.getN1())
		return (true);
	return (false);
}

bool vect2::operator!=(const vect2& b) const
{
	return (!(*this == b));
}

// not a mem

vect2 operator*(const int num, const vect2& b)
{
	vect2 res;
	res.setN0(b.getN0() * num);
	res.setN1(b.getN1() * num);
	return (res);
}

int vect2::operator[](int index) const
{
	if(index == 0)
		return(this->_num0);
	return(this->_num1);
}

int& vect2::operator[](int index)
{
	if(index == 0)
		return(this->_num0);
	return(this->_num1);
}