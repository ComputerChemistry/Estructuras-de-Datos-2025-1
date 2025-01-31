#include <iostream>
#include "Matriz.hpp"

int main() {
    try {
        // Crear una matriz de 2x2
      Matriz DimensionMatriz();

        Matriz mat1(redimensionar);
        std::cout << "Ingresa los valores para la primera matriz (2x2):" << std::endl;
        std::cin >> mat1;

        // Crear otra matriz de 2x2
        Matriz mat2(redimensionar);
        std::cout << "Ingresa los valores para la segunda matriz (2x2):" << std::endl;
        std::cin >> mat2;

        // Mostrar las matrices
        std::cout << "Matriz 1:" << std::endl << mat1;
        std::cout << "Matriz 2:" << std::endl << mat2;

        // Realizar operaciones
        Matriz suma = mat1 + mat2;
        Matriz diferencia = mat1 - mat2;
        Matriz producto = mat1 * mat2;
        Matriz transpuesta = mat1.transpuesta();

        // Mostrar resultados
        std::cout << "Suma:" << std::endl << suma;
        std::cout << "Diferencia:" << std::endl << diferencia;
        std::cout << "Producto:" << std::endl << producto;
        std::cout << "Transpuesta de la Matriz 1:" << std::endl << transpuesta;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
