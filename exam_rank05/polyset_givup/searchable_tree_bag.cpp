/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:05:23 by tabading          #+#    #+#             */
/*   Updated: 2025/07/31 12:10:15 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_class_includes/searchable_tree_bag.hpp"

// constructor destructor
searchable_tree_bag::searchable_tree_bag(void) : tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other) {}

searchable_tree_bag::~searchable_tree_bag(void) {}

// overload

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
	{
		clear();
		set_tree(other.tree);
	}
	return (*this);
}

// mem functs

bool searchable_tree_bag::has_recursive(node* node, int target) const 
{
	if (!node) 
		return (false);
	if (target == node->val) 
		return (true);
	if (target < node->val)
		return (has_recursive(node->l, target));
	else
		return (has_recursive(node->r, target));
}

bool searchable_tree_bag::has(int input)const
{
	return (has_recursive(this->tree, input));
}



