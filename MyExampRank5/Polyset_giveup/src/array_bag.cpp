#include "../includes/array_bag.hpp"

array_bag::array_bag() :arr(0), size(0){}
array_bag::~array_bag(){delete[] this->arr;}

array_bag::array_bag(const array_bag& b)
{
	this->arr = new int[b.size];
	for (int i = 0; i < b.size; i++)
	{
		this->arr[i] = b.arr[i];
	}
	this->size = b.size;
}

array_bag& array_bag::operator=(const array_bag& b)
{
	this->clear();
	this->arr = new int[b.size];
	for (int i = 0; i < b.size; i++)
	{
		this->arr[i] = b.arr[i];
	}
	this->size = b.size;
	return (*this);
}


void array_bag::insert(int val)
{
	int *tmp = new int[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i];
	}
	tmp[this->size] = val;
	delete[] this->arr;
	this->arr = tmp;
	this->size++;
}

void array_bag::insert(int *a, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		this->insert(a[i]);
	}
	
}

void array_bag::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << " ";
	}
	std::cout << std::endl;
}

void array_bag::clear()
{
	delete[] this->arr;
	this->arr = 0;
	this->size = 0;
}