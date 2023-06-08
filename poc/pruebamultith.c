#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
// Función del primer hilo para imprimir del 0 al 20
void* printNumbers1(void* arg) {
    for (int i = 1; i <= 20; i++) {
		if (i % 2 != 0) {
			printf("Primero %d \n", i);
		}
		sleep(1);
    }
    printf("\n");
    
    pthread_exit(NULL);
}

// Función del segundo hilo para imprimir del 0 al 20
void* printNumbers2(void* arg) {
    for (int i = 1; i <= 20; i++) {
		if (i % 2 == 0) {
			printf("Segundo %d \n", i);
		}
		sleep(1);
	}
    printf("\n");
    
    pthread_exit(NULL);
}
void declaracion_hilos(){
    // Declarar los identificadores de los hilos
    pthread_t thread1, thread2, thread3;

    // Crear el primer hilo
    if (pthread_create(&thread1, NULL, printNumbers1, NULL) != 0) {
        fprintf(stderr, "Error al crear el primer hilo.\n");
        exit(0);
    }

    // Crear el segundo hilo
    if (pthread_create(&thread2, NULL, printNumbers2, NULL) != 0) {
        fprintf(stderr, "Error al crear el segundo hilo.\n");
        exit(0);
    }
	if (pthread_create(&thread3, NULL, printmierda))
    // Esperar a que los hilos terminen
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}

int main() {
	declaracion_hilos();

    return 0;
}
