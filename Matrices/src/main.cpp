#include "../include/Matrices.hpp"
#include "../include/LTraingelMatrix.hpp"

int main()
{
	//int A[5] = {3, 4, 7, 9, 10};
	//Matrices m(5);
	//m.setMatrices(3,3, 11);
	//m.setMatrices(1,1, 10);
	//m.setMatrices(2,2, 7);
	//m.setMatrices(4,4, 1);
	//m.display();

	std::cout << "\033[34mTEST: Default constructor will be called\033[0m\n";
	std::cout << "TraingelMatrix t(5);\n";
	LTraingelMatrix t(5);
	t.setMatrices(3,3,4);
	t.setMatrices(3,1,3);
	t.setMatrices(3,2,2);
	t.setMatrices(2,2,1);
	t.setMatrices(2,1,10);
	t.setMatrices(1,1,11);
	t.setMatrices(4,1,14);
	t.setMatrices(4,2,17);
	t.setMatrices(4,3,5);
	t.setMatrices(4,4,6);
	t.display();
	return (0);
}