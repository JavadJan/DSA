#include "Matrices.hpp"

Matrices::Matrices():n(0)
{
	std::cout << "Default Matrices constructor called" << std::endl;
}

Matrices::Matrices(int size):n(size)
{
	this->A = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->A[i] =  0;
	}
	//this->n = size;
	std::cout << "Parameterized Matrices constructor called" << std::endl;
}

Matrices::~Matrices()
{
	delete [] this->A;
	std::cout << "\033[32mDestructor Matrices called\033[0m" << std::endl;
}
int Matrices::getMatrices(int i, int j) const
{
	//if (i == j)
	(void)j;
	return (this->A[i]); 
}

//void Matrices::setMatrices(int i, int j, int x)
//{

//}

void Matrices::display() const
{
	for (int i = 1; i < this->n; i++)
	{
		for (int j = 1; j < this->n; j++)
		{
			if (i >= j)
				std::cout << this->A[i] << " ";
			else
				std::cout << "0 " ;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Matrices::getMatrixSize() const
{
	return (this->n);
}
