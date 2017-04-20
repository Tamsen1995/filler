/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 18:17:44 by tbui              #+#    #+#             */
/*   Updated: 2016/08/21 18:17:47 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIECE current->piece->piece
#define PLATEAU current->plateau->plateau
#define X x
#define Y y

#include "filler.h"
#include "ft_printf.h"

int			to_high_left(t_current *current, char c)
{
	int x;
	int y;

	y = 0;
	while (y < current->plateau->Y)
	{
		x = 0;
		while (x < current->plateau->X)
		{
			if (peut_placer(current, x, y, c))
				return (ft_printf("%d %d\n", y, x));
			x++;
		}
		y++;
	}
	return (0);
}

int			to_high_right(t_current *current, char c)
{
	int x;
	int y;

	x = current->plateau->X - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < current->plateau->Y)
		{
			if (peut_placer(current, x, y, c))
				return (ft_printf("%d %d\n", y, x));
			y++;
		}
		x--;
	}
	return (0);
}

int			to_low_right(t_current *current, char c)
{
	int x;
	int y;

	y = current->plateau->Y - 1;
	while (y >= 0)
	{
		x = current->plateau->X - 1;
		while (x >= 0)
		{
			if (peut_placer(current, x, y, c))
				return (ft_printf("%d %d\n", y, x));
			x--;
		}
		y--;
	}
	return (0);
}

int			to_low_left(t_current *current, char c)
{
	int x;
	int y;

	x = 0;
	while (x < current->plateau->X)
	{
		y = current->plateau->Y - 1;
		while (y >= 0)
		{
			if (peut_placer(current, x, y, c))
				return (ft_printf("%d %d\n", y, x));
			y--;
		}
		x++;
	}
	return (0);
}
