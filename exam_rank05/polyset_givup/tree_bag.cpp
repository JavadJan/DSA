/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:05:30 by codespace         #+#    #+#             */
/*   Updated: 2025/07/30 15:59:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tree_bag.hpp"

/* 
approximately like this in functionality, i didn't have the time to 
write down this file >:(. remember to copy it next time !!!!!!
*/

// constructor destructor ====================================================

tree_bag::tree_bag(void) : tree(0) {}

tree_bag::tree_bag(const tree_bag& other) : tree(0)
{
	set_tree(other.tree);
}

tree_bag::~tree_bag(void)
{
	destroy_tree();
}

// overload ====================================================

tree_bag& tree_bag::operator=(const tree_bag& other)
{
	if (this != &other)
	{
		clear();
		set_tree(other.tree);
	}
	return (*this);
	
}

// tree stuff ====================================================

tree_bag::node* tree_bag::extract_tree(void) 
{ 
	return (this->tree);
}

void tree_bag::set_tree(node* other) 
{
	if (!other)
		return ;
	insert((other->val));
	set_tree(other->l);
	set_tree(other->r);
}

// mem functs ====================================================

void tree_bag::insert(int val)
{
	node** tmp = &this->tree;

	while((*tmp))
	{
		if (val < (*tmp)->val )
			tmp = &(*tmp)->l;
		else 
			tmp = &(*tmp)->r;
	}
	node* n = new node;
	n->r = 0;
	if ((*tmp) && (*tmp)->l)
		n->r = (*tmp)->l;
	n->l = 0;
	if ((*tmp) && (*tmp)->r)
		n->l = (*tmp)->r;
	n->val = val;
	(*tmp) = n;

	// maby delete?
}

void tree_bag::insert(int* a, int amount)
{
	for (int i = 0; i < amount; i++)
		this->insert(a[i]);
}

void tree_bag::print(void)
{
	node** t = &this->tree;

	while ((*t)->l)
		t = &(*t)->l;
	while ((*t))
	{
		std::cout << (*t)->val << " ";
		t = &(*t)->r;
	}
	std::cout << std::endl;
}

void tree_bag::clear(void)
{
	this->destroy_tree();
}

// priv ==================================================== 

void tree_bag::destroy_tree(void)
{
	node* t;
	
	while (tree->l)
		tree = tree->l;
	
	while (this->tree)
	{
		t = this->tree;
		this->tree = this->tree->r;
		delete t;
	}
	this->tree = 0;
}

void tree_bag::print_node(void)
{
	std::cout << this->tree->val << std::endl;
}

tree_bag::node* tree_bag::copy_node(void)
{
	if (!this->tree)
		return (0);
	
	node* n = new node;
	n->l = 0;
	n->r = 0;
	n->val = this->tree->val;

	return (n);
}
