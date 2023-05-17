#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include "./src/libft/libft.h"
//#include "./src/get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#define BUFFER_SIZE 5000
#define BPP 64
// STRUCTS
typedef struct{
	char *map_name;
	int	lines;
	int columns;
	int coins;
	int	exitp;
	int startp;
	int	zeros;
	int ones;
	char *mapstruct[BUFFER_SIZE];
	void *mlx;
	void *mlx_win;
	void *wall_ptr;
	void *floor_ptr;
	void *exit_ptr;
	void *coin_ptr;
	void *player_ptr;
	int width;
	int height;
	void *player_img;
	int player_x;
	int	player_y;
	int moves;
	int coins_gained;
	int endian;
}map;
/*FUNCIONES PRINTF*/
int	ft_printf(const char *fmt, ...);
/*FUNCIONES LIBFT*/
void ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
/*FUNCION GET_NEXT_LINE*/
/*char *get_next_line(int fd);*/
/*FUNCIONES DE MAPA*/
int process_map_file(int argc, char **argv, map *c);
void check_argc(int argc);
int check_file_extension(char *filename, char *extension);
int line_counter(int fd);
int process_line(int fd, map *c);
int check_line(char *buffer, int *i, map *c);
int map_validator(char *buffer, map *c);
int first_line_analyzer(char *buffer, map *c);
int body_line_analyzer(char *buffer, map *c);
int last_line_analyzer(char *buffer, map *c);
int search_items(char item, map *c);
int path_finder(map *c);
/*FUNCIONES DE GESTION DE GRÁFICOS*/
int	mlx_process(map *c);
void put_imgs(map *c);
void put_item(map *c, int y, int x);
int key_hook(int keycode, map *c);
/*FUNCIONES DE GESTION DE MOVIMIENTOS*/
int move_up(map *c);
int move_down(map *c);
int move_right(map *c);
int move_left(map *c);
int check_e(map *c);
/*FUNCIONES DE GESTIÓN DE ERRORES*/
void perror(const char *s);
char *strerror(int errnum);

#endif
