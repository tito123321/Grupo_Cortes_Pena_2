#include <iostream>
#include <string>

int main() {
    std::string entrada;
    std::string salida = "";

    // Solicitar al usuario la cadena de entrada
    std::cout << "Ingresa una cadena de caracteres (números y letras): ";
    std::cin >> entrada;

    for (int i = 0; i < entrada.length(); i++) {
        if (std::isdigit(entrada[i])) {
            int repeticiones = entrada[i] - '0'; // Convertir el carácter numérico a un entero
            i++; // Avanzar al siguiente carácter (letra)
            while (repeticiones > 0) {
                salida += entrada[i];
                repeticiones--;
            }
        } else {
            salida += entrada[i];
        }
    }

    // Imprimir la cadena de salida
    std::cout << "Resultado: " << salida << std::endl;

    return 0;
}
