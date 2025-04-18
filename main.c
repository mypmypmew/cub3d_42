
#include "include/cub3d.h"

void put_pixel(int x, int y, int color, t_game *game)
{
	int	index;
	t_rgb rgb;

	rgb.value = 0x3366CC;

	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->stride + x * game->bits_per_pixel / 8;
	game->pixels[index] = rgb.blue;
	game->pixels[index + 1] = rgb.green;
	game->pixels[index + 2] = rgb.red;

}

void init_game(t_game *game) {
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	game->mlx = mlx_new_image(game->mlx, WIDTH, HEIGHT);

	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

int main(void)
{
	t_game game;

	init_game(&game);

	mlx_loop(game.mlx);

	return EXIT_SUCCESS;
}