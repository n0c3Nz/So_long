#include <stdio.h>
#include <string.h>
typedef struct map {
    char *line[10];
} map;
int funcion(map *my_map);
void	asignar(map *my_map);
int main(){
    map my_map;
	asignar(&my_map);
	funcion(&my_map);
	return (0);
}
void	asignar(map *my_map){
    char *colors= "amarillo";
    int i = 0;
    while (i < 10){
		my_map->line[i] = colors;
        i++;
	}
}
int funcion(map *my_map){
	int i;
	i = 0;
    while (i < 10) {
        printf("%s\n", my_map->line[i]);
        i++;
    }
	return (0);
}