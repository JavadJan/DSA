/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:06:37 by codespace         #+#    #+#             */
/*   Updated: 2025/07/30 13:09:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_HPP
# define BAG_HPP

#include <iostream>

class bag
{
	public:
		virtual void insert(int) = 0;
		virtual void insert(int*, int) = 0;
		virtual void print() = 0;
		virtual void clear() = 0;
};

#endif