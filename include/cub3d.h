#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 800
#define HEIGHT 600

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
	void *mlx;
	void *img;

	/* for Drawing pixels */
	int stride;
	int bits_per_pixel;
	char *pixels;
} t_game;

#endif
