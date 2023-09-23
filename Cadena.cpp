#include <stdio.h>
#include <stdlib.h>

int main() {
    char cad[50];
    char car;
    int contador = 0;
    printf("Ingresa una cadena de caracteres (max 50 caracteres): ");
    scanf("%s", cad);

    printf("Ingresa un carácter a buscar: ");
    scanf(" %c", &car);

    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == car) {
            contador++;
        }
    }
    printf("El carácter '%c' se encuentra %d veces en la cadena.\n", car, contador);

    return 0;
}
