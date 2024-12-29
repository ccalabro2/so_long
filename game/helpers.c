#include "../so_long.h"

void ft_free_matrix(t_game *game)
{
    int i;

    i = -1;
    if (game->map && game->map->maps)
    {
        while (++i < game->map->height)
        {
            free(game->map->maps[i]);
            game->map->maps[i] = NULL;
        }
        free(game->map->maps);
        game->map->maps = NULL;
    }
    i = -1;
    if (game->mapcopy)
    {
        while (++i < game->map->height)
        {
            free(game->mapcopy[i]);
            game->mapcopy[i] = NULL;  
        }
        free(game->mapcopy);
        game->mapcopy = NULL; 
    }
}

void ft_exit(t_game *game)
{
    ft_free_matrix(game);
    if (game->map)
    {
        free(game->map);
        game->map = NULL;
    }
    if (game->mlx_ptr && game->mlx_win)
        mlx_destroy_window(game->mlx_ptr, game->mlx_win);  
    free(game);  
    game = NULL;  
}
