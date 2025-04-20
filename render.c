
#include "include/cub3d.h"

char **get_map(void)
{
	char **map = malloc(sizeof(char *) * 11);

	map[0] = "111111111111111";
	map[1] = "100000000000001";
	map[2] = "100000000000001";
	map[3] = "100000000000001";
	map[4] = "100000000000001";
	map[5] = "100000000000001";
	map[6] = "100000000000001";
	map[7] = "100000000000001";
	map[8] = "100000000000001";
	map[9] = "111111111111111";
	map[10] = NULL;
	return (map);

}

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

	game->map = get_map();

	game->pixels = (char *)game->img->pixels;

	game->bits_per_pixel = 32;

	game->stride = game->img->width * (game->bits_per_pixel / 8);

	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void clear_screen(t_game *game, uint32_t color)
{
	t_rgb rgb;
	rgb.value = color;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			put_pixel(x, y, rgb, game);
		}
	}
}

void draw_map(t_game *game)
{
	char **map = game->map;
	int color = 0x000FF;
	for(int y = 0; map[y]; y++)
	{
		for(int x = 0; map[y][x]; x++)
		{
			if(map[y][x] == '1')
				draw_player(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, color, game);

		}
	}
}

bool touch_edge(float px, float py, t_game *game)
{
	int map_heigt = 10;
	int map_width = 15;
	int x = px / TILE_SIZE;
	int y = py / TILE_SIZE;
	if (x < 0 || y < 0 || y >= map_heigt || x >= map_width)
		return true;
	if(game->map[y][x] == '1')
		return true;
	return false;
}

void render(void *param)
{
	t_game *game = (t_game *)param;
	t_player *player = &game->player;

	t_rgb rgb;
	rgb.value = 0xFF0000;

	clear_screen(game, 0x000000);
	move_player(game);
	draw_player(player->x, player->y, 10, 0xFFFF00, game);
	draw_map(game);

	float ray_x = player->x;
	float ray_y = player->y;
	float cos_angle = cos(player->angle);
	float sin_angle = sin(player->angle);

	while(!touch_edge(ray_x, ray_y, game))
	{
		put_pixel(ray_x, ray_y, rgb, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}