#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>
#include <stdexcept>

class Matriz {
private:
    unsigned int filas; // Número de filas
    unsigned int columnas; // Número de columnas
    double** datos; // Puntero a un arreglo dinámico 2D

public:
    // Constructor con parámetros por defecto
    Matriz(unsigned int f = 1, unsigned int c = 1);
    
    // Destructor
    ~Matriz();
    
    // Constructor de copia
    Matriz(const Matriz& otra);
    
    // Operador de asignación
    Matriz& operator=(const Matriz& otra);
    
    // Sobrecargas de operadores para operaciones de matrices
    Matriz operator+(const Matriz& otra) const;
    Matriz operator-(const Matriz& otra) const;
    Matriz operator*(const Matriz& otra) const;
    Matriz operator*(double escalar) const;
    
    // Método para calcular la transpuesta de la matriz
    Matriz transpuesta() const;
    
    // Método para calcular la inversa de una matriz cuadrada
    Matriz inversa() const;
    
   void MatrizDimension(unsigned int nuevaFila, unsigned int nuevaColumna);

    // Método para redimensionar la matriz
    void redimensionar(unsigned int nuevasFilas, unsigned int nuevasColumnas);
    
    // Funciones amigas para entrada y salida
    friend std::ostream& operator<<(std::ostream& os, const Matriz& matriz);
    friend std::istream& operator>>(std::istream& is, Matriz& matriz);
};

// Operador no miembro para multiplicación escalar
Matriz operator*(double escalar, const Matriz& matriz);

#endif // MATRIZ_HPP_INCLUDED

