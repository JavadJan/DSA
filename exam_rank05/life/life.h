/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:11:08 by tabading          #+#    #+#             */
/*   Updated: 2025/08/05 09:45:39 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

# define V 1

typedef struct s_life
{
	char**	board;
	char*	input;

	int		w;
	int		h;
	int		it;
	bool	draw;
	
} t_life;

// initi
void	draw_board(t_life* l);
char**	get_board(t_life* l);
void 	get_in(t_life* l, int i);
void	initi(t_life* l, char** argv);

// fr
void fr(t_life* l, int a);

#endif

