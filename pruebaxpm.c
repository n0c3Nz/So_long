#include "so_long.h"

int main()
{
	int endian;
	char *img_data;
	void *mlx_ptr = mlx_init();
    if (!mlx_ptr) { return 1; }
    void *win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Mi ventana");

    // Cargar una imagen XPM desde un archivo
    int width, height;
    void *img_ptr = mlx_xpm_file_to_image(mlx_ptr, "tests/pacsuelo.xpm", &width, &height);

    // Verificar si la imagen se cargó correctamente
    if (!img_ptr)
    {
        // Manejo de errores en caso de no cargar la imagen
        return 1;
    }

    // Dibujar la imagen en la ventana en la posición (x, y) horizontal/vertical.
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 10, 10);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 10, 20);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 10, 30);
	img_data = mlx_get_data_addr(img_ptr, &width, &height, &endian);
	int i = 0;
	while (i < 5)
	{
		
	}
	// Iniciar el bucle principal
    mlx_loop(mlx_ptr);
}