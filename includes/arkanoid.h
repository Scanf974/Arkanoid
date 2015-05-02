/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:49:08 by bsautron          #+#    #+#             */
/*   Updated: 2015/05/02 14:36:03 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <GLFW/glfw3.h>
# include <fcntl.h>
# include <libft.h>
# include <get_next_line.h>
# include <math.h>
# include <stdio.h>///////////////////////////////////
////////////////////////////////////////////////////

typedef struct		s_pt2d
{
	int			x;
	int			y;
}					t_pt2d;

typedef struct		s_ball
{
	t_pt2d		pos;
	float		radius;
}					t_ball;

typedef struct		s_bar
{
	t_pt2d		pos;
	float		h;
	float		w;
}					t_bar;

typedef struct		s_env
{
	int			height;
	int			width;
	t_ball		ball;
	t_bar		bar;
	char		**map;
}					t_env;

#endif
