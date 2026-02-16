/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:13:17 by tabading          #+#    #+#             */
/*   Updated: 2025/08/11 10:29:43 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*

[bsq]:	write a programm that takes a map and fill in the biggest 
		possible square

[allowed functs] : malloc, free, fopen, fclose, getline, 

[input]: take map [argv] if given else [stdin]

[valid map]: 
	- first line has [linenumber][empty][obstacle][full]
	- only has the chars [empty][obstacle][full]
	- [empty][obstacle][full] don't double up
	- map has at least 1 line and 1 cell
	- all lines have the same lenght
	- all lines end on \n

[square]:
	- in case of multiple squares take the [top left most]

[error]:
	- in case of error print "Error: " with a sensible descriptor
	- in case of invalid map print "Error: invalid map"

ex:
	example_map:
	9.ox
	.................o.........
	....o......................
	...........................
	.....................o.....
	...............o...........
	...........................
	...........................
	........o..................
	...........................

	./bsq example_map
	
	.....xxxxxxxxxx..o.........
	....oxxxxxxxxxx............
	.....xxxxxxxxxx............
	.....xxxxxxxxxx......o.....
	.....xxxxxxxxxxo...........
	.....xxxxxxxxxx............
	.....xxxxxxxxxx............
	........o..................
	...........................

*/

int check_sq(t_bsq* bb, int size, int a, int b)
{
	int y = 0;
	int x = 0;

	if (size + a > bb->h - 1 || size + b > bb->w - 1)
		return (-1);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (bb->map[a + y][b + x] == bb->ob)
				return (-1);
			x++;
		}
		y++;
	}
	bb->size = size;
	bb->y = a;
	bb->x = b;
	return (0);
}

void bsq(t_bsq* bb)
{
	int look_size = 0;
	int stat = 0;
	int a = 0;
	int b = 0;

	if (bb->h < bb->w)
		look_size = bb->h / 2;
	else
		look_size = bb->w / 2;

	while (stat >= 0 || bb->size == 0)
	{
		a = 0;
		if (stat > 0)
			a = bb->y;
		while (a < bb->h - (look_size + stat) + 1)
		{
			b = 0;
			if (stat > 0 && a == bb->y)
				b = bb->x;
			while (b < bb->w - 1 - (look_size + stat) + 1)
			{
				if (check_sq(bb, (look_size + stat), a, b) != -1)
				{
					stat++;
					break ;
				}
				b++;
			}
			if (b != bb->w - 1 - (look_size + stat) + 1)
				break ;
			a++;
		}
		if (stat <= 0)
			stat--;
		if (stat > 0 && a == bb->h - (look_size + stat) + 1)
			break ;
	}
}

void h(t_bsq* bb)
{
	int i = 0;

	while (i < bb->size)
	{
		int a = 0;
		while (a < bb->size)
			bb->map[bb->y + i][bb->x + a++] = bb->fu;
		i++;
	}
}

int main(int argc, char** argv)
{
	struct s_bsq bb;

	bb.map = 0;
	bb.fd = 0;
	if (argc > 2)
		return (ex(&bb, "Error: Invalid args"));

	if (initi(&bb, argc, argv) == -1)
		return (0);
	bsq(&bb);
	h(&bb);
	
	print_m(bb.map);

	// printf("\nh: %d\nw: %d\nem: %c\nob: %c\nfu: %c\n", bb.h, bb.w, bb.em, bb.ob, bb.fu);

	free_m(&bb);
	return (0);
}
