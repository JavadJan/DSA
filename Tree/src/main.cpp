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
}