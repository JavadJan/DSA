#include "../includes/searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(): array_bag(){}
searchable_array_bag::searchable_array_bag(const searchable_array_bag& b): array_bag(b){}

searchable_array_bag::~searchable_array_bag(){}
searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other)
{
	if (this == &other)
		return *this;
	array_bag::operator=(other); // Delegate to base class assignment operator
	return *this;
}


bool searchable_array_bag::has(int key) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == key)
			return true ;
	}
	
	return false;
}