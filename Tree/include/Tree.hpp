#ifndef Tree_hpp
# define Tree_hpp

#include <iostream> // std::cout
#include <queue> // using stakc to track the node
#include <stack>
#include <cstdint>

//template <typename T>
//struct Node{
//	T value;
//	struct Node* left;
//	struct Node* right; // take idea from this struct ot build your tree
//	Node(): left(nullptr), right(nullptr){}
//};



template <typename T>
class Node{
	private:
		T value;
		Node<T> *left; // points to a data type of itself type
		Node<T> *right; // points to a datatype of itself type, it is Node

	public:
		Node();
		Node(const T &value); // constuctor
		Node(const Node& other);
		~Node();
		// setter
		void setLeft(Node *l);
		void setRight(Node *r);
		// getter
		Node<T>* getLeft() const;
		Node<T>* getRight() const;
		const T& getNode() const;		
		
};

template <typename T>
class BinaryTree{
	protected:
		Node<T>* root;
		int height(Node<T> *p);
		int count(Node<T> *p);
		int sum(Node<T> *p);
		int countLeaf(Node<T> *p);
		void preorder(Node<T>* node);
		void postorder(Node<T>* node);
		void inorder(Node<T>* node);
	public:
		BinaryTree();
		virtual ~BinaryTree();
		void FillBinary();

		// display in tree ways: preorder, inorder, postorder; 
		void iterativeInorder();
		void iterativePostorder();

		/* recursively: */
		void preorder();
		void postorder();
		void inorder();

		void printfPreOrder();
		int countLeaf();
		int height();
		int sum();

		
};


template <typename T>
class BST : public BinaryTree<T>{

	public:
		BST();
		~BST();
		void build();
		void insert();
		void remove();
		void search();
};

#include "./Tree.tpp"

#endif