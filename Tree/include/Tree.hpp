#ifndef Tree_hpp
# define Tree_hpp

#include <iostream> // std::cout
#include <queue> // using stakc to track the node

struct Node{
	int value;
	struct Node* left;
	struct Node* right; // take idea from this struct ot build your tree
};



template <typename T>
class Tree{
	private:
		//std::stack<T> st; // the tree has stack itself internally, the stack should define outside
		T node;
		Tree *left; // points to a data type of itself type
		Tree *right; // points to a datatype of itself type, it is Tree

	public:
		Tree();
		Tree(T &value); // constuctor
		Tree(const Tree& other);
		~Tree();
		// setter
		void setLeft(Tree *l);
		void setRight(Tree *r);
		// getter
		Tree* getLeft();
		Tree* getRight();
		T getNode();
		
		
};

template <typename T>
class BinaryTree{
	private:
		Tree<T>* root;
	public:
		BinaryTree();
		void FillBinary();

		// display in tree ways: preorder, inorder, postorder; 
		void preorder(Tree<T>* node);
		void inorder(Tree<T>* node);
		void postorder(Tree<T>* node);

		void printfPreOrder();
};

#include "./Tree.tpp"

#endif