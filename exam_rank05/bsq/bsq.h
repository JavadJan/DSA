/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:35:41 by tabading          #+#    #+#             */
/*   Updated: 2025/08/06 10:22:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_bsq
{
	char** map;

	int h;
	int w;

	char em;
	char ob;
	char fu;

	FILE* fd;

	int x;
	int y;

	int size;

} t_bsq;

//initi 

void	set_nu(t_bsq* bb);
int		set_vals(t_bsq* bb, char* p);
int		get_firstl(t_bsq* bb, int argc, char** argv);
int		initi(t_bsq* bb, int argc, char** argv);

// helper

void	print_m(char** m);
void	free_m(t_bsq* bb);
int		ex(t_bsq* bb, char* err);

#endif