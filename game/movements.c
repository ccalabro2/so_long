#include "../so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map->maps[new_y][new_x] != '1')
	{
		if (game->map->maps[new_y][new_x] == 'C')
			game->c_coin--;
		if (game->map->maps[new_y][new_x] == 'E')
		{
			if (game->c_coin)
				return ;
			ft_printf("YOU WON!\n");
			ft_exit(game);
		}
		game->map->maps[game->y][game->x] = '0';
		game->x = new_x;
		game->y = new_y;
		game->map->maps[new_y][new_x] = 'P';

		game->steps++;
        ft_printf("Passetti: %d\n", game->steps); 
	}
}

void	move_up(t_game *game)
{
	move_player(game, game->x, game->y - 1);
}

void	move_down(t_game *game)
{
	move_player(game, game->x, game->y + 1);
}

void	move_left(t_game *game)
{
	move_player(game, game->x - 1, game->y);
}

void	move_right(t_game *game)
{
	move_player(game, game->x + 1, game->y);
}
