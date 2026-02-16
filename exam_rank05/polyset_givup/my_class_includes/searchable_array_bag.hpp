/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:49:42 by codespace         #+#    #+#             */
/*   Updated: 2025/07/31 12:33:43 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

#include "../includes/array_bag.hpp"
#include "../includes/searchable_bag.hpp"

class array_bag;
class searchable_bag;

class searchable_array_bag : virtual public array_bag, public searchable_bag
{
	protected:

	public:
		// constructor destructor
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag&);
		virtual ~searchable_array_bag();
		
		// overload
		searchable_array_bag& operator=(const searchable_array_bag&);

		// mem functs
		bool has(int)const;
};

#endif