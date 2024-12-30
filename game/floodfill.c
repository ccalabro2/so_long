/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:47:16 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/30 17:44:24 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// copia della mappa su cui eseguiamo il flood fill
void	init_mapcopy(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->mapcopy = malloc(sizeof(char *) * game->map->height);
	if (!game->mapcopy)
		return ;
	while (y < game->map->height)
	{
		x = 0;
		game->mapcopy[y] = malloc(sizeof(char) * (game->map->width + 1));
		if (!game->mapcopy[y])
			return ;
		while (x < game->map->width)
		{
			game->mapcopy[y][x] = game->map->maps[y][x];
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->map->height || x < 0 || x >= game->map->width)
		return ;
	if (game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == '#')
		return ;
	game->mapcopy[y][x] = '#';
	flood_fill(game, y - 1, x);
	flood_fill(game, y, x - 1);
	flood_fill(game, y + 1, x);
	flood_fill(game, y, x + 1);
}

void	print_mapcopy(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		ft_printf("%s\n", game->mapcopy[y]);
		y++;
	}
}

// controllo che le C e le E siano raggiungibili
int	path_finder(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->mapcopy[y][x] == 'C' || game->mapcopy[y][x] == 'E')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_path(t_game *game)
{
	init_mapcopy(game);
	player_position(game);
	flood_fill(game, game->y, game->x);
	if (path_finder(game))
		return (1);
	else
		return (0);
}
