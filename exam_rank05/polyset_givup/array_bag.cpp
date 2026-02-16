/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:41:10 by codespace         #+#    #+#             */
/*   Updated: 2025/07/30 15:45:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/array_bag.hpp"

// constructor destructor ====================================================

array_bag::array_bag(void) : data(0), size(0) {}

array_bag::array_bag(const array_bag& other)
{
	this->data = new int[other.size];
	
	for (int i = 0; i < other.size; i++)
		this->data[i] = other.data[i];
	this->size = other.size;
}

array_bag::~array_bag() { delete this->data; }

// overload ====================================================

array_bag& array_bag::operator=(const array_bag& other)
{
	this->clear();
	this->data = new int[other.size];
	
	for (int i = 0; i < other.size; i++)
		this->data[i] = other.data[i];
	this->size = other.size;
	return (*this);
}

// mem functs ====================================================

void array_bag::insert(int val)
{
	int* tmp = new int[this->size + 1];
	
	for (int i = 0; i < this->size; i++)
		tmp[i] = this->data[i];
	tmp[this->size] = val;
	delete this->data;
	this->data = tmp;
	this->size++;
}

void array_bag::insert(int* a, int amount)
{
	for (int i = 0; i < amount; i++)
		this->insert(a[i]);
}

void array_bag::print()
{
	for (int i = 0; i < size; i++)
		std::cout << this->data[i] << " ";
	std::cout << std::endl;
}

void array_bag::clear()
{
	delete this->data;
	this->data = 0;
	this->size = 0;
}
