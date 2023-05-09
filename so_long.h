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
#define BUFFER_SIZE 200

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
	char *mapstruct[20];
	void *mlx;
	void *mlx_win;
	void *img_ptr;
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
/*FUNCIONES DE GESTION DE GRÁFICOS*/
int	mlx_process(map *c);
/*FUNCIONES DE GESTIÓN DE ERRORES*/
void perror(const char *s);
char *strerror(int errnum);

#endif
