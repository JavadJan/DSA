#include "../include/Tree.hpp"

int main()
{
	

	//Tree<int> t(x);
	BinaryTree<int> root;
	root.FillBinary();

	root.printfPreOrder();
	std::cout << "----------------->" << std::endl;
}