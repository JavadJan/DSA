#include "../include/LTraingelMatrix.hpp"

LTraingelMatrix::LTraingelMatrix():Matrices()
{
	/* both construtor will be called; Matrices then current */
	std::cout << "Called Default construtor\n";
}
LTraingelMatrix::LTraingelMatrix(int n):Matrices(n)
{
	std::cout << "\033[32mTraingle Param constructor called\033[0m" << std::endl;
	size = (n * (n + 1)) / 2; // non-zero
	this->A = new int[size];
	
}

LTraingelMatrix::~LTraingelMatrix()
{
	//delete [] this->A;
	std::cout << "\033[33mTraingle destructor called\033[0m\n";
}

void LTraingelMatrix::setMatrices(int i, int j, int value)
{
	if (i>=j)
	{
		//this->A[i] = value;
		//setMatrices(i,j, value);
		//this->A[i] = value;
		this->A[((i - 1)*(i)) / 2 + (j -1)] = value;
		std::cout <<"index: " << ((i - 1)*(i)) / 2 + (j -1) << std::endl;
	}
}

int LTraingelMatrix::getMatrices(int i, int j) const
{
	//(void)i;
	(void)j;
	return (this->A[i]);
}

void LTraingelMatrix::display() const
{
	std::cout << "size: " << getMatrixSize() << std::endl;
	for (int i = 1; i < getMatrixSize(); i++)
	{
		for (int j = 1; j < getMatrixSize(); j++)
		{
			if (i>=j)
				std::cout << this->A[((i - 1)*(i)) / 2 + (j -1)] <<  " ";
			else 
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	
}

int LTraingelMatrix::getMatrixSize() const
{
	return (n);
}