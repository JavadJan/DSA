/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:10:59 by tabading          #+#    #+#             */
/*   Updated: 2025/08/04 09:22:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

/*
Name: 			[life]
allowed functs:	[atoi, read, putchar, malloc, calloc, realloc, free]
includes:		[unistd.h, stdlib.h, stdio.h]
Task: 			[You must write a programm that simulates a game of life.]

The prototype is the following: 
	- ./life width height iterations
		- width & height are the dimensions of the board and iterations is  
		the number of iterations of the game of life
		- the initial configuration of the board is drawn by a sequence of 
		commands in the standard input.

Imagine a pen starting in the upper left corner of the board.
Each command is one of these chars:
	- w, a, s, d:
		-> movement pen on board
	- x
		-> start/stop drawing
		-> default not drawing

Your pen stays inside the board, if a command were to move it outside 
do nothing.
If an invalid command is input, do nothing.
Once end of file is reached, your programm must simulate a game of life 
based on this board and print the result to stdout (each living cell is 
represented by char '0', each dead cell by char ' ').
Each cell outside the array is dead.

[Game of Life]

Rules:
	- on each itearation the following occures:
		-> Any live cell with [ <2 ] live neighbours dies.
		-> Any live cell with [ 2-3 ] live neighbours lives on.
		-> Any live cell with [ >3 ] live neighbours dies.
		-> Any dead cell with [ 3 ] live neighbours becomes a live cell.

*/

int act(t_life* l, char c, int w, int h)
{
	if (c == 'w' && w > 0)
		return (-1);
	if (c == 's' && w < l->w)
		return (1);
	if (c == 'a' && h > 0)
		return (-1);
	if (c == 'd' && h < l->h)
		return (1);
	return (0);
}

void fill_b(t_life* l)
{
	char* in = l->input;
	int c = 0;
	int w = 0;
	int h = 0;

	while (in[c])
	{
		if (in[c] == 'w' || in[c] == 'a' || in[c] == 's' || in[c] == 'd') // valid
		{
			if (in[c] == 'w' || in[c] == 's')
				h += act(l, in[c], w, h);
			else
				w += act(l, in[c], w, h);
			if (l->draw == true)
				l->board[h][w] = '0';
		}
		if (in[c] == 'x')
		{
			if (l->draw == true)
				l->draw = false;
			else
				l->draw = true;
		}
		c++;
	}
}

int neigh(t_life* l, int h, int w)
{
	char** b = l->board;
	int n = 0;

	if (h > 0 && w > 0 && b[h - 1][w - 1] == '0') // up left
		n++;
	if (h > 0 && b[h - 1][w] == '0') // up midle
		n++;
	if (h > 0 && w < l->w - 1 && b[h - 1][w + 1] == '0') // up right
		n++;
	
	if (w > 0 && b[h][w - 1] == '0') // middle left
		n++;
	if (w < l->w - 1 && b[h][w + 1] == '0') // middle right
		n++;

	if (h < l->h - 1 && w > 0 && b[h + 1][w - 1] == '0') // down left
		n++;
	if (h < l->h - 1 && b[h + 1][w] == '0') // down midle
		n++;
	if (h < l->h - 1 && w < l->w - 1 && b[h + 1][w + 1] == '0') // down right
		n++;
	return (n);
}

bool is_it_alive(char stat, int n)
{
	if (stat == '0') // live cell
	{
		if (n < 2)
			return (false);
		if (n == 2 || n == 3)
			return (true);
		if (n > 3)
			return (false);
	}
	else if (n == 3) // dead cell
		return (true);
	return (false);
}

char** get_newb(t_life* l, char** o)
{
	int h = 0;
	int w;
	char** newb = get_board(l);

	while (h < l->h)
	{
		w = 0;
		while (w < l->w)
		{
			int n = neigh(l, h, w); // amount of neighbours of cell
			if (is_it_alive(o[h][w], n))
				newb[h][w] = '0';
			w++;
		}
		h++;
	}
	return (newb);
}

void sim(t_life* l)
{
	int i = 0;
	char** newb;

	while (i < l->it) // one sim per loop
	{
		newb = get_newb(l, l->board);
		if (i == 0)
			fr(l, 1); // frees board & input
		else
			fr(l, 0); // only frees board
		l->board = newb;
		i++;
	}
}

int main(int argc, char *argv[])
{
	struct s_life l;

	if (argc != 4)
		return (0);
	initi(&l, argv);
	fill_b(&l);
	sim(&l);
	draw_board(&l);
	fr(&l, 0);
	return (0);
}

// look at 5 5 5