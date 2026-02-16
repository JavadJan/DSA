/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:47:41 by tabading          #+#    #+#             */
/*   Updated: 2025/08/10 13:27:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void set_nu(t_bsq* bb)
{
	bb->h = 0;
	bb->w = 0;
	bb->em = 0;
	bb->ob = 0;
	bb->fu = 0;
	bb->fd = 0;
	bb->x = 0;
	bb->y = 0;
	bb->size = 0;
}

int set_vals(t_bsq* bb, char* p)
{
	int i = 0;
	if (!p)
		return (ex(bb, "Error: invalid first line"));

	while (p[i] >= '0' && p[i] <= '9')
		bb->h = bb->h * 10 + p[i++] - '0';
	if (bb->h == 0)
		return (ex(bb, "Error: invalid first line: num < 1"));
	if (p[i + 0] == '\n' || p[i + 1] == '\n' || p[i + 2] == '\n')
		return (ex(bb, "Error: invalid first line: amount"));
	if (p[i + 3] != '\n')
		return (ex(bb, "Error: invalid first line: no newline/amount"));
	bb->em = p[i++];
	bb->ob = p[i++];
	bb->fu = p[i++];
	if (bb->em == bb->ob || bb->em == bb->fu || bb->fu == bb->ob)
		return (ex(bb, "Error: invalid first line: double"));
	return (0);
}

int get_firstl(t_bsq* bb, int argc, char** argv)
{
	size_t n = 0;
	int by = 0;
	char* p = 0;
	
	if (argc == 2)
	{
		bb->fd = fopen(argv[1], "r");
		if (bb->fd == 0)
			return (ex(bb, "Error: invalid file"));
		by = getline(&p, &n, bb->fd);
		if (by == -1)
		{
			// fclose(bb->fd);
			return (ex(bb, "Error: invalid map"));
		}
		// printf("%s", p);
		// fclose(bb->fd);
	}
	else
	{
		by = getline(&p, &n, stdin);
		if (by == -1)
			return (ex(bb, "Error: stdin"));
		//printf("%s\n", p);
	}
	if (set_vals(bb, p) == -1)
	{
		free(p);
		return (-1);
	}
	free(p);
	return (0);
}

int get_m(t_bsq* bb, int argc)
{
	int i = 0;
	int by = 0;
	size_t n = 0;
	char *p = 0;

	bb->map = malloc((bb->h + 1) * sizeof(char *));
	bb->map[bb->h] = 0;
	while (i < bb->h)
	{
		if (argc == 2)
			by = getline(&p, &n, bb->fd);
		else
			by = getline(&p, &n, stdin);
		if(by == -1)
		{
			int z = 0;
			while (z < i)
				free(bb->map[z++]);
			free(bb->map);
			free(p);
			bb->map = 0;
			return (ex(bb, "Error: invalid map: wrong linecount given/no cells"));
		}
		bb->map[i] = p;
		if (bb->map[i][by - 1] != '\n')
			return (ex(bb, "Error: invalid map: line missing newline"));
		if (bb->w == 0 || (bb->w != 0 && bb->w == by))
			bb->w = by;
		else
		{
			int z = 0;
			while (z < i + 1)
				free(bb->map[z++]);
			free(bb->map);
			bb->map = 0;
			return (ex(bb, "Error: invalid map: invalid linelenght"));
		}
		p = 0;
		i++;
	}
	return (0);
}

int vali(t_bsq* bb)
{
	int i = 0;
	
	while (i < bb->h)
	{
		int x = 0;
		while (x < bb->w - 1)
		{
			if (bb->map[i][x] != bb->em && bb->map[i][x] != bb->ob)
				return (ex(bb, "Error: invalid map: invalid char encounterd"));
			x++;
		}
		i++;
	}
	return (0);
}

int initi(t_bsq* bb, int argc, char** argv)
{
	set_nu(bb);
	if (get_firstl(bb, argc, argv) == -1)
		return (-1);

	if (get_m(bb, argc) == -1)
		return (-1);
	
	if (bb->fd != 0)
		fclose(bb->fd);
	
	bb->fd = 0;
	if (vali(bb) == -1)
		return (-1);
	return (0);
}
