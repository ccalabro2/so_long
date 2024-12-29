#include "so_long.h"
#include "mlx/mlx.h"

// PROBLEMINI:
// va in SEGFAULT se:
// - la mappa non passa il flood fill
// - non si va a capo dopo l'ultima riga della mappa


void	print_map_info(t_game *game)
{
	for (int i = 0; i < game->map->height; i++)
		ft_printf("%s", game->map->maps[i]);
	ft_printf("Height: %d\n Width: %d\n",game->map->height, game->map->width);
}

int	main(int argc, char **argv)
{
    t_game	*game;

    if (argc != 2 || ft_endcmp(argv[1], ".ber"))
        return (ft_printf("Invalid arguments! :c\n"), 1);
    
    game = malloc(sizeof(t_game));
    if (!game)
        return (1);
    
    game->file_path = argv[1];
    check_map(game); 
    
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        return (1);
    game->mlx_win = mlx_new_window(game->mlx_ptr, game->map->width * 64, game->map->height * 64, "REPARTO ORTOFRUTTICOLO");
    if (!game->mlx_win)
        mlx_destroy_window(game->mlx_ptr, game->mlx_win);
    
    set_images(game);
    render_map(game);

    mlx_key_hook(game->mlx_win, key_hook, game);
    mlx_hook(game->mlx_win, 17, 0, exit_hook, game);
    mlx_loop(game->mlx_ptr);
    
    return (0);
}

