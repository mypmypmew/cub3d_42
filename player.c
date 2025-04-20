
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

	player->input.up = false;
	player->input.down = false;
	player->input.right = false;
	player->input.left = false;

	player->input.rotate_left = false;
	player->input.rotate_right = false;
}

void handle_key(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;
	t_player *player = &game->player;
	int is_pressed = (keydata.action == MLX_PRESS);

	if (keydata.key == MLX_KEY_W)
		player->input.up = is_pressed;
	if (keydata.key == MLX_KEY_S)
		player->input.down = is_pressed;
	if (keydata.key == MLX_KEY_A)
		player->input.left = is_pressed;
	if (keydata.key == MLX_KEY_D)
		player->input.right = is_pressed;
	if (keydata.key == MLX_KEY_LEFT)
		player->input.rotate_left = is_pressed;
	if (keydata.key == MLX_KEY_RIGHT)
		player->input.rotate_right = is_pressed;
}

void move_player(t_game *game)
{
	t_player *player = &game->player;
	mlx_t *mlx = game->mlx;

	float speed = 5.0f;
	float rotate_speed = 0.05f;

	// Поворот
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		player->angle -= rotate_speed;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		player->angle += rotate_speed;

	// Нормализовать угол
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;

	// Движение
	float cos_a = cos(player->angle);
	float sin_a = sin(player->angle);

	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->x += cos_a * speed;
		player->y += sin_a * speed;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		player->x -= cos_a * speed;
		player->y -= sin_a * speed;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		player->x -= sin_a * speed;
		player->y += cos_a * speed;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		player->x += sin_a * speed;
		player->y -= cos_a * speed;
	}
}
