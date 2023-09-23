#include <stdio.h>
#include <stdlib.h>
int main() {
    char cad[50];
    int i, j;
    printf("Introduce una cadena de caracteres formada por números y letras, en ese orden: ");
    scanf("%s", cad);
    i = 0;
    while (cad[i] != '\0') {
        if (cad[i] >= '0' && cad[i] <= '9') {
            j = 0;
            while (j < cad[i] - '0') {
                printf("%c", cad[i + 1]);
                j++;
            }
            i++;
        }
        i++;
    }
    printf("\n");
    return 0;
}
