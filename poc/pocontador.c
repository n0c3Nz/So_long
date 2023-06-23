#include <stdio.h>
#include <stdlib.h>

char* agregarCeros(int numero, char* resultado) {
    if (numero < 0 || numero > 999) {
        printf("El número está fuera del rango válido (0-999).\n");
        resultado[0] = '\0';  // Establecer el resultado como una cadena vacía
        return resultado;
    }

    if (numero < 10) {
        sprintf(resultado, "00%d", numero);
    } else if (numero < 100) {
        sprintf(resultado, "0%d", numero);
    } else {
        sprintf(resultado, "%d", numero);
    }

    return resultado;
}

int main() {
    int numero;
    char resultado[4];

    printf("Ingrese un número (0-999): ");
    scanf("%d", &numero);

    char* valor = agregarCeros(numero, resultado);

    if (valor[0] != '\0') {
        printf("Resultado: %s\n", valor);
    }

    return 0;
}
