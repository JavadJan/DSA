/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:35:21 by tabading          #+#    #+#             */
/*   Updated: 2025/07/31 13:35:02 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_class_includes/set.hpp"

// constructor destructor

set::set(void) : _b(0) {}

set::set(const set& other) 
{
	*this = other;
}

set::set(searchable_bag& other) : _b(&other)
{
}

set::~set() {}

// overload

// set& set::operator=(const set& other) 
// {
// 	return (*this);
// }

// mem functs

searchable_bag* set::get_bag()
{
	return (_b);
}

