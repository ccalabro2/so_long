/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:47:22 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/30 17:46:41 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_matrix(char **matrix, int height)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < height)
	{
		if (matrix[i])
			free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_exit(t_game *game)
{
	if (game->mlx_ptr && game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (game->map)
	{
		if (game->map->maps)
			free_matrix(game->map->maps, game->map->height);
		free(game->map);
	}
	if (game->mapcopy)
		free_matrix(game->mapcopy, game->map->height - 1);
	free(game);
	exit(0);
}

void	player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->maps[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
			}
			x++;
		}
		y++;
	}
}
