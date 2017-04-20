/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 17:55:43 by tbui              #+#    #+#             */
/*   Updated: 2016/08/21 17:55:53 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIECE current->piece->piece
#define PLATEAU current->plateau->plateau
#define X x
#define Y y

#include "filler.h"

int			advance_j(int i, int j, t_current *current)
{
	while (j != current->piece->Y)
	{
		while (i != current->piece->X)
		{
			if (PIECE[j][i] == '*')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

int			advance_i(int i, int j, t_current *current)
{
	while (i != current->piece->X)
	{
		while (j != current->piece->Y)
		{
			if (PIECE[j][i] == '*')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int			peut_placer(t_current *current, int x, int y, char c)
{
	int i;
	int j;
	int count;

	count = 0;
	j = advance_j(0, 0, current);
	while (j != current->piece->Y)
	{
		i = advance_i(0, j, current);
		while (i != current->piece->X)
		{
			if (((y + j) >= current->plateau->Y || (x + i) >=
						current->plateau->X) && PIECE[j][i] != '.')
				return (0);
			if ((PIECE[j][i] == '*') &&
				(PLATEAU[y + j][x + i] == c || PLATEAU[y + j][x + i] == c - 32))
				count++;
			else if ((PIECE[j][i] == '*') && (PLATEAU[y + j][x + i] != '.') &&
				PLATEAU[y + j][x + i] != 'c' && PLATEAU[y + j][x + i] != c - 32)
				return (0);
			i++;
		}
		j++;
	}
	return (count == 1 ? 1 : 0);
}

void		find_solution(t_current *current)
{
	int				(*place[4])(t_current *current, char c);
	static int		i = 0;
	int				end;

	place[0] = to_high_left;
	place[1] = to_high_right;
	place[2] = to_low_right;
	place[3] = to_low_left;
	end = 0;
	while ((place[i % 4](current, current->mysign) == 0))
	{
		i++;
		end++;
		if (end == 4)
		{
			ft_putstr("0 0\n");
			return ;
		}
	}
	i++;
}
