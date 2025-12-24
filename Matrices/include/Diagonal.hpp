#ifndef DIAGONAL_HPP
#define DIAGONAL_HPP
#include <iostream>
#include <Matrices.hpp>

class Diagonal:public Matrices
{
	private:
	public:
		Diagonal();
		~Diagonal();
		Diagonal(int size);

		void setMatrices(int i,int j,int value) ;
   		int getMatrices(int i,int j) ;
		void display() ;

};

#endif