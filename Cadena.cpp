#include <stdio.h>

int main() {
    char cad[50], car;
    int i, contador = 0;

    printf("Introduce una cadena de caracteres (max 50): ");
    fgets(cad, 50, stdin);

    printf("Introduce un carácter: ");
    scanf(" %c", &car);

    for(i = 0; cad[i] != '\0'; i++) {
        if(cad[i] == car) {
            contador++;
        }
    }

    printf("El carácter '%c' se encuentra %d veces en la cadena.\n", car, contador);

    return 0;
}
