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
#include <time.h>//Utilizada para la parte bonus, ANIMACIONES.
#define BUFFER_SIZE 5000
#define FRAMES_PER_CHANGE 60
#define BPP 64
// Variables globales
extern clock_t lastKeyPressTime;
extern const int MIN_DELAY;
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
	void *wall_sprite_1;
	void *wall_sprite_2;
	void *floor_ptr;
	void *exit_ptr;
	void *coin_ptr;
	void *coin_sprite_1;
	void *coin_sprite_2;
	void *coin_sprite_3;
	void *player_ptr;
	int width;
	int height;
	void *player_img;
	int player_x;
	int	player_y;
	int exit_x;
	int exit_y;
	int moves;
	int coins_gained;
	int endian;
	clock_t env_animation;//parte bonus
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
int dfs(int row, int col, int **visited, map *c);
/*FUNCIONES DE GESTION DE GRÁFICOS*/
int	mlx_process(map *c);
void put_imgs(map *c);
void put_item(map *c, int y, int x);
int key_hook(int keycode, map *c);
void free_mapstruct(map *c);
int loop_hook(map *c);// PROBANDO
void wall_animation(map *c);
void coin_animation(map *c);
void check_coins(map *c);
void draw_image(map *c, void *img_ptr, int start_x, int start_y);
/*FUNCIONES DE GESTION DE MOVIMIENTOS*/
int check_e(map *c);
/*FUNCIONES DE GESTIÓN DE ERRORES*/
void perror(const char *s);
char *strerror(int errnum);
/*EXATRON*/
int get_pixel_color(void *img_ptr, int x, int y);
void handlemove(map *c, int coordx, int coordy);
int handlekeys(map *c, char key);
char *getdirectionimage1(int coordx, int coordy);
char *getdirectionimage2(int coordx, int coordy);
float getsumax(int coordx, float lx);
float getsumay(int coordy, float lx);
char *getdirectionstatic(int coordx, int coordy);
int drawcharacter(int stepanimation, map *c, int coordx, int coordy);
void initplayer(map *c, int coordx, int coordy);
char convertirKeyCodeALetra(int keycode);
int timer(clock_t inicio, double tiempo_deseado);
int hasEnoughTimeElapsed(void);
#endif