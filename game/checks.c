/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:47:03 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/30 16:54:52 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_dim(t_game *game)
{
	int	len;
	int	i;

	i = -1;
	while (++i < game->map->height)
	{
		len = ft_strlen(game->map->maps[i]) - 1;
		if (len != game->map->width)
		{
			ft_printf("Ci sta un problemino!\n");
			return (0);
		}
	}
	return (1);
}

int	check_border(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map->height)
	{
		if (game->map->maps[i][0] != '1' ||
			game->map->maps[i][game->map->width - 1] != '1')
		{
			ft_printf("Error on column\n");
			return (0);
		}
	}
	i = -1;
	while (++i < game->map->width)
	{
		if (game->map->maps[0][i] != '1' ||
			game->map->maps[game->map->height - 1][i] != '1')
		{
			ft_printf("Error on line\n");
			return (0);
		}
	}
	return (1);
}

int	check_info(t_game *game)
{
	int	i;
	int	j;

	if (!init_game(game))
		return (0);
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->maps[i][j] == 'P')
				game->c_player++;
			if (game->map->maps[i][j] == 'C')
				game->c_coin++;
			if (game->map->maps[i][j] == 'E')
				game->c_exit++;
		}
	}
	if (game->c_player != 1 || game->c_exit != 1 || game->c_coin < 1)
		return (0);
	return (1);
}

int	check_chars(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->height)
	{
		y = 0;
		while (y < game->map->width)
		{
			if (game->map->maps[x][y] != 'P'
					&& game->map->maps[x][y] != 'C'
					&& game->map->maps[x][y] != 'E'
					&& game->map->maps[x][y] != 'W'
					&& game->map->maps[x][y] != '0'
					&& game->map->maps[x][y] != '1')
			{
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

void	check_map(t_game *game)
{
	if (!init_map(game) || !check_dim(game)
		|| !check_border(game) || !check_path(game)
		|| !check_info(game) || !check_chars(game))
	{
		ft_printf("OPS! La tua mappa non ci piace :c\n");
		ft_exit(game);
	}
}
