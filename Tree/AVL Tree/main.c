#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct Node {
	struct Node *left;
	int data;
	int height;
	struct Node *right;
} *root = NULL;

//int height(struct Node *p)
//{
//	int x, y;
//	if (p != NULL)
//	{
//		x = height(p->left);
//		y = height(p->right);
//		if (x > y)
//			return x + 1;
//		else
//			return y + 1;
//	}
//	return 0;
//}

/* 
	this height function is better, because the once the the Rinsert arive in base case
	and in this height the child return the height itself in returning time
*/
int height(struct Node* p)
{
	int hl, hr;
	hl = p && p->left ? p->left->height : 0;
	hr = p && p->right ? p->right->height : 0;

	return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p)
{
	int hl, hr;
	hl = p && p->left ? p->left->height : 0;
	hr = p && p->right ? p->right->height : 0;

	return hl - hr;
}

struct Node *LLRotation(struct Node *p)
{
	struct Node *pl = p->left;
	struct Node *plr = pl->right;

	pl->right = p;
	p->left = plr;

	p->height = height(p);
	pl->height = height(pl);
	if (root == p)
		root = pl;
	return pl;
}

struct Node *LRRotation(struct Node *p)
{
	// get the left of the imbalance node
	struct Node *p_left = p->left;
	// get thel imbalance node->left->right
	struct Node *p_left_right = p_left->right;

	// update the pointers of these node
	p_left->right = p_left_right->left;
	p->left = p_left_right->right;
	
	// update left->right;
	p_left_right = p;
	p_left_right->left = p_left;

	p_left->height = height(p_left);
	p_left_right->height = height(p_left_right);
	p->height = height(p);
	if (root == p)
		root = p_left_right;
	return p_left_right; // return the node that want to replace

}

struct Node *RRRotation(struct Node *p)
{
	// get right of the imbalance node
	struct Node *pr = p->right;
	// get left of right of the imbalance node
	struct Node *prl = pr->left;

	// update the pointers
	pr->left = p;
	p->right = prl;
	// update the height
	pr->height = height(pr);
	p->height = height(p);
	if (root == p)
		root = pr;
	return pr;
}

struct Node *RLRotation(struct Node *p)
{
	struct Node *pr = p->right;
	struct Node *prl = pr->left;

	p->right = prl->left;
	pr->left = prl->right;
	prl->left = p;
	prl->right = pr;

	p->height = height(p);
	pr->height = height(pr);
	prl->height = height(prl);
	if (root == p)
		root = prl;
	return prl; // return the new father
}

struct Node* RInsert(struct Node *p, int key)
{
	// if base case, create node and return the caller will assing this node to its child
	if (p == NULL)
	{
		struct Node *t = (struct Node *)malloc(sizeof(struct Node));
		if (!t)
			return NULL;
		t->data = key;
		t->left = t->right = NULL;
		// for every singel node we consider a height
		t->height = 1;
		return t;
	}
	if (key < p->data)
		p->left = RInsert(p->left, key);
	else if (key > p->data)
		p->right = RInsert(p->right, key);
	// in retrurin time we update the height
	p->height = height(p);
	if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)
		return LLRotation(p);
	else if ((BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1))
		return LRRotation(p);
	else if ((BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1))
		return RRRotation(p);
	else if ((BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1))
		return RLRotation(p);
	return p;
}

void print_inOrder(struct Node *temp)
{
	if (!temp) return;
	print_inOrder(temp->left);
	printf("%d, ", temp->data);
	print_inOrder(temp->right);
}

int main()
{
	root = RInsert(root, 10);
	RInsert(root, 5);
	RInsert(root, 2);
	
	print_inOrder(root);
	printf("\n");

}