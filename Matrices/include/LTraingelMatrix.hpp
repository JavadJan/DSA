#ifndef TRIANGLEMATRIX_HPP
# define TRIANGLEMATRIX_HPP
#include <iostream>
#include "Matrices.hpp"

class LTraingelMatrix:public Matrices
{
	private:
		//int *lineer_arr;
		int size;
	public:
		LTraingelMatrix();
		LTraingelMatrix(int n);
		~LTraingelMatrix();
		void setMatrices(int i, int j, int value);
		int getMatrices(int i, int j) const;
		void display() const;
		virtual int getMatrixSize() const;
};



#endif