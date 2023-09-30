#include <stdio.h>
#include <pigpio.h>

#define UART_DEVICE const_cast<char*>("/dev/ttyACM0") // Conversión explícita a char*

#define DATA_BUFFER_SIZE 32000

int main() {
  if (gpioInitialise() < 0) {
    printf("Error al inicializar pigpio\n");
    return 1;
  }

  int serialPort = serOpen(UART_DEVICE, 9600, 0); // Abre la comunicación UART

  if (serialPort < 0) {
    printf("Error al abrir el puerto serie\n");
    return 1;
  }

  FILE *file = fopen("datos.txt", "w"); // Abre el archivo para escribir

  if (file == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }

  char dataBuffer[DATA_BUFFER_SIZE];

  for (int i = 0; i < DATA_BUFFER_SIZE; i++) {
    while (serDataAvailable(serialPort) == 0) {
      // Espera a que haya datos disponibles en el puerto serie
    }

    dataBuffer[i] = serReadByte(serialPort); // Lee un byte del puerto serie
    fprintf(file, "%c", dataBuffer[i]); // Escribe los datos en el archivo

    printf("Dato enviado correctamente a datos.txt\n"); // Agrega este mensaje
  }

  fclose(file); // Cierra el archivo
  serClose(serialPort); // Cierra el puerto serie

  gpioTerminate(); // Termina la librería pigpio

  return 0;
}

