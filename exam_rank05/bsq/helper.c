/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:48:05 by tabading          #+#    #+#             */
/*   Updated: 2025/08/10 13:26:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void print_m(char** m)
{
	int i = 0;

	while (m[i])
		printf("%s", m[i++]);
}

void free_m(t_bsq* bb)
{
	int i = 0;
	while (bb->map[i])
		free(bb->map[i++]);
	free(bb->map[i++]);
	free(bb->map);
}

int ex(t_bsq* bb, char* err)
{
	if (bb->fd != 0)
	{
		fclose(bb->fd);
		bb->fd = 0;
	}
	if (bb->map)
		free_m(bb);
	printf("%s\n", err);
	return (-1);
}
