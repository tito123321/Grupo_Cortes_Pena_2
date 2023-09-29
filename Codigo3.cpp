#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>

#define NUMERO_DE_NUMEROS 256

int numerosAleatorios[NUMERO_DE_NUMEROS];

#define PIN_LED 17

void inicializarPigpio() {
    if (gpioInitialise() < 0) {
        fprintf(stderr, "Error al inicializar pigpio\n");
        exit(1);
    }
}

void configurarLEDs() {
    gpioSetMode(PIN_LED, PI_OUTPUT);
}

void imprimirEnBinario(int numero) {
    char binario[9];
    for (int i = 0; i < 8; i++) {
        binario[7 - i] = (numero & (1 << i)) ? '1' : '0';
    }
    binario[8] = '\0';
    printf("%s\n", binario);
}

void controlarLEDs(int numero) {
    for (int i = 0; i < 8; i++) {
        int bit = (numero >> i) & 1;
        gpioWrite(PIN_LED, bit);
        gpioDelay(100); // Espera 500 ms
    }
}

int main() {
    inicializarPigpio();
    configurarLEDs();

    for (int i = 0; i < NUMERO_DE_NUMEROS; i++) {
        numerosAleatorios[i] = rand() % 256;
        imprimirEnBinario(numerosAleatorios[i]);
        controlarLEDs(numerosAleatorios[i]);
    }

    gpioTerminate();
    return 0;
}

