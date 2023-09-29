#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_HORAS 24

// Función para generar temperaturas aleatorias
double generarTemperatura() {
    return (rand() % 30) - 5 + (rand() % 100) / 100.0; // Temperaturas entre -5°C y 25°C
}

// Función para encontrar la temperatura promedio
double encontrarPromedio(double temperaturas[]) {
    double suma = 0;
    for (int i = 0; i < NUM_HORAS; i++) {
        suma += temperaturas[i];
    }
    return suma / NUM_HORAS;
}

// Función para encontrar la temperatura máxima y su hora
void encontrarMaximo(double temperaturas[], int *horaMax, double *tempMax) {
    *tempMax = temperaturas[0];
    *horaMax = 0;
    for (int i = 1; i < NUM_HORAS; i++) {
        if (temperaturas[i] > *tempMax) {
            *tempMax = temperaturas[i];
            *horaMax = i;
        }
    }
}

// Función para encontrar la temperatura mínima y su hora
void encontrarMinimo(double temperaturas[], int *horaMin, double *tempMin) {
    *tempMin = temperaturas[0];
    *horaMin = 0;
    for (int i = 1; i < NUM_HORAS; i++) {
        if (temperaturas[i] < *tempMin) {
            *tempMin = temperaturas[i];
            *horaMin = i;
        }
    }
}

int main() {
    srand(time(NULL)); // Inicializar la semilla para generación de números aleatorios

    double temperaturas[NUM_HORAS];
    int horaMax, horaMin;
    double tempMax, tempMin;

    // Generar temperaturas aleatorias para 24 horas
    for (int i = 0; i < NUM_HORAS; i++) {
        temperaturas[i] = generarTemperatura();
    }

    // Encontrar la temperatura promedio
    double promedio = encontrarPromedio(temperaturas);

    // Encontrar la temperatura máxima y su hora
    encontrarMaximo(temperaturas, &horaMax, &tempMax);

    // Encontrar la temperatura mínima y su hora
    encontrarMinimo(temperaturas, &horaMin, &tempMin);

    // Imprimir resultados
    printf("Temperatura promedio del día: %.2f°C\n", promedio);
    printf("Temperatura máxima: %.2f°C a las %d:00 horas\n", tempMax, horaMax);
    printf("Temperatura mínima: %.2f°C a las %d:00 horas\n", tempMin, horaMin);

    return 0;
}

