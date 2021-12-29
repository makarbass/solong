#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	char	*ptr;
	int		str;
	int		x;
	int		y;
	int		lines;
	int		columns;
	int		x_pos;
	int		y_pos;
	int		x_ext;
	int		y_ext;
	int		s;
	int		player;
	int		collectible;
	int		ext;
}				t_var;

char	**map_storage(char *path, t_var var);
int		ft_lines(char *map, t_var var);
int		ft_columns(char *map, t_var var);
int		map_validity(t_var *var);
int		read_image(t_var v);
int		move_up(t_var *v, int xx, int yy);
int		move_down(t_var *v, int xx, int yy);
int		move_left(t_var *v, int xx, int yy);
int		move_right(t_var *v, int xx, int yy);
void	count_moves(t_var *vars);
void	ft_free_map(t_var *var, char *msg);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif
