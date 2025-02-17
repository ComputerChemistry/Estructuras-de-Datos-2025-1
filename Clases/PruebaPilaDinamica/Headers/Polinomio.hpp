/**
 * @file Polinomio.hpp
 * \author: Carlos Eduardo Moreno Vargas, Joan Antonio Lazaro Silva
 * \date: 30/01/2025
 * @brief Definición de la clase Polinomios.
 */

#ifndef POLINOMIO_HPP_INCLUDED
#define POLINOMIO_HPP_INCLUDED

#include <vector>
#include <initializer_list>
#include <iostream>

/**
 * \class Polinomio
 * \brief Representa un polinomio con coeficientes almacenados en un vector.
 * 
 * Proporciona operaciones básicas como suma y métodos para imprimir.
 */
class Polinomio {
private:
    std::vector<double> coeficientes; ///< Vector que almacena los coeficientes del polinomio.

public:
    /**
     * \brief Constructor por defecto de la clase Polinomio.
     */
    Polinomio();
    
    /**
     * \brief Constructor que inicializa el polinomio con una lista de coeficientes.
     * \param coef Lista de coeficientes para inicializar el polinomio.
     */
    Polinomio(std::initializer_list<double> coef);
    
    /**
     * \brief Constructor que inicializa el polinomio con un vector de coeficientes.
     * \param coef Vector de coeficientes para inicializar el polinomio.
     */
    Polinomio(const std::vector<double>& coef);
    
    /**
     * \brief Imprime el polinomio en formato estándar.
     */
    void Imprimir() const;
    
    /**
     * \brief Sobrecarga del operador suma para polinomios.
     * \param otro Polinomio a sumar.
     * \return Nuevo polinomio resultante de la suma.
     */
    Polinomio operator+(const Polinomio& otro) const;
};

#endif // POLINOMIO_HPP_INCLUDED
