/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:59:09 by codespace         #+#    #+#             */
/*   Updated: 2025/07/30 15:31:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_BAG_HPP
# define TREE_BAG_HPP

#include "bag.hpp"

class bag;

class tree_bag : virtual public bag
{
	protected:
		struct node
		{
			node *l;
			node *r;
			int val;
		};
		node* tree;
		
	public:
		// constructor destructor
		tree_bag();
		tree_bag(const tree_bag&);
		~tree_bag();
		
		// overload
		tree_bag& operator=(const tree_bag&);

		// tree stuff
		node* extract_tree();
		void set_tree(node*);
		
		// mem functs
		void insert(int);
		void insert(int*, int);
		void print();
		void clear();

	private:
		void destroy_tree();
		void print_node();
		node* copy_node();
};

#endif