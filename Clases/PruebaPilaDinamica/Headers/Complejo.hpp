/**
 * @file Complejo.hpp
 * \author: Carlos Eduardo Moreno Vargas, Joan Antonio Lazaro Silva
 * \date: 30/01/2025
 * @brief Definición de la clase Matriz Complejo.
 */

#ifndef COMPLEJO_HPP_INCLUDED
#define COMPLEJO_HPP_INCLUDED

#include <iostream>

/** 
 * \class Complejo
 * \brief Representa un número complejo con parte real e imaginaria.
 * 
 * La clase proporciona operaciones básicas como suma y métodos para obtener los valores reales e imaginarios.
 */
class Complejo {
private:
    double real;      ///< Parte real del número complejo.
    double imaginario; ///< Parte imaginaria del número complejo.

public:
    /** 
     * \brief Constructor de la clase Complejo.
     * 
     * \param r Valor inicial de la parte real (por defecto 0).
     * \param i Valor inicial de la parte imaginaria (por defecto 0).
     */
    Complejo(double r = 0, double i = 0);
    
    /** 
     * \brief Obtiene la parte real del número complejo.
     * 
     * \return El valor de la parte real.
     */
    double ObtenerReal() const;
    
    /** 
     * \brief Obtiene la parte imaginaria del número complejo.
     * 
     * \return El valor de la parte imaginaria.
     */
    double ObtenerImaginario() const;
    
    /** 
     * \brief Sobrecarga del operador suma para números complejos.
     * 
     * \param otro Número complejo a sumar.
     * \return Un nuevo número complejo que representa la suma.
     */
    Complejo operator+(const Complejo& otro) const;
    
    /** 
     * \brief Imprime el número complejo en formato estándar.
     */
    void Imprimir() const;
    
    /** 
     * \brief Sobrecarga del operador de salida para imprimir un número complejo.
     * 
     * \param out Flujo de salida.
     * \param c Número complejo a imprimir.
     * \return Flujo de salida modificado.
     */
    friend std::ostream& operator<<(std::ostream& out, const Complejo& c);
};

#endif // COMPLEJO_HPP_INCLUDED
