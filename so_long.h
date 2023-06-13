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
	int width;
	int height;
	int exit_x;
	int exit_y;
	int moves;
	int coins_gained;
	int endian;
	clock_t env_animation;//parte bonus
}map;

typedef struct{
	void *ptr;
	int width;
	int height;
	void *img;
	int x;
	int	y;
	int moves;
	int endian;
	int stepanimation;
}entity;

typedef struct {
	map *map;
	entity *player;
	entity *ditto;
	entity *snorlax;
	// Agrega aquí todas las variables que necesitas
} in;
/*FUNCIONES PRINTF*/
int	ft_printf(const char *fmt, ...);
/*FUNCIONES LIBFT*/
void ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
/*FUNCION GET_NEXT_LINE*/
/*char *get_next_line(int fd);*/
/*FUNCIONES DE MAPA*/
int process_map_file(in *fw);
void check_argc(int argc);
int check_file_extension(char *filename, char *extension);
int line_counter(int fd);
int process_line(int fd, in *fw);
int check_line(char *buffer, int *i, in *fw);
int map_validator(char *buffer, in *fw);
int first_line_analyzer(char *buffer, in *fw);
int body_line_analyzer(char *buffer, in *fw);
int last_line_analyzer(char *buffer, in *fw);
int search_items(char item, in *fw);
int path_finder(in *fw);
int dfs(int row, int col, int **visited, in *fw);
/*FUNCIONES DE GESTION DE GRÁFICOS*/
int mlx_process(in *fw);
void put_imgs(in *fw);
void put_item(in *fw, int y, int x);
int key_hook(int keycode, in *fw);
void free_mapstruct(in *fw);
int loop_hook(in *fw);// PROBANDO
void wall_animation(in *fw);
void coin_animation(in *fw);
void check_coins(in *fw);
void draw_image(in *fw, void *img_ptr, int start_x, int start_y);
/*FUNCIONES DE GESTION DE MOVIMIENTOS*/
int check_e(in *fw);
/*FUNCIONES DE GESTIÓN DE ERRORES*/
void perror(const char *s);
char *strerror(int errnum);
/*EXATRON*/
int get_pixel_color(void *img_ptr, int x, int y);
void handlemove(in *fw, entity *entity, int coordx, int coordy);
int handlekeys(in *fw, char key);
int check_move(in *fw, int coordX, int coordY);
char *getdirectionimage1(int coordx, int coordy);
char *getdirectionimage2(int coordx, int coordy);
float getsumax(int coordx, float lx);
float getsumay(int coordy, float lx);
char *getdirectionstatic(int coordx, int coordy);
int drawcharacter(in *fw, entity *entity, int coordx, int coordy);
void initplayer(in *fw, int coordx, int coordy);
char convertirKeyCodeALetra(int keycode);
int timer(clock_t inicio, double tiempo_deseado);
int hasEnoughTimeElapsed(void);
#endif