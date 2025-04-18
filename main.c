
#include "mlx42/include/MLX42/MLX42.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

// gcc main.c mlx42/build/libmlx42.a -Iinclude -lglfw -framework Cocoa -framework
//OpenGL -framework IOKit

void keyhook(mlx_key_data_t keydata, void *param)
{
	if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window((mlx_t*)param);
	}
}

int main(void)
{
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Hello MLX42", true);
    if (!mlx)
        return EXIT_FAILURE;

    mlx_key_hook(mlx, keyhook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}