#ifndef SEARCHABLE_BAG_HPP
# define SEARCHABLE_BAG_HPP

#include "./bag.hpp"

/**
 * @class bag
 * @brief Represents a collection of items with the ability to store multiple instances of the same item.
 * 
 * The `bag` class provides a container that allows duplicate elements and 
 * supports operations such as insertion, removal, and search. It is designed 
 * to be a simple and flexible data structure for managing collections of items.
 * 
 * Note: The implementation details and specific functionality of the `bag` 
 * class are not provided in this header file.
 */
class bag;

class searchable_bag: virtual public bag {

	public: 
		searchable_bag();
		virtual ~searchable_bag();
		//searchable_bag(const searchable_bag& other);
		//searchable_bag& operator=(const searchable_bag& other);

		virtual bool has(int x) const = 0;
};

#endif