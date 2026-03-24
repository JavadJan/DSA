
# ifndef SET_HPP
# define SET_HPP


#include "searchable_bag.hpp"
#include <cstddef>

class searchable_bag;

class set
{
	protected:
		searchable_bag*	_b;

	public:
		// constructor destructor
		set();
		set(const set&);
		explicit set(searchable_bag&);
		//set( searchable_bag&);
		~set();
		
		// overload
		// set& operator=(const set&);

		// mem functs
		searchable_bag* get_bag();

};

#endif