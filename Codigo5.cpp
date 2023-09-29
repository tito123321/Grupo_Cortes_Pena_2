#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int validarCalificacion(int calificacion) {
    if (calificacion >= 10 && calificacion <= 70) {
        return 1; // Calificación válida
    } else {
        return 0; // Calificación invalida
    }
}

int main() {
    int ALU[N];
    float media_aritmetica, varianza_, desviacion_estandar_;
    int moda;

    printf("Introduzca las calificaciones de los exámenes de los alumnos:\n");
    for (int i = 0; i < N; i++) {
        int calificacion;
        scanf("%d", &calificacion);
        if (validarCalificacion(calificacion)) {
            ALU[i] = calificacion;
        } else {
            printf("Calificación incorrecta. Debe estar en el rango de 10 a 70.\n");
            i--; // Volver a pedir la calificación
        }
    }

    media_aritmetica = 0;
    for (int i = 0; i < N; i++) {
        media_aritmetica += ALU[i];
    }
    media_aritmetica /= N;

    varianza_ = 0;
    for (int i = 0; i < N; i++) {
        varianza_ += (ALU[i] - media_aritmetica) * (ALU[i] - media_aritmetica);
    }
    varianza_ /= N;

    desviacion_estandar_ = sqrt(varianza_);

    int maxCount = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (ALU[j] == ALU[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            moda = ALU[i];
        }
    }

    printf("La media aritmética es: %.2f\n", media_aritmetica);
    printf("La varianza es: %.2f\n", varianza_);
    printf("La desviación estándar es: %.2f\n", desviacion_estandar_);
    if (maxCount > 1) {
        printf("La moda es: %d\n", moda);
    } else {
        printf("No hay una moda clara en los datos.\n");
    }

    return 0;
}

