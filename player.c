
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

void init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;

	player->up = false;
	player->down = false;
	player->right = false;
	player->left = false;
}

void press_key(int keycode, t_player *player)
{
	if(keycode == KEY_W)
		player->up = TRUE;
	if(keycode == KEY_S)
		player->down = TRUE;
	if(keycode == KEY_A)
		player->left = TRUE;
	if(keycode == KEY_D)
		player->right = TRUE;
	return 0;
}

void unpress_key(int keycode, t_player *player)
{
	if(keycode == KEY_W)
		player->up = FALSE;
	if(keycode == KEY_S)
		player->down = FALSE;
	if(keycode == KEY_A)
		player->left = FALSE;
	if(keycode == KEY_D)
		player->right = FALSE;
}

