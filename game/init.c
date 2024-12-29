#include "../so_long.h"

int init_map(t_game *game)
{
    char    *line;
    int     fd;
    int     i;

    i = 0;
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (0);
    game->map->height = 0;
    fd = open(game->file_path, O_RDONLY);
    if (fd < 0)
        return (0);
    line = get_next_line(fd);
    if (!line)
        return (0);
    game->map->width = ft_strlen(line) - 1;
    game->map->maps = malloc(sizeof(char *) * (game->map->width + 2)); 
    if (!game->map->maps)
    {
        free(game->map);
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

    ft_printf("Benvenuto al Reparto Ortofrutticolo!\n");

	return (1);
}

