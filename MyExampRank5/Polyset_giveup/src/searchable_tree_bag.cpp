#include "../includes/searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag(){}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& b): tree_bag(b){}

searchable_tree_bag::~searchable_tree_bag(){}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this == &other) return *this; // Self-assignment check
	this->destroy(root);              // Clear existing tree
	root = copy(other.root);          // Deep copy
	return *this;
}


bool searchable_tree_bag::has_recursive(tree_bag::Node* root, int key) const
{
	if (!root)
		return false;
	if (root->val == key)
		return true;
	if (key < root->val)
		return has_recursive(root->left, key);
	else
		return has_recursive(root->right, key);
}

bool searchable_tree_bag::has(int key) const
{
	return this->has_recursive(this->root, key);
}