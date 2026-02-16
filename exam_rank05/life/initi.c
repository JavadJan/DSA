/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:17:47 by tabading          #+#    #+#             */
/*   Updated: 2025/08/04 09:18:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void draw_board(t_life* l)
{
	int i = 0;

	i = 0;
	while (i < l->h)
		printf("|%s|\n", l->board[i++]);

}

char** get_board(t_life* l)
{
	char** b;

	b = malloc((l->h + 1) * sizeof(char*));
	int i = 0;
	while (i < l->h)
	{
		b[i] = malloc ((l->w + 1) * sizeof(char));
		int x = 0;
		while (x < l->w)
			b[i][x++] = ' ';
		b[i][x] = 0;
		i++;
	}
	b[i] = 0;
	return (b);
}

void get_in(t_life* l, int i)
{
	char buf[1000];
	int byts = 0;

	if (i == 0)
	{
		byts = read(0, buf, 1000);
		buf[byts] = 0;
		l->input = malloc( (byts + 1) * sizeof(char));
		int i = 0;
		while (buf[i])
		{
			l->input[i] = buf[i];
			i++;
		}
		l->input[i] = 0;
	}
	else
	{
		if (l->h == 3)
			l->input =  "xdss";
		if (l->h == 5)
			l->input =  "sdxddssaaww";
	}
}

void initi(t_life* l, char** argv)
{
	l->w = atoi(argv[1]);
	l->h = atoi(argv[2]);
	l->it = atoi(argv[3]);
	l->draw = false;

	get_in(l, V);

	l->board = get_board(l);
}
