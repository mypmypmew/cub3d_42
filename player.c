
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
	player->angle = PI / 2;

	player->up = false;
	player->down = false;
	player->right = false;
	player->left = false;

	player->left_rotate = false;
	player->right_rotate = false;
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
	if (keydata.key == MLX_KEY_LEFT)
		player->left_rotate = is_pressed;
	if (keydata.key == MLX_KEY_RIGHT)
		player->right_rotate = is_pressed;
}

void move_player(t_player *player)
{
	int speed = 5;
	float rotate_speed;

	rotate_speed = 0.05;

float cos_angle = cos(player->angle);
float sin_angle = sin(player->angle);

if (player->left_rotate)
	player->angle -= rotate_speed;
if (player->right_rotate)
	player->angle += rotate_speed;

if (player->angle > 2 * PI)
	player->angle -= 2 * PI;
if (player->angle < 0)
	player->angle += 2 * PI;


if (player->up)
{
	player->x += cos_angle * speed;
	player->y += sin_angle * speed;
}
if (player->down)
{
	player->x -= cos_angle * speed;
	player->y -= sin_angle * speed;
}
if (player->left)
{
	player->x -= sin_angle * speed;
	player->y += cos_angle * speed;
}
if (player->right)
{
	player->x += sin_angle * speed;
	player->y -= cos_angle * speed;
}
}

