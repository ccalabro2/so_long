#include "so_long.h"

void	print_map_info(t_game *game)
{
	for (int i = 0; i < game->map->height; i++)
		ft_printf("%s", game->map->maps[i]);
	ft_printf("Height: %d\n Width: %d\n",game->map->height, game->map->width);
}

int init_map(t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	game->map = malloc(sizeof(t_map *));
	game->map->height = 0;
	fd = open(game->file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		game->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	fd = open(game->file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	game->map->maps = malloc(game->map->height * sizeof(char **) + 1);
	if (!game->map->maps)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		game->map->maps[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->map->maps[i] = NULL;
	game->map->width = ft_strlen(game->map->maps[0]) - 1;
	free(line);
	close(fd);
	// print_map_info(game);
	return (1);
}

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
	int i;

	i = -1;
	while ( ++i < game->map->height)
	{
		if (game->map->maps[i][0] != '1' || game->map->maps[i][game->map->width - 1] != '1')
		{
			ft_printf("Error on column\n");
			return (0);
		}
	}
	i = -1;
	while ( ++i < game->map->width)
	{
		if (game->map->maps[0][i] != '1' || game->map->maps[game->map->height - 1][i] != '1')
		{
			ft_printf("Error on line\n");
			return (0);
		}
	}
	return (1);
}

int init_info(t_game *game)
{
	game->info = malloc(sizeof(t_info *));
	if (!game->info)
		return (0);
	game->info->c_player = 0;
	game->info->c_coin = 0;
	game->info->c_exit = 0;
	return (1);
}

int check_info(t_game *game)
{
	int	i;
	int	j;

	if (!init_info(game))
		return (0);
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->maps[i][j] == 'P')
				game->info->c_player++;
			if (game->map->maps[i][j] == 'C')
				game->info->c_coin++;
			if (game->map->maps[i][j] == 'E')
				game->info->c_exit++;
		}
	}
	if (game->info->c_player != 1 || game->info->c_exit != 1 || game->info->c_coin < 1)
		return (0);
	return (1);
}

void	check_map(t_game *game)
{
	if(!init_map(game) || !check_dim(game) || !check_border(game))
		ft_exit(game, 1);
	if (!check_info(game))
		ft_exit(game, 2);
}

void	ft_free_matrix(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->map->height)
		free(game->map->maps[i]);
	free(game->map->maps);
}

void	ft_exit(t_game *game, int flag)
{
	if (flag > 0)
		ft_free_matrix(game);
	if (flag > 1)
		free(game->info);
	free(game);
}

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	game = malloc(sizeof(t_game*));
	if (!game)
		return (1);
	game->file_path = argv[1];
	check_map(game);
	// Next: flood fill
	// MLX
	return (0);
}
