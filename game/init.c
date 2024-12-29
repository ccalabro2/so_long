#include "../so_long.h"

int init_map(t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	
	game->map = malloc(sizeof(t_map));
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
	return (1);
}

int init_game(t_game *game)
{
	game->c_player = 0;
	game->c_coin = 0;
	game->c_exit = 0;
	game->wall = NULL;
	game->floor = NULL;
	game->coin = NULL;
	game->player = NULL;
	game->exit = NULL;

	return (1);
}

