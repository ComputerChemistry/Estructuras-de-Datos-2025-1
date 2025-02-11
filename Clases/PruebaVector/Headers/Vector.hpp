
/**
* \file Vector.hpp
* Contiene la definicion de una clase que representa un vector algebraico 
* \author: Carlos Eduardo Moreno Vargas
* \date: 24/01/2025
*/
#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>

#define MAX_DIM 10
/**
* Vector es una clase para el manejo de vectores algebraicos
*/

class Vector{
/** \brief Operador de Multiplicacion de escalar por vectores 
*   \param escalar  Escalar por el que se muliplica un vector 
*   \param   v  Vector a multiplicacion
*   \return Vector resultante  de la multiplicacion
*/
    friend Vector operator*(double escalar, const Vector v);
    friend std::ostream & operator<<(std::ostream &salida, const Vector v);
    friend std::istream & operator>>(std::istream &entrada, Vector &v);
public:
    //Vector();
    explicit Vector(int dimension = 1, double valor = 0);
    Vector(const Vector & v); 
 
    ~Vector();
    Vector & operator=(const Vector v); 

    //Vector(int dimension, double valor);

    int ObtenerDim() const;

    void Imprimir() const;
    void Capturar();

    Vector operator+(const Vector v) const;
    Vector operator-(const Vector v) const;
    double operator*(const Vector v) const;
    Vector operator*(const double escalar) const;
    double Magnitud() const;

    double operator[](int i) const;
    double & operator[](int i);

private:
    int dim;
    double componente[MAX_DIM];
    // Métodos de utilería
    void EstablecerDim(int dimension);

};



#endif // VECTOR_HPP_INCLUDED
