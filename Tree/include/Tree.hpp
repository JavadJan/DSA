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
		int height;
	public:
		Node();
		Node(const T &value); // constuctor
		Node(const Node& other);
		Node& operator=(const Node& other);
		~Node();
		// setter
		void setLeft(Node *l);
		void setRight(Node *r);
		void setValue(T val);
		void setHeight(int h);
		// getter
		Node<T>* getLeft() const;
		Node<T>* getRight() const;
		const T& getNode() const;		
		int	getHeight() const; 
};

template <typename T>
class BinaryTree{
	protected:
		Node<T>* root;
		int count(Node<T> *p);
		int sum(Node<T> *p);
		int countLeaf(Node<T> *p);
		void preorder(Node<T>* node);
		void postorder(Node<T>* node);
		void inorder(Node<T>* node);
	public:
		int height(Node<T> *p);
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
class BST : public BinaryTree<T>
{

	private:
		Node<T>* Rsearch(Node<T> *root, int key);
		Node<T>* remove(Node<T> *root, int key);
	protected:
		virtual Node<T>* RInsert(Node<T> *p,const T& key);
	public:
		BST();
		~BST();
		void insert(const T& key);
		// override in AVL, but I didn't because it call another private member function
		virtual void RInsert(const T& key); 
		// remove will be a recursive function
		void remove(int key);
		Node<T> * InPre(Node<T> *node);
		Node<T> * InSucc(Node<T> *node);
		
		T search(int key);
		Node<T>* Rsearch(int key);
		void createBSTfromPreorder(int pre[], size_t size);

};

// AVL is a BST, so it can inhertis from BST
template <typename T>
class AVL : public BST<T>
{
	protected:
		Node<T>* RInsert(Node<T> *p,const T& key) override;
	public:
		AVL();
		~AVL();
		int  nodeHeight(Node<T> *p);
		int  balanceFactor(Node<T> *p);
		Node<T>* LLRotation(Node<T> *p);
		Node<T>* LRRotation(Node<T> *p);
		Node<T>* RRRotation(Node<T> *p);
		Node<T>* RLRotation(Node<T> *p);
		void RInsert(const T& key) override;

};
#include "./Tree.tpp"

#endif