#include <stdio.h>
#include <string.h>
typedef struct{
  char *nombre;
  int edad;
  char *direccion;
}Persona;
int registrador_edad(Persona *p){
	p->edad = 30;
	return (0);
}
char *registrador_resto(Persona persona1){
	persona1.nombre = "Juan Perez";
	printf("%d\n", persona1.edad);
	return(persona1.nombre);
}
void suma(int *i)
{
	*i = *i + 1;
}
int	main(){
	int i;
	i = 0;
	printf("\nsin sumar %d\n", i);
	suma(&i);
	printf("\nsumado %d\n", i);
	Persona persona1;
	registrador_edad(&persona1);
	registrador_resto(persona1);
	printf("La persona %s tiene %i años y vive en %s", persona1.nombre, persona1.edad, persona1.direccion);
	return 0;
}