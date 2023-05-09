#include "so_long.h"
#include <stdio.h>

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width, height;
    char *file_path = "tests/wall.xpm";

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        fprintf(stderr, "Error: mlx_init() failed\n");
        return 1;
    }

    win_ptr = mlx_new_window(mlx_ptr, 640, 480, "Example XPM");
    if (!win_ptr)
    {
        fprintf(stderr, "Error: mlx_new_window() failed\n");
        return 1;
    }

    img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_path, &width, &height);
    if (!img_ptr)
    {
        fprintf(stderr, "Error: mlx_xpm_file_to_image() failed\n");
        return 1;
    }

    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_loop(mlx_ptr);
    return 0;
}