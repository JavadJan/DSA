#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

#include "./searchable_bag.hpp"
#include "./tree_bag.hpp"

class tree_bag;
class searchable_bag;

class searchable_tree_bag: public tree_bag, public searchable_bag
{
	private:
		bool has_recursive(Node* root, int key) const;

	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag& b);
		searchable_tree_bag& operator=(const searchable_tree_bag& b);
		virtual ~searchable_tree_bag();

		bool has(int) const;
};

#endif