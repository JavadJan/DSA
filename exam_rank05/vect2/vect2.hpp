/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:05:40 by codespace         #+#    #+#             */
/*   Updated: 2025/07/17 17:11:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class vect2
{
	public:
		// constructor
			vect2(void);
			vect2(int num0, int num1);
			vect2(const vect2& b);
			vect2&	operator=(const vect2& b); // Vect2 v0(1 ,3) AND Vect2 v1(3, 5) =>
		// destructor
			~vect2(void);

		// getter
			int		getN0(void)const;
			int		getN1(void)const;
		// setter
			void	setN0(int num);
			void	setN1(int num);
			
		// operator overloads
			// assignment
			vect2&	operator+=(const vect2& b);
			vect2&	operator-=(const vect2& b);
			vect2&	operator*=(const int num);
			
			// access
			int&	operator[](int num);
			
			// inc dec
			vect2	operator++(int);
			vect2&	operator++(void);
			vect2	operator--(int);
			vect2&	operator--(void);
			
			// arithmetic
			vect2 	operator+(const vect2& b)const;
			vect2	operator-(const vect2& b)const;
			vect2	operator-(void)const;
			vect2	operator*(const int num)const;

			// comp
			bool operator==(const vect2& b) const;
			bool operator!=(const vect2& b) const;
			int operator[](int index) const;
			int& operator[](int index); // NON-COST
	private:
		int _num0;
		int _num1;
};

vect2 operator*(const int num, const vect2& b);

std::ostream& operator<<(std::ostream& o, const vect2& b);

#endif