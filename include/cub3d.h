#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 800
#define HEIGHT 600

#define W 119
#define A 97
#define S 115
#define D 100

#define PI 3.1415926 //535

#include "../mlx42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>



typedef union u_rgb {
	int value;
	struct {
		uint8_t blue;
		uint8_t green;
		uint8_t red;
	};
} t_rgb;

typedef struct s_game {
	mlx_t *mlx;
	mlx_image_t *img;

	int stride;
	char *pixels;
	int bits_per_pixel;
} t_game;

typedef struct s_player {
	float x;
	float y;

} t_player;

void draw_player(int x, int y, int size, int color_val, t_game *game);
void put_pixel(int x, int y, t_rgb color, t_game *game);
void init_game(t_game *game);
void render(void *param);

#endif
