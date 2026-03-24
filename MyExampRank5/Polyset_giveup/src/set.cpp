#include "../includes/set.hpp"

set::set(): _b(NULL){}
set::~set(){}
set::set(const set& other)
{
	*this = other ;
}
set::set(searchable_bag& bp): _b(&bp)
{

}

searchable_bag* set::get_bag()
{
	return (_b);
}