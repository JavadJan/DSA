/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:49:56 by codespace         #+#    #+#             */
/*   Updated: 2025/07/31 12:27:30 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_class_includes/searchable_array_bag.hpp"

// constructor destructor ====================================================

searchable_array_bag::searchable_array_bag() : array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other) : array_bag(other) {}

searchable_array_bag::~searchable_array_bag() {}

// overload ====================================================

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other)
{
	if (this != &other)
	{
		this->clear();
		this->data = new int[other.size];
		
		for (int i = 0; i < other.size; i++)
			this->data[i] = other.data[i];
		this->size = other.size;
	}
	return (*this);
}

// mem functs ====================================================

bool searchable_array_bag::has(int input)const
{
	for (int i = 0; i < size; i++)
	{
		if (this->data[i] == input)
			return (true);
	}
	return (false);
}

