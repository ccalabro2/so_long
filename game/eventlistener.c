#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)  // ESC key
		ft_exit(game, 0);
	else if (keycode == 13)  // W key
		move_up(game);
	else if (keycode == 1)  // S key
		move_down(game);
	else if (keycode == 0)  // A key
		move_left(game);
	else if (keycode == 2)  // D key
		move_right(game);
	print_map_info(game);  // Print moves to terminal
	render_map(game);  // Re-render map
	return (0);
}

int	exit_hook(t_game *game)
{
	ft_exit(game, 0);
	return (0);
}
