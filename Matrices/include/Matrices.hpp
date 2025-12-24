#ifndef MATRICES_HPP
#define MATRICES_HPP
#include <iostream>

class Matrices
{
	protected:
		int n;
		int *A;
	public:
		Matrices();
		Matrices(int size);
		~Matrices();
		virtual int getMatrixSize() const = 0;

		/* when you  */
		virtual void setMatrices(int i,int j,int value) = 0;
   		virtual int getMatrices(int i,int j) const = 0;
		virtual void display() const = 0;
};



#endif