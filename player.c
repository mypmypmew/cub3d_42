
#include "include/cub3d.h"

void draw_player(int x, int y, int size, int color_val, t_game *game)
{
	t_rgb color;
	color.value = color_val;


	for (int i = 0; i < size; i++)
		put_pixel(x + i, y, color, game);

	for (int i = 0; i < size; i++)
		put_pixel(x, y + i, color, game);

	for (int i = 0; i < size; i++)
		put_pixel(x + size, y + i, color, game);

	for (int i = 0; i < size; i++)
		put_pixel(x + i, y + size, color, game);
}

