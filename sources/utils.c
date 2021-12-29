#include "so_long.h"

void	ft_free_map(t_var *var, char *msg)
{
	int	x;

	x = 0;
	while (x < var->lines)
	{
		free(var->map[x]);
		x++;
	}
	free(var->map);
	if (!var->ptr)
		free(var->ptr);
	printf("Exit: %s\n", msg);
	exit (0);
}

int	ft_lines(char *map, t_var var)
{
	int		fd;
	int		nb;
	char	*line;

	nb = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free_map(&var, "Map error");
	line = get_next_line(fd);
	while (line)
	{
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (nb < 3)
		ft_free_map(&var, "Map error");
	return (nb);
}

int	ft_columns(char *map, t_var var)
{
	int		fd;
	int		nb;
	int		ret;
	char	line[2];

	nb = -1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free_map(&var, "Map error");
	while (!ft_strchr(line, '\n'))
	{
		ret = read(fd, line, 1);
		if (ret < 0)
			return (0);
		line[ret] = '\0';
		nb++;
	}
	close(fd);
	if (nb < 3)
		ft_free_map(&var, "Map error");
	return (nb);
}

void	count_moves(t_var *v)
{
	static int	moves;

	moves += 1;
	if (moves != 1)
		free(v->ptr);
	v->ptr = ft_itoa(moves);
	if (!v->ptr)
		return ;
	v->img = mlx_xpm_file_to_image(v->mlx, "includes/sep.xpm", &v->s, &v->s);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	v->str = mlx_string_put(v->mlx, v->win, 5, 15, 0x0000FF00, \
			v->ptr);
}
