/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:04:34 by tabading          #+#    #+#             */
/*   Updated: 2025/08/04 09:24:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void fr(t_life* l, int a)
{
	int i = 0;
	while (i < l->h)
		free(l->board[i++]);
	free(l->board[i]);
	free(l->board);
	if (a == 1 && V == 0)
	{
		free(l->input);
		l->input = 0;
	}
}
