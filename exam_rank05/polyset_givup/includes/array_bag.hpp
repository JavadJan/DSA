/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:12:50 by codespace         #+#    #+#             */
/*   Updated: 2025/07/30 13:47:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_BAG_HPP
# define ARRAY_BAG_HPP

#include "bag.hpp"

class bag;

class array_bag : virtual public bag
{
	protected:
		int* data;
		int size;
		
	public:
		// constructor destructor
		array_bag();
		array_bag(const array_bag&);
		~array_bag();
		
		// overload
		array_bag& operator=(const array_bag&);

		// mem functs
		void insert(int);
		void insert(int*, int);
		void print();
		void clear();
		
};

#endif