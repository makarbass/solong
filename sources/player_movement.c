/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:52:54 by bpatrici          #+#    #+#             */
/*   Updated: 2021/12/29 13:52:56 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_pos(t_var *vars, int x, int y)
{
	if (vars->map[x][y] == '1')
		return (1);
	if (vars->map[x][y] == 'C')
	{
		if (vars->collectible >= 0)
		{
			vars->map[x][y] = '0';
			vars->collectible -= 1;
		}
		if (vars->collectible == 0)
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, "includes/exit.xpm", \
					&vars->s, &vars->s);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
					vars->y_ext * vars->s, vars->x_ext * vars->s);
		}
	}
	if (vars->map[x][y] == 'E')
	{
		if (vars->collectible == 0)
			return (2);
		return (1);
	}
	return (0);
}

int	move_up(t_var *v, int xx, int yy)
{
	int	ret;

	ret = check_pos(v, xx, yy);
	if (ret != 0)
		return (ret);
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/up.xpm", &v->s, \
			&v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, yy * v->s, \
			xx * v->s);
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/grass.xpm", &v->s, \
			&v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->y_pos * v->s, \
			v->x_pos * v->s);
	v->x_pos -= 1;
	count_moves(v);
	return (0);
}

int	move_down(t_var *v, int xx, int yy)
{
	int	ret;

	ret = check_pos(v, xx, yy);
	if (ret != 0)
		return (ret);
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/down.xpm", &v->s, \
			&v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, yy * v->s, \
			xx * v->s);
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/grass.xpm", &v->s, \
			&v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->y_pos * v->s, \
			v->x_pos * v->s);
	v->x_pos += 1;
	count_moves(v);
	return (0);
}

int	move_right(t_var *v, int xx, int yy)
{
	int	ret;

	ret = check_pos(v, xx, yy);
	if (ret != 0)
		return (ret);
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/right.xpm", &v->s, \
			&v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, yy * v->s, \
			xx * v->s);
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/grass.xpm", &v->s, \
			&v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->y_pos * v->s, \
			v->x_pos * v->s);
	v->y_pos += 1;
	count_moves(v);
	return (0);
}

int	move_left(t_var *v, int xx, int yy)
{
	int	ret;

	ret = check_pos(v, xx, yy);
	if (ret != 0)
		return (ret);
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/left.xpm", &v->s, \
			&v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, yy * v->s, \
			xx * v->s);
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/grass.xpm", &v->s, \
			&v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->y_pos * v->s, \
			v->x_pos * v->s);
	v->y_pos -= 1;
	count_moves(v);
	return (0);
}
