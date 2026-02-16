#include "./Tree.hpp"

template <typename T>
Node<T>::Node():left(NULL),right(NULL), height(1){

}

template <typename T>
Node<T>::Node(const T &value):value(value), left(NULL), right(NULL),height(1){} // constuctor

template <typename T>
Node<T>::~Node(){}

template <typename T>
Node<T>::Node(const Node &other): value(other.value), left(other.left), right(other.right)
{

}

template <typename T>
Node<T>& Node<T>::operator=(const Node& other)
{
	if (this != &other)
	{
		this->value = other.value;
		this->left = other.left;
		this->right = other.right;
	}
	return *this;
}

// setter
template <typename T>
void Node<T>::setLeft(Node *l)
{
	this->left = l;
}
template <typename T>
void Node<T>::setHeight(int h)
{
	this->height = h;
}
template <typename T>
void Node<T>::setRight(Node *r)
{
	this->right = r;
}

template <typename T>
void Node<T>::setValue(T val)
{
	this->value = val;
}

// getter
template <typename T>
const T& Node<T>::getNode() const
{
	return value;
}
template <typename T>
int Node<T>::getHeight() const
{
	return height;
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
	passing the root does not make sense!
	so we use from internal heppler and publick API
	private:
		height(Tree<T> *p)
	public: // public API
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
//--------------------------#
//			BST				#
//--------------------------#
template <typename T>
BST<T>::BST():BinaryTree<T>()
{

}

template <typename T>
BST<T>::~BST()
{

}
template <typename T>
void BST<T>::insert(const T& value)
{
    Node<T>* t = new Node<T>(value);

    if (this->root == nullptr)
    {
        this->root = t;
        return;
    }

    Node<T>* p = this->root;
    Node<T>* parent = nullptr;

    while (p != nullptr)
    {
        parent = p;

        if (value < p->getNode())
            p = p->getLeft();
        else
            p = p->getRight();
    }

    if (value < parent->getNode())
        parent->setLeft(t);
    else
        parent->setRight(t);
}


/* insert a key in BST Tree with recursive apparoach */
template<typename T>
void BST<T>::RInsert(const T& key)
{
	this->root = RInsert(this->root, key);
}

template <typename T>
Node<T> *BST<T>::RInsert(Node<T> *p, const T& key)
{
	if (p == nullptr)
	{
		Node<T> *t = new Node<T>(key);
		return t;
	}
	if (key < p->getNode())
	{
		p->setLeft(RInsert(p->getLeft(), key));
	}
	else if (key > p->getNode())
	{
		p->setRight(RInsert(p->getRight(), key));
	}
	// If key == p->getNode(), do nothing (no duplicates)
	return p;
}


template <typename T>
T BST<T>::search(int key)
{
	Node<T> *p = this->root;
	while (p != NULL)
	{
		if (p->getNode() == key)
			return p->getNode();
		if (p->getNode() < key)
			p = p->getLeft();
		else if (p->getNode() > key)
			p = p->getRight();
	}
	return 0;
}

template <typename T>
Node<T>* BST<T>::Rsearch(Node<T> *t, int key)
{
	if (t == NULL)
		return NULL;
	if (t->getNode() == key)
		return t;
	if (t->getNode() < key)
		return Rsearch(t->getLeft(), key);
	else
		return Rsearch(t->getRight(), key);
	
}

template <typename T>
Node<T>* BST<T>::Rsearch(int key)
{
	return this->Rsearch(this->root, key);
}

// left most leaf
template <typename T>
Node<T> *BST<T>::InPre(Node<T> *node)
{

	while (node && node->getRight() != NULL)
	{
		node = node->getRight();
	}
	return node;
}

template <typename T>
Node<T> *BST<T>::InSucc(Node<T> *node)
{
	while (node && node->getLeft() != NULL)
	{
		node = node->getLeft();
	}
	return node;
}

template <typename T>
void BST<T>::remove(int key)
{
	remove(this->root, key);
}

template <typename T>
Node<T>* BST<T>::remove(Node<T> *p, int key)
{

	Node<T> *q;

	if (p == nullptr)
		return nullptr;

	if (p->getNode() < key)
	{
		std::cout << "go left" << std::endl;
		p->setLeft(remove(p->getLeft(), key));
	}
	else if (p->getNode() > key)
	{
		std::cout<< "go right " << std::endl;
		p->setRight(remove(p->getRight(), key));
	}
	else
	{
		// if it comes the base case:
		if (p->getLeft() == NULL && p->getRight() == NULL)
		{
			if (p == this->root)
			{
				// retrive from stack
				std::cout << " one node: " << p->getNode() << " != " << key << std::endl;
				this->root = NULL;
			}
			delete p;
			return NULL;		
		}
		if (this->height(p->getLeft()) > this->height(p->getRight()))
		{
			q = InPre(p->getLeft());
            p->setValue(q->getNode());
			p->setLeft(remove(p->getLeft(), p->getNode()));
		}
		else
		{
			q = InSucc(p->getRight());
            p->setValue(q->getNode());
			p->setRight(remove(p->getRight(), p->getNode()));
		}
	}
	return p;
}

template<typename T>
void BST<T>::createBSTfromPreorder(int pre[], size_t size)
{
	if (size <= 0)
	{
		std::cout << "there is not list to make BST\n";
		return;
	}
	std::stack<Node<T> *> st;
	size_t i = 0;
	Node<T> *newNode = new Node<T>;
	newNode->setValue(pre[i++]);
	newNode->setRight(NULL);
	newNode->setRight(nullptr);
	Node<T> *p = this->root = newNode;

	while (i < size)
	{
		// for insertion in left child
		if (pre[i] < p->getNode())
		{
			Node<T> *newNode = new Node<T>;
			newNode->setValue(pre[i++]);
			newNode->setLeft(nullptr); 
			newNode->setRight(nullptr);

			p->setLeft(newNode);
			// keep track in a stack
			st.push(p);
			p = newNode; // update p
		}
		else
		{
			if (pre[i] > p->getNode() && (st.empty() || pre[i] < st.top()->getNode()))
			{
				Node<T> *newNode = new Node<T>;
				newNode->setValue(pre[i++]);
				newNode->setLeft(nullptr); 
				newNode->setRight(nullptr);

				p->setRight(newNode);
				p = newNode;
			}
			else
			{
				p = st.top();
				st.pop();
			}
		}
	}
	
}


/*-------------------------------*/
/* 								 */
/* 			AVL TREE			 */
/* 								 */
/*-------------------------------*/
template<typename T>
AVL<T>::AVL()
{

}

template<typename T>
AVL<T>::~AVL()
{
	
}
template <typename T>
Node<T>* AVL<T>::LLRotation(Node<T> *p)
{
	std::cout << "LL Rotation called\n";
	Node<T> *pl = p->getLeft();
	Node<T> *plr = pl->getRight();

	// apply totate to left:
	p->setLeft(plr);
	pl->setRight(p);
	p->setHeight(nodeHeight(p));
	pl->setHeight(nodeHeight(pl));
	if (p == this->root)
		this->root = pl;
	return pl;
}
template <typename T>
Node<T>* AVL<T>::LRRotation(Node<T> *p)
{
	std::cout << "LR Rotation called\n";
	Node<T> *pl = p->getLeft();
	Node<T> *plr = pl->getRight();

	p->setLeft(plr->getRight());
	pl->setRight(plr->getLeft());

	plr->setRight(p);
	plr->setLeft(pl);

	p->setHeight(nodeHeight(p));
	pl->setHeight(nodeHeight(pl));
	plr->setHeight(nodeHeight(plr));

	if(this->root == p)
		this->root = plr;
	return plr;
}
template <typename T>
Node<T>* AVL<T>::RRRotation(Node<T> *p)
{
	std::cout << "RR Rotation called\n";
	Node<T> *pr = p->getRight();
	Node<T> *prl = pr->getLeft();

	p->setRight(prl);
	pr->setLeft(p);
	p->setHeight(nodeHeight(p));
	pr->setHeight(nodeHeight(pr));

	if (p == this->root)
		this->root = pr;
	return pr;

}
template <typename T>
Node<T>* AVL<T>::RLRotation(Node<T> *p)
{
	std::cout << "RL Rotation called\n";
	Node<T> *pr = p->getRight();
	Node<T> *prl = pr->getLeft();

	p->setRight(prl->getLeft());
	pr->setLeft(prl->getRight());

	prl->setLeft(p);
	prl->setRight(pr);

	p->setHeight(nodeHeight(p));
	pr->setHeight(nodeHeight(pr));
	prl->setHeight(nodeHeight(prl));

	if (p == this->root)
		this->root = prl;
	
	return prl;
}


template <typename T>
void AVL<T>::RInsert(const T& key)
{
	this->root = this->RInsert(this->root, key);
}

template <typename T>
Node<T>* AVL<T>::RInsert(Node<T> *p, const T& key) {
    // 1. Standard BST Insert
    if (p == nullptr) return new Node<T>(key);
    
    if (key < p->getNode())
        p->setLeft(RInsert(p->getLeft(), key));
    else if (key > p->getNode())
        p->setRight(RInsert(p->getRight(), key));
    else 
        return p; // Duplicate keys not allowed in standard AVL

    // 2. Update height of current node
    p->setHeight(nodeHeight(p));

    // 3. Balance the node if necessary
    int bf = balanceFactor(p);

    // LL Case
    if (bf == 2 && balanceFactor(p->getLeft()) >= 0)
	{
		std::cout << "LL\n";
        return LLRotation(p);
	}
    // LR Case
    if (bf == 2 && balanceFactor(p->getLeft()) < 0)
	{
		
		std::cout << "LL\n";
        return LRRotation(p);
	}
    // RR Case
    if (bf == -2 && balanceFactor(p->getRight()) <= 0)
	{
		
		std::cout << "LL\n";
        return RRRotation(p);
	}
    // RL Case
    if (bf == -2 && balanceFactor(p->getRight()) > 0)
	{
		std::cout << "LL\n";
        return RLRotation(p);
	}

    return p;
}


template <typename T>
int AVL<T>::nodeHeight(Node<T> *p)
{
	int hl,hr;

	hl = (p && p->getLeft()) ? p->getLeft()->getHeight():0 ;
	hr = (p && p->getRight()) ? p->getRight()->getHeight():0 ;
	return (hl > hr ? hl : hr) + 1;
}

template <typename T>
int AVL<T>::balanceFactor(Node<T> *p)
{
	int hl,hr;

	hl = (p && p->getLeft()) ? p->getLeft()->getHeight():0 ;
	hr = (p && p->getRight()) ? p->getRight()->getHeight():0;

	return (hl - hr);
}