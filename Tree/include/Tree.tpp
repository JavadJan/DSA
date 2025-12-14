#include "./Tree.hpp"

template <typename T>
Tree<T>::Tree():left(NULL),right(NULL){

}

template <typename T>
Tree<T>::Tree(T &value):node(value), left(NULL), right(NULL){} // constuctor

template <typename T>
Tree<T>::~Tree(){}

template <typename T>
Tree<T>::Tree(const Tree &other): node(other.node), left(other.left), right(other.right)
{

}

// setter
template <typename T>
void Tree<T>::setLeft(Tree *l){this->left = l;}
template <typename T>
void Tree<T>::setRight(Tree *r){this->right = r;}

// getter
template <typename T>
T Tree<T>::getNode()
{
	return node;
}
template <typename T>
Tree<T>* Tree<T>::getLeft(){return left;}
template <typename T>
Tree<T>* Tree<T>::getRight(){return right;}

// fill tree
template <typename T>
BinaryTree<T>::BinaryTree():root(nullptr)
{

}
template <typename T>
void BinaryTree<T>::FillBinary()
{
	std::queue<Tree<int> *> q;// a Q of pointer of object tree
	int x = -1;
	std::cout << "enter root: " << std::endl;
	std::cin >> x;

	if (x == -1)
		return;

	root = new Tree<T>(x); // create obj of tree
	 // how add left and right? p.set

	q.push(root);
	
	while (!q.empty())
	{
		Tree<T>* p = q.front();
		q.pop(); // add level by level

		std::cout << "Enter Left child for " << p->getNode() << std::endl;
		std::cin >> x;
		if (x != -1)
		{
			Tree<T> *t = new Tree<T>(x); // created
			q.push(t); // added to queue to track
			p->setLeft(t); // add to the left
		}
		std::cout << "Enter Right Child for " << p->getNode() << std::endl;
		std::cin >> x;
		if (x != -1)
		{
			Tree<int> *t = new Tree<T>(x);
			q.push(t);
			//p.setRight(t); // add right;
			p->setRight(t);
		}
	}
	
}
// display the tree in preorder, in order, and postorder recurively
template <typename T>
void BinaryTree<T>::preorder(Tree<T> * node)
{
	if (!node) return;
	std::cout << node->getNode() << " ";
	preorder(node->getLeft());
	preorder(node->getRight());
}

template <typename T>
void BinaryTree<T>::printfPreOrder() {
	preorder(root);
	std::cout << std::endl;
}
// display in iteration way
