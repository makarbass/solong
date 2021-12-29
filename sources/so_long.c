#include "so_long.h"

void	ft_show_image(t_var *v)
{
	if (v->map[v->x][v->y] == '1')
		v->img = mlx_xpm_file_to_image(v->mlx, "includes/sep.xpm", &v->s, \
				&v->s);
	if (v->map[v->x][v->y] == '0')
		v->img = mlx_xpm_file_to_image(v->mlx, "includes/grass.xpm", &v->s, \
				&v->s);
	if (v->map[v->x][v->y] == 'C')
		v->img = mlx_xpm_file_to_image(v->mlx, "includes/oil.xpm", &v->s, \
				&v->s);
	if (v->map[v->x][v->y] == 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "includes/noexit.xpm", \
				&v->s, &v->s);
		v->x_ext = v->x;
		v->y_ext = v->y;
	}
	if (v->map[v->x][v->y] == 'P')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "includes/right.xpm", &v->s, \
				&v->s);
		v->x_pos = v->x;
		v->y_pos = v->y;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, v->y * v->s, v->x * v->s);
}

int	key_command(int keycode, t_var *vars)
{
	int	ret;

	ret = 0;
	if (keycode == 53)
		ft_free_map(vars, "[ESC]");
	if (keycode == 13)
		ret = move_up(vars, vars->x_pos - 1, vars->y_pos);
	if (keycode == 0)
		ret = move_left(vars, vars->x_pos, vars->y_pos - 1);
	if (keycode == 1)
		ret = move_down(vars, vars->x_pos + 1, vars->y_pos);
	if (keycode == 2)
		ret = move_right(vars, vars->x_pos, vars->y_pos + 1);
	if (ret == 2)
		ft_free_map(vars, "success!");
	return (0);
}

int	shutdown(int status, t_var *var)
{
	(void)var;
	(void)status;
	write(1, "Exit: [RED CROSS]\n", 18);
	exit (0);
}

int	read_image(t_var v)
{
	v.x = 0;
	v.y = 0;
	v.mlx = mlx_init();
	v.img = mlx_xpm_file_to_image(v.mlx, "includes/grass.xpm", &v.s, &v.s);
	v.win = mlx_new_window(v.mlx, v.s * v.columns, v.s * v.lines, "So Long");
	mlx_hook(v.win, 17, 1L << 19, shutdown, &v);
	mlx_hook(v.win, 2, 1L << 0, key_command, &v);
	while (v.x < v.lines)
	{
		write(1, v.map[v.x], v.columns + 1);
		while (v.y < v.columns)
		{
			ft_show_image(&v);
			v.y++;
		}
		v.y = 0;
		v.x++;
	}
	mlx_loop(v.mlx);
	return (0);
}
