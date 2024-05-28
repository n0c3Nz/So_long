#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef struct {
char *frase[50];
}fras;
int main(void){
	fras	a;
	int count = 50;
	for (size_t i = 0; i < count; i++)
	{
		a.frase[i] = "pipo";
		printf("[%i] %s\t", i, a.frase[i]);
	}
	printf("\nEl array número 39 dice %s", a.frase[38]);
	printf("\nEl array número 50 dice %s y tiene %i carácteres", a.frase[49], strlen(a.frase[49]));
	printf("\nEl array número 51 dice %s", a.frase[50]);
	return(0);
}