/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:51:38 by bpatrici          #+#    #+#             */
/*   Updated: 2021/12/29 13:52:21 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc != 2)
		write(1, "Error\n", 6);
	if (argc == 2)
	{
		var.lines = ft_lines(argv[1]);
		var.columns = ft_columns(argv[1]);
		var.map = map_storage(argv[1], var);
		if (map_validity(&var) == 1)
			ft_free_map(&var, "Map error");
		read_image(var);
	}
	return (0);
}
