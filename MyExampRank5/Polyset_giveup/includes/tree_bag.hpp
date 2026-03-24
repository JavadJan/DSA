#ifndef TREE_BAG_HPP
# define TREE_BAG_HPP
# include <iostream>
#include "bag.hpp"
class bag;
class tree_bag : virtual public bag{
	protected:
		struct Node
		{
			int val;
			struct Node* left;
			struct Node* right;
		};
		
		Node* root;
		Node* copy(Node* tree);
		Node* RInsert(Node* p, int key);
		void inorder(Node* tree) const;
		void destroy(Node* &p);

	public:
		tree_bag();
		virtual ~tree_bag();
		tree_bag(const tree_bag& b);
		tree_bag& operator=(const tree_bag& b);

		void insert(int val);
		void insert(int *, int);
		void clear();
		void print() const;
};

#endif