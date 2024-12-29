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
	if(!init_map(game) || !check_dim(game) || !check_border(game) || !check_path(game))
		ft_exit(game, 1);
	if (!check_info(game))
		ft_exit(game, 2);
}
