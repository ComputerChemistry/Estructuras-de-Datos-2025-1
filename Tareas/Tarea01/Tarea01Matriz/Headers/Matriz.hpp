/**
 * @file Matriz.hpp
 * \author: Carlos Eduardo Moreno Vargas, Joan Antonio Lazaro Silva
 * \date: 30/01/2025
 * @brief Definición de la clase Matriz para operaciones con matrices.
 */

#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>
#include <stdexcept>

/**
 * @class Matriz
 * @brief Clase para la manipulación de matrices dinámicas.
 */
class Matriz {
private:
    unsigned int filas; ///< Número de filas de la matriz.
    unsigned int columnas; ///< Número de columnas de la matriz.
    double** datos; ///< Puntero a un arreglo dinámico 2D que almacena los datos de la matriz.

public:
    /**
     * @brief Constructor de la clase Matriz.
     * @param f Número de filas (por defecto 1).
     * @param c Número de columnas (por defecto 1).
     */
    Matriz(unsigned int f = 1, unsigned int c = 1);

    /**
     * @brief Destructor de la clase Matriz.
     */
    ~Matriz();

    /**
     * @brief Constructor de copia.
     * @param otra Matriz a copiar.
     */
    Matriz(const Matriz& otra);

    /**
     * @brief Operador de asignación.
     * @param otra Matriz a asignar.
     * @return Referencia a la matriz actual modificada.
     */
    Matriz& operator=(const Matriz& otra);

    /**
     * @brief Sobrecarga del operador de suma para matrices.
     * @param otra Matriz a sumar.
     * @return Nueva matriz resultante de la suma.
     * @throws std::invalid_argument si las dimensiones no coinciden.
     */
    Matriz operator+(const Matriz& otra) const;

    /**
     * @brief Sobrecarga del operador de resta para matrices.
     * @param otra Matriz a restar.
     * @return Nueva matriz resultante de la resta.
     * @throws std::invalid_argument si las dimensiones no coinciden.
     */
    Matriz operator-(const Matriz& otra) const;

    /**
     * @brief Sobrecarga del operador de multiplicación de matrices.
     * @param otra Matriz a multiplicar.
     * @return Nueva matriz resultante de la multiplicación.
     * @throws std::invalid_argument si el número de columnas de la primera matriz no coincide con el número de filas de la segunda.
     */
    Matriz operator*(const Matriz& otra) const;

    /**
     * @brief Sobrecarga del operador de multiplicación por escalar.
     * @param escalar Valor escalar a multiplicar.
     * @return Nueva matriz escalada.
     */
    Matriz operator*(double escalar) const;

    /**
     * @brief Calcula la transpuesta de la matriz.
     * @return Nueva matriz transpuesta.
     */
    Matriz transpuesta() const;

    /**
     * @brief Calcula la inversa de una matriz cuadrada.
     * @return Nueva matriz inversa.
     * @throws std::runtime_error si la matriz no es cuadrada o es singular.
     */
    Matriz inversa() const;

    /**
     * @brief Redimensiona la matriz a nuevas dimensiones.
     * @param nuevasFilas Nuevo número de filas.
     * @param nuevasColumnas Nuevo número de columnas.
     */
    void redimensionar(unsigned int nuevasFilas, unsigned int nuevasColumnas);

    /**
     * @brief Sobrecarga del operador de salida para imprimir la matriz.
     * @param os Flujo de salida.
     * @param matriz Matriz a imprimir.
     * @return Flujo de salida modificado.
     */
    friend std::ostream& operator<<(std::ostream& os, const Matriz& matriz);

    /**
     * @brief Sobrecarga del operador de entrada para leer una matriz.
     * @param is Flujo de entrada.
     * @param matriz Matriz a leer.
     * @return Flujo de entrada modificado.
     */
    friend std::istream& operator>>(std::istream& is, Matriz& matriz);
};

/**
 * @brief Sobrecarga del operador de multiplicación escalar por la izquierda.
 * @param escalar Valor escalar a multiplicar.
 * @param matriz Matriz a multiplicar.
 * @return Nueva matriz escalada.
 */
Matriz operator*(double escalar, const Matriz& matriz);

#endif // MATRIZ_HPP_INCLUDED
