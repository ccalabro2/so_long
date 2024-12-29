#include "../so_long.h"

// funzione per cercare le coordinate del player
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

void flood_fill(t_game *game, int y, int x)
{
    // controlla che la cella non sia fuori dai limiti e che non sia una parete ('1') o già visitata ('#')
    if (y < 0 || y >= game->map->height || x < 0 || x >= game->map->width
        || game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == '#')
    {
        return;
    }

    // segna la cella come visitata
    game->mapcopy[y][x] = '#';  

    // esplora celle adiacenti
    flood_fill(game, y - 1, x);  // su
    flood_fill(game, y, x - 1);  // sinistra
    flood_fill(game, y + 1, x);  // giù
    flood_fill(game, y, x + 1);  // destra
}

void	print_mapcopy(t_game *game)
{
	for (int y = 0; y < game->map->height; y++)
		ft_printf("%s\n", game->mapcopy[y]);
	ft_printf("\n");
}


// controllo che le C e le E siano raggiungibili
int	path_finder(t_game *game)
{
	int	y;
	int	x;

	y = 0;

    print_mapcopy(game);
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
