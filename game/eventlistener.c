#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)  
		ft_exit(game);
	else if (keycode == 119 || keycode == 13) 
		move_up(game);
	else if (keycode == 115 || keycode == 1) 
		move_down(game);
	else if (keycode == 97 || keycode == 0) 
		move_left(game);
	else if (keycode == 100 || keycode == 2) 
		move_right(game);
	render_map(game);
	return (0);
}

int	exit_hook(t_game *game)
{
	ft_exit(game);
	return (0);
}
