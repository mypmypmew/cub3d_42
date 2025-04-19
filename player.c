
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

void handle_key(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;
	t_player *player = &game->player;
	int is_pressed = (keydata.action == MLX_PRESS);

	if (keydata.key == MLX_KEY_W)
		player->up = is_pressed;
	if (keydata.key == MLX_KEY_S)
		player->down = is_pressed;
	if (keydata.key == MLX_KEY_A)
		player->left = is_pressed;
	if (keydata.key == MLX_KEY_D)
		player->right = is_pressed;
}

void move_player(t_player *player)
{
	int speed;

	speed = 10;

	if(player->up)
		player->y -= speed;
	if(player->down)
		player->y += speed;
	if(player->left)
		player->x -= speed;
	if(player->right)
		player->x += speed;
}

