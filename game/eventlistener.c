#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)  
		ft_exit(game, 0);
	else if (keycode == 13) 
		move_up(game);
	else if (keycode == 1) 
		move_down(game);
	else if (keycode == 0) 
		move_left(game);
	else if (keycode == 2)  
		move_right(game);
	// qua funzione per contare i passi
	render_map(game); 
	return (0);
}

int	exit_hook(t_game *game)
{
	ft_exit(game, 0);
	return (0);
}
