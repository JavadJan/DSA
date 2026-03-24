#include "../includes/tree_bag.hpp"

tree_bag::tree_bag():root(NULL){}
tree_bag::tree_bag(const tree_bag& b)
{
	root = copy(b.root);
}

tree_bag& tree_bag::operator=(const tree_bag& b)
{
	if (this == &b) return *this; // Self-assignment check
	this->destroy(root);         // Clear existing tree
	root = copy(b.root);         // Deep copy
	return *this;
}

tree_bag::Node* tree_bag::copy(Node* tree)
{
	if (!tree) return NULL;
	Node* newNode = new Node();
	
	newNode->val = tree->val;
	newNode->left = copy(tree->left);
	newNode->right = copy(tree->right);
	return newNode;
}

tree_bag::~tree_bag()
{
	this->destroy(root);
}

void tree_bag::destroy(Node* &root)
{
	if (root == NULL)
	{
		return;
	}
	destroy(root->left);
	destroy(root->right);
	delete root;
	root = NULL;
	// if we do not get the pointer and just in local then 
	// with refrence then the caller's root is still dangeling
}



tree_bag::Node* tree_bag::RInsert(Node *tree, int key)
{
	if (tree == NULL)
	{
		struct Node *t = new struct Node;
		t->val = key;
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	if (tree->val < key)
		tree->right = RInsert(tree->right, key);
	else if (tree->val > key)
	{
		tree->left = RInsert(tree->left, key);
	}
	return tree;
}

void tree_bag::insert(int val)
{
	this->root = this->RInsert(this->root, val);
}

void tree_bag::insert(int *a, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		this->insert(a[i]);
	}
	
}
void tree_bag::inorder(Node *p) const
{
	if (!p) return;
	inorder(p->left);
	std::cout << p->val << " ";
	inorder(p->right);
}

void tree_bag::print() const
{
	this->inorder(this->root);
}

void tree_bag::clear()
{
	this->destroy(this->root);
}