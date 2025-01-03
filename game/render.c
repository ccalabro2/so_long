/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:47:39 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/30 17:12:33 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// funzioni che stampano la mappa

void	set_images(t_game *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/wall.xpm", &width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/floor.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/melanzana1.xpm", &width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/carotina.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/exit.xpm", &width, &height);
}

void	render_tile(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wall, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr,
			game->mlx_win, game->floor, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr,
			game->mlx_win, game->player, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->coin, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, x * 80, y * 80, game->map->maps[y][x]);
			x++;
		}
		y++;
	}
}
