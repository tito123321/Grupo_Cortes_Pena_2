#include <stdio.h>
#include <string.h>

int main() {
    char cad[50];
    int i = 0, j, k;

    printf("Ingrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    while (cad[i] != '\n') {
        if (cad[i] >= '0' && cad[i] <= '9') {
            j = cad[i] - '0';
            i++;
            while (cad[i] >= 'a' && cad[i] <= 'z') {
                for (k = 0; k < j; k++) {
                    printf("%c", cad[i]);
                }
                i++;
            }
        } else {
            i++;
        }
    }

    printf("\n");

    return 0;
}
