
#include "include/cub3d.h"

bool is_wall(float x, float y, t_game *game)
{
	int grid_x = x / TILE_SIZE;
	int grid_y = y / TILE_SIZE;

	if (grid_x < 0 || grid_y < 0 || grid_y >= MAP_HEIGHT || grid_x >= MAP_WIDTH)
		return true;

	return (game->map[grid_y][grid_x] == '1');
}

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

float normalize_angle(float angle)
{
	if(angle < 0)
		return (angle + 2 * PI);
	if(angle >= 2 * PI)
		return angle - 2 * PI;
	return angle;
}

void move_player(t_game *game)
{
	t_player *player = &game->player;
	float speed = 5.0f;
	float rotate_speed = 0.05f;

	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		player->angle -= rotate_speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		player->angle += rotate_speed;

	player->angle = normalize_angle(player->angle);

	float cos_a = cos(player->angle);
	float sin_a = sin(player->angle);

	float new_x, new_y;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		new_x = player->x + cos_a * speed;
		new_y = player->y + sin_a * speed;
		if (!is_wall(new_x, player->y, game))
			player->x = new_x;
		if (!is_wall(player->x, new_y, game))
			player->y = new_y;
	}

	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		new_x = player->x - cos_a * speed;
		new_y = player->y - sin_a * speed;
		if (!is_wall(new_x, player->y, game))
			player->x = new_x;
		if (!is_wall(player->x, new_y, game))
			player->y = new_y;
	}

	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		new_x = player->x + sin_a * speed;
		new_y = player->y - cos_a * speed;
		if (!is_wall(new_x, player->y, game))
			player->x = new_x;
		if (!is_wall(player->x, new_y, game))
			player->y = new_y;
	}

	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		new_x = player->x - sin_a * speed;
		new_y = player->y + cos_a * speed;
		if (!is_wall(new_x, player->y, game))
			player->x = new_x;
		if (!is_wall(player->x, new_y, game))
			player->y = new_y;
	}
}