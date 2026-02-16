/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:50:34 by codespace         #+#    #+#             */
/*   Updated: 2025/07/31 12:34:51 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

#include "../includes/tree_bag.hpp"
#include "../includes/searchable_bag.hpp"

class tree_bag;
class searchable_bag;

class searchable_tree_bag : virtual public tree_bag, public searchable_bag
{
	protected:

	public:
		// constructor destructor
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag&);
		virtual ~searchable_tree_bag();
		
		// overload
		searchable_tree_bag& operator=(const searchable_tree_bag&);

		// mem functs
		bool has_recursive(node* node, int target)const;

		bool has(int)const;
};
	

#endif