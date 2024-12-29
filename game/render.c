#include "../so_long.h"

// funzioni che stampano la mappa

void	set_images(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/wall.xpm", &game->map->width, &game->map->height);
    game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/floor.xpm", &game->map->width, &game->map->height);
    game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/melanzana1.xpm", &game->map->width, &game->map->height);
    game->coin = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/carotina.xpm", &game->map->width, &game->map->height);
    game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/exit.xpm", &game->map->width, &game->map->height);
}

void	render_tile(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wall, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->coin, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit, x, y);

}

void	render_map(t_game *game)
{
	ft_printf("render map!\n");
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, x * 64, y * 64, game->map->maps[y][x]);
			x++;
		}
		y++;
	}
	ft_printf("fine render map\n");
}