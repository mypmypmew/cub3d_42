#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 800
#define HEIGHT 600

#define TRUE 1
#define FALSE 0

typedef enum e_key {
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
} t_key;

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

typedef struct s_player {
	float x;
	float y;

	uint8_t up;
	uint8_t down;
	uint8_t left;
	uint8_t right;

} t_player;

typedef struct s_game {
	mlx_t *mlx;
	mlx_image_t *img;

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
void unpress_key(mlx_key_data_t keydata, void *param);
void press_key(mlx_key_data_t keydata, void *param);

#endif
