#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 1280
#define HEIGHT 720

#define TILE_SIZE 64

#define TRUE 1
#define FALSE 0

#define LEFT 65361
#define RIGHT 65363

#define PI 3.1415926 //535

#include "../mlx42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct s_input {
	bool up;
	bool down;
	bool left;
	bool right;
	bool rotate_left;
	bool rotate_right;
} t_input;

typedef union u_rgb {
	int value;
	struct {
		uint8_t blue;
		uint8_t green;
		uint8_t red;
	};
} t_rgb;

typedef struct s_player {
	float x;
	float y;
	float angle;

	uint8_t up;
	uint8_t down;
	uint8_t left;
	uint8_t right;

	bool left_rotate;
	bool right_rotate;

	t_input input;

} t_player;

typedef struct s_game {
	mlx_t *mlx;
	mlx_image_t *img;

	char **map;

	int stride;
	char *pixels;
	int bits_per_pixel;
	t_player player;
} t_game;

void draw_player(int x, int y, int size, int color_val, t_game *game);
void put_pixel(int x, int y, t_rgb color, t_game *game);
void init_game(t_game *game);
void render(void *param);
void init_player(t_player *player);
void handle_key(mlx_key_data_t keydata, void *param);
void move_player(t_game *game);

#endif
