#ifndef ARRAY_BAG_HPP
# define ARRAY_BAG_HPP

# include "bag.hpp"
# include <iostream>

class bag;

class array_bag: virtual public bag
{
	protected:
		int *arr;
		int size;
	public:
		array_bag();
		virtual ~array_bag();
		array_bag(const array_bag& b);
		array_bag& operator=(const array_bag& b);

		void insert(int val);
		void insert(int *a, int amount);
		void clear();
		void print() const;

};

#endif