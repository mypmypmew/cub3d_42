
#include "include/cub3d.h"

void put_pixel(int x, int y, t_rgb color, t_game *game)
{
	int index;
	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->stride + x * game->bits_per_pixel / 8;
	game->pixels[index] = color.blue;
	game->pixels[index + 1] = color.green;
	game->pixels[index + 2] = color.red;
	game->pixels[index + 3] = (char)255;

}

void init_game(t_game *game) {

	init_player(&game->player);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if(!game->mlx)
		exit(EXIT_FAILURE);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if(!game->img)
		exit(EXIT_FAILURE);

	game->pixels = (char *)game->img->pixels;

	game->bits_per_pixel = 32;

	game->stride = game->img->width * (game->bits_per_pixel / 8);

	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void render(void *param)
{
	t_game *game = (t_game *)param;

	draw_player(WIDTH / 2, HEIGHT / 2, 10, 0xFFFF00, game);
}