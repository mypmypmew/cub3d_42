
#include "include/cub3d.h"


int main(void)
{
	t_game game;

	init_game(&game);

	mlx_key_hook(game.mlx, press_key, &game);
	mlx_key_hook(game.mlx, unpress_key, &game);

	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);

	return EXIT_SUCCESS;
}