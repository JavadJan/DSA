/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:35:09 by tabading          #+#    #+#             */
/*   Updated: 2025/07/31 13:37:45 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SET_HPP
# define SET_HPP


#include "../includes/searchable_bag.hpp"

class searchable_bag;

class set
{
	protected:
		searchable_bag*	_b;

	public:
		// constructor destructor
		set();
		set(const set&);
		explicit set( searchable_bag&);
		~set();
		
		// overload
		// set& operator=(const set&);

		// mem functs
		searchable_bag* get_bag();

};

#endif