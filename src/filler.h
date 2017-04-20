/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 18:15:23 by tbui              #+#    #+#             */
/*   Updated: 2016/08/21 18:15:26 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_plateau
{
	int		x;
	int		y;
	char	**plateau;
}				t_plateau;

typedef struct	s_piece
{
	int		x;
	int		y;
	char	**piece;
}				t_piece;

typedef struct	s_current
{
	int			player;
	char		mysign;
	t_piece		*piece;
	t_plateau	*plateau;
}				t_current;

int				advance_j(int i, int j, t_current *current);
int				advance_i(int i, int j, t_current *current);
int				peut_placer(t_current *current, int x, int y, char c);
void			find_solution(t_current *current);
int				to_low_left(t_current *current, char c);
int				to_low_right(t_current *current, char c);
int				to_high_right(t_current *current, char c);
int				to_high_left(t_current *current, char c);
void			parsing_module(t_current *current, int *tab);
int				free_tab_str(char **str);
void			make_struct(t_current *current, int *tab);
void			fill_field(t_current *current, char **line, int *tab);
void			get_piece(t_current *current, char **line, int *tab);
int				get_next_line(int const fd, char **line);
void			find_solution(t_current *current);

#endif
