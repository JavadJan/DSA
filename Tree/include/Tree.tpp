#include "./Tree.hpp"

template <typename T>
Node<T>::Node():left(NULL),right(NULL){

}

template <typename T>
Node<T>::Node(const T &value):value(value), left(NULL), right(NULL){} // constuctor

template <typename T>
Node<T>::~Node(){}

template <typename T>
Node<T>::Node(const Node &other): value(other.value), left(other.left), right(other.right)
{

}

// setter
template <typename T>
void Node<T>::setLeft(Node *l)
{
	this->left = l;
}
template <typename T>
void Node<T>::setRight(Node *r)
{
	this->right = r;
}

// getter
template <typename T>
const T& Node<T>::getNode() const
{
	return value;
}
template <typename T>
Node<T>* Node<T>::getLeft() const
{
	return left;
}
template <typename T>
Node<T>* Node<T>::getRight() const
{
	return right;
}

// fill tree
template <typename T>
BinaryTree<T>::BinaryTree():root(nullptr)
{

}

template <typename T>
BinaryTree<T>::~BinaryTree()
{

}
template <typename T>
void BinaryTree<T>::FillBinary()
{
	std::queue<Node<T> *> q;// a Q of pointer of object tree
	int x = -1; // for nodes have does not child
	std::cout << "enter root: " << std::endl;
	std::cin >> x;

	if (x == -1)
		return;

	root = new Node<T>(x); // create obj of tree
	 // how add left and right? p.set

	q.push(root);
	
	while (!q.empty())
	{
		Node<T>* p = q.front(); // take from Q to add new one
		q.pop(); // add level by level

		std::cout << "Enter Left child for " << p->getNode() << std::endl;
		std::cin >> x;
		if (x != -1)
		{
			Node<T> *t = new Node<T>(x); // created
			q.push(t); // added to queue to track
			p->setLeft(t); // add to the left
		}
		std::cout << "Enter Right Child for " << p->getNode() << std::endl;
		std::cin >> x;
		if (x != -1)
		{
			Node<int> *t = new Node<T>(x);
			q.push(t);
			//p.setRight(t); // add right;
			p->setRight(t);
		}
	}
	
}
// display the tree in preorder, in order, and postorder recurively
template <typename T>
void BinaryTree<T>::preorder(Node<T> * node)
{
	if (!node) return;
	std::cout << node->getNode() << " ";
	preorder(node->getLeft());
	preorder(node->getRight());
}
/* public API */
template <typename T>
void BinaryTree<T>::preorder()
{
	this->preorder(root);
}

template <typename T>
void BinaryTree<T>::postorder(Node<T> * p)
{
	if (!p) return;
	postorder(p->getLeft());
	postorder(p->getRight());
	std::cout << p->getNode() << " ";
}

template <typename T>
void BinaryTree<T>::postorder()
{
	this->postorder(root);
}

template <typename T>
void BinaryTree<T>::inorder(Node<T> * node)
{
	if (!node) return;
	inorder(node->getLeft());
	std::cout << node->getNode() << " ";
	inorder(node->getRight());
}

template <typename T>
void BinaryTree<T>::inorder()
{
	this->inorder(root);
}

template <typename T>
void BinaryTree<T>::printfPreOrder() {
	preorder(root);
	std::cout << std::endl;
}
// display in iteration way


template <typename T>
void BinaryTree<T>::iterativeInorder()
{
	std::stack<Node<T>*> st;
	Node<T>* t = root;

	while (t != NULL || !st.empty())
	{
		if (t != NULL)
		{
			st.push(t);
			t = t->getLeft();
		}
		else
		{
			t = st.top();
			st.pop();
			std::cout << t->getNode() << " ";
			t = t->getRight();
		}
	}
}

template <typename T>
void BinaryTree<T>::iterativePostorder()
{
	// define a stack to track print data
	std::stack<Node<T> *> st;

	// define a Tree has already visited;
	Node<T> *visisted;

	// defein into to prevert modify the original root
	Node<T> *t = root;
	while (t != NULL || !st.empty())
	{
		if (t != NULL)
		{
			st.push(t); // push into stakc to keep track
			t = t->getLeft(); // go to left
		}
		else
		{
			Node<T> *top = st.top();
			if (top->getRight() != NULL && top->getRight() != visisted)
			{
				t = top->getRight(); // move just if not null and not viststed
			}
			else
			{
				std::cout << top->getNode() << ", ";
				visisted = top;

				st.pop();
			}
		}
	}
	
}
template <typename T>
int BinaryTree<T>::count(Node<T> *p)
{
	int x,y;
	if (p != NULL)
	{
		x = count(p->getLeft());
		y = count(p->getRight());
		return (x + y + 1);
	}
	return 0;
}

template <typename T>
int BinaryTree<T>::countLeaf(Node<T> *p)
{
	int x,y;
	if (p != NULL)
	{
		x = countLeaf(p->getLeft());
		y = countLeaf(p->getRight());
		if (p->left == NULL && p->right == NULL)
			return (x + y + 1);
		else
			return (x + y);
	}
	return 0;
}

template <typename T>
int BinaryTree<T>::countLeaf()
{
	return (this->countLeaf(root));
}
/* 
	user does not know about the root.
	preserve the encapsulation
*/
template <typename T>
int sum(Node<T> *p)
{
	int x,y;
	if (p != NULL)
	{
		x = sum(p->getLeft());
		y = sum(p->getRight());
		return (x + y + p->getNode());
	}
	return 0;
}

template <typename T>
int BinaryTree<T>::sum()
{
	return (sum(this->root));
}

// why the Binary tree has alreay the root and height must tale the root as param?
/* 
	in desing patter the tree.hight() is correct but the tree.height(root) is false?
	passing the root does not male sense!
	so we use from interla heppler and publick API
	private:
		height(Tree<T> *p)
	public:
		height();

	this is desight pattern for all the sum() and count is correct
*/

template <typename T>
int BinaryTree<T>::height(Node<T> *p)
{
	int x,y;
	if (p != NULL)
	{
		x = height(p->getLeft());
		y = height(p->getRight());
		if (x > y)
			return x + 1;
		else
			return y + 1;
	}
	return 0;
}

template <typename T>
int BinaryTree<T>::height()
{
	return height(root);
}


/* BST: insert, build, remove */
//void BST<T>::fil