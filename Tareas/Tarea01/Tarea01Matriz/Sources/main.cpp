/*
Autores: Carlos Eduardo Moreno



*/

#include <iostream>
#include "../Headers/Matriz.hpp"

int main() {
    try {
       
          unsigned int filas1, columnas1, filas2, columnas2;


	std::cout << "Ingresa las dimensiones de la Matriz 1:" << std::endl;
	std::cout << "filas:\n";
	std::cin >> filas1;
	std::cout << "columnas:\n";
	std::cin >> columnas1;

	std::cout << "Ingresa las dimensiones de la Matriz 2:" << std::endl;
	std::cout << "filas:\n";
	std::cin >> filas2;
	std::cout << "columnas:\n";
	std::cin >> columnas2;


      // Crear una matriz 
        Matriz mat1(filas1, columnas2);
        std::cout << "Ingresa los valores para la primera matriz (mxn):" << std::endl;
        std::cin >> mat1;

        // Crear otra matriz
        Matriz mat2(filas2, columnas2);
        std::cout << "Ingresa los valores para la segunda matriz (mxn):" << std::endl;
        std::cin >> mat2;

        // Mostrar las matrices
        std::cout << "Matriz 1:" << std::endl << mat1;
        std::cout << "Matriz 2:" << std::endl << mat2;

        // Realizar operaciones
        Matriz suma = mat1 + mat2;
        Matriz diferencia = mat1 - mat2;
        Matriz producto = mat1 * mat2;
        Matriz transpuesta1 = mat1.transpuesta();
	Matriz transpuesta2 = mat2.transpuesta();

        // Mostrar resultados
        std::cout << "Suma:" << std::endl << suma;
        std::cout << "Diferencia:" << std::endl << diferencia;
        std::cout << "Producto:" << std::endl << producto;	
        std::cout << "Transpuesta de la Matriz 1:" << std::endl << transpuesta1;
	std::cout << "Transpuesta de la Matriz 2:" << std::endl << transpuesta2;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
