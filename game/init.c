/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:47:27 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/31 01:17:21 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	allocate_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (0);
	game->map->height = 0;
	game->map->maps = NULL;
	return (1);
}

int	load_map_data(t_game *game, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	game->map->width = ft_strlen(line) - 1;
	game->map->maps = malloc(sizeof(char *) * (game->map->width + 2));
	if (!game->map->maps)
	{
		free(line);
		return (0);
	}
	while (line)
	{
		game->map->maps[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map->height = i;
	game->map->maps[i] = NULL;
	return (1);
}

int	init_map(t_game *game)
{
	int	fd;

	if (!allocate_map(game))
		return (0);
	fd = open(game->file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!load_map_data(game, fd))
	{
		free(game->map);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	init_game(t_game *game)
{
	game->c_player = 0;
	game->c_coin = 0;
	game->c_exit = 0;
	game->steps = 0;
	game->wall = NULL;
	game->floor = NULL;
	game->coin = NULL;
	game->player = NULL;
	game->exit = NULL;
	ft_printf("Benvenuto al Reparto Ortofrutticulo!\n");
	return (1);
}
