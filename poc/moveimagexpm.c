#include <mlx.h>
#include <unistd.h>
typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;
int main(void)
{
    void *mlx;
    void *win;
    t_data img_data;
    int width;
    int height;
    int i = 0;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Window");
    img_data.img = mlx_xpm_file_to_image(mlx, "sprites/p_stand.xpm", &width, &height);
    if (img_data.img == NULL)
    {
        write(1, "Error loading image\n", 19);
        return (1);
    }
    img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel, &img_data.line_length, &img_data.endian);
    if (img_data.addr == NULL)
    {
        write(1, "Error getting image data address\n", 32);
        return (1);
    }
    while (i < 10)
    {
        mlx_clear_window(mlx, win);
        mlx_put_image_to_window(mlx, win, img_data.img, i * 10, i * 10);
        mlx_do_sync(mlx);
        usleep(100000);  // Retraso de 100 milisegundos
        i++;
    }
    mlx_loop(mlx);
    return (0);
}