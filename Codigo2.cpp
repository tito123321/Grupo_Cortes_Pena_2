#include <stdio.h>
int main() {
    int s;
    float fa;
    printf("Introduzca el número de sonidos emitidos por la chicharra en un minuto: ");
    scanf("%d", &s);
    fa = s / 4 + 40;
    printf("La temperatura en grados Fahrenheit es: %.2f\n", fa);
    return 0;
}
