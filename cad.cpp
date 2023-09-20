#include <iostream>
#include <string>

int main() {
    std::string cad;
    char car;
    int contador = 0;

    // Solicitar al usuario la cadena y el carácter
    std::cout << "Ingresa una cadena de caracteres: ";
    std::cin >> cad;
    std::cout << "Ingresa un carácter: ";
    std::cin >> car;

    // Recorrer la cadena para contar la ocurrencia del carácter
    for (char c : cad) {
        if (c == car) {
            contador++;
        }
    }

    // Mostrar el resultado
    std::cout << "El carácter '" << car << "' aparece " << contador << " veces en la cadena." << std::endl;

    return 0;
}


