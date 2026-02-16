/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_bag.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:10:09 by codespace         #+#    #+#             */
/*   Updated: 2025/07/30 13:11:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_BAG_HPP
# define SEARCHABLE_BAG_HPP

#include "bag.hpp"

class bag;

class searchable_bag : virtual public bag
{
	public:
		virtual bool has(int)const = 0;
};

#endif