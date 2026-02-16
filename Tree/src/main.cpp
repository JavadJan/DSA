#include "../include/Tree.hpp"

int main()
{
	

	//Tree<int> t(x);
	BinaryTree<int> btree;
	btree.FillBinary();

	btree.printfPreOrder();
	std::cout << "----------------->in order: " ;
	btree.inorder();
	std::cout << std::endl;
	
	std::cout << "\n----------------->postorder: " ;
	btree.postorder();

	std::cout << "\n----------------->height: " ;
	std::cout << btree.height() <<std::endl;
	std::cout << std::endl;

	//int arr[] = {10, 9, 11, 5, 6, 2, 7, 8, 4, 3};
	int arr[] = {10};
	BST<int> bst;
	for (size_t i = 0; i < 1; i++)
	{
		bst.insert(arr[i]);
	}

	std::cout << "list: ";
	bst.inorder();
	std::cout << std::endl;

	std::cout << "search 10: " << bst.search(10) << std::endl;
	std::cout << "search 10 in recursive log(n): " << bst.Rsearch(10)->getNode() << std::endl;

	std::cout << "remove 10: " << std::endl;
	bst.remove(11);
	std::cout << std::endl;
	std::cout << "list: ";
	bst.inorder();
	std::cout << std::endl;

	int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
	bst.createBSTfromPreorder(pre, 8);
	std::cout << "created from pre order: ";
	bst.inorder();
	std::cout << std::endl;
	
	std::cout << "AVL: ";
	int arr0[7] = {10, 20, 30, 25, 28, 27, 5};
	AVL<int> avl;
	for (size_t i = 0; i < 7; i++)
	{
		/* code */
		avl.RInsert(arr0[i]);
	}
	
	//avl.RInsert(9);
	//avl.RInsert(8);
	//avl.RInsert(7);
	//avl.RInsert(6);
	//avl.inorder();
	std::cout << std::endl;
}