#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include "./src/libft/libft.h"
//#include "./src/get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>//Utilizada para la parte bonus, ANIMACIONES.
#include <math.h>//Utilizada para el algoritmo a Star.
#include <X11/Xlib.h>//Utilizada para la gestion del multihilo.
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
	int enemies;
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
	int is_w_pressed;
}map;

typedef struct{
	void *ptr;
	int width;
	int height;
	void *img;
	int x;
	int	y;
	float xT;
	float yT;
	int moves;
	int endian;
	int stepanimation;
	char value;
	int is_wall;
	clock_t walktimer;
	bool iswalking;
}entity;
typedef struct{
	void *zero_ptr;
	void *one_ptr;
	void *two_ptr;
	void *three_ptr;
	void *four_ptr;
	void *five_ptr;
	void *six_ptr;
	void *seven_ptr;
	void *eight_ptr;
	void *nine_ptr;
	void *move_ptr;
	int width;
	int height;
	int widthmove;
	int heightmove;
}counter;

typedef struct {
	map *map;
	entity *player;
	entity *ditto;
	entity *snorlax;
	counter *count;
	// Agrega aquí todas las variables que necesitas
} in;

typedef struct {
	in *tempfw;
	entity *tempentity;
	int coordx;
	int coordy;
} tempcajon;

/*FUNCIONES PRINTF*/
int	ft_printf(const char *fmt, ...);
/*FUNCIONES LIBFT*/
void ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
/*FUNCION GET_NEXT_LINE*/
/*char *get_next_line(int fd);*/
/*FUNCIONES DE MAPA*/
void check_argc(int argc);
int check_file_extension(char *filename, char *extension);
int process_map_file(in *fw);
int line_counter(int fd);
int process_line(int fd, in *fw);
int check_line(char *buffer, int *i, in *fw);
int map_validator(char *buffer, in *fw);
int first_line_analyzer(char *buffer, in *fw);
int body_line_analyzer(char *buffer, in *fw);
void search_entitys(in *fw, char letter, int e, int num);
int last_line_analyzer(char *buffer, in *fw);
int search_items(char item, in *fw);
int path_finder(in *fw);
int dfs(int row, int col, int **visited, in *fw);
/*FUNCIONES DE GESTION DE GRÁFICOS*/
int mlx_process(in *fw);
void put_imgs(in *fw);
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
char *getdirectionimage1(entity *entity, int coordx, int coordy);
char *getdirectionimage2(entity *entity, int coordx, int coordy);
float getsumax(int coordx, float lx);
float getsumay(int coordy, float lx);
char *getdirectionstatic(entity *entity, int coordx, int coordy);
int drawcharacter(in *fw, entity *entity, int coordx, int coordy);
void initplayer(in *fw, entity *entity, int coordx, int coordy);
char convertirKeyCodeALetra(int keycode);
int timer(clock_t inicio, double tiempo_deseado);
int hasEnoughTimeElapsed(void);
/*BUSQUEDA A* */
int moveEnemyTowardsPlayer(in *fw, entity *enemy, entity *player);
char* put_values(char *cadena, entity *entity);
char get_low(char letter);
int getRandomBoolean(void);
void *bucle_asincrono(void* arg);
//prueba
int key_release(int keycode, in *fw);
bool iswall(in *fw, entity *enemy, int posx, int posy);
int is_entity(in *fw, int y, int x, int first_time);
void put_item_to_buffer(in *fw, int *buffer_data, int y, int x);
//int put_counter(in *fw);
int agregarCeros(in *fw);
void draw_counter(in *fw, void	*img_ptr, int	start_x, int	start_y);
void put_number(in *fw, int number, int position);
#endif