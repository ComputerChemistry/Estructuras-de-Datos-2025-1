/**
* \file Vector.hpp
* Contiene la definición de una clase que representa un vector algebraico.
* \author: Carlos Eduardo Moreno Vargas
* \date: 24/01/2025
*/

#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>

#define MAX_DIM 10 // Definición de la dimensión máxima del vector

/**
* \class Vector
* \brief Clase para el manejo de vectores algebraicos
*
* Esta clase permite realizar operaciones algebraicas con vectores, tales como
* suma, resta, multiplicación por un escalar, y cálculo de la magnitud, entre otras.
*/
class Vector {
    /** 
     * \brief Operador de multiplicación de escalar por vector
     * \param escalar Escalar por el que se multiplica un vector
     * \param v Vector a multiplicar
     * \return Vector resultante de la multiplicación
     */
    friend Vector operator*(double escalar, const Vector &v);

    /** 
     * \brief Sobrecarga del operador de salida (ostream) para impresión del vector
     * \param salida Flujo de salida
     * \param v Vector a imprimir
     * \return Flujo de salida con el vector impreso
     */
    friend std::ostream & operator<<(std::ostream &salida, const Vector &v);

    /** 
     * \brief Sobrecarga del operador de entrada (istream) para leer componentes del vector
     * \param entrada Flujo de entrada
     * \param v Vector que recibirá los valores
     * \return Flujo de entrada con los valores leídos
     */
    friend std::istream & operator>>(std::istream &entrada, Vector &v);

public:
    /** 
     * \brief Constructor que inicializa un vector con dimensión y valor
     * \param dimension Número de componentes del vector
     * \param valor Valor inicial para las componentes del vector
     */
    explicit Vector(int dimension = 1, double valor = 0);

    /** 
     * \brief Constructor de copia para crear un vector a partir de otro
     * \param v Vector a copiar
     */
    Vector(const Vector & v); 
  
    /** 
     * \brief Destructor para liberar memoria dinámica
     */
    ~Vector();

    /** 
     * \brief Operador de asignación para asignar un vector a otro
     * \param v Vector a asignar
     * \return Referencia al vector asignado
     */
    Vector& operator=(const Vector &v); 

    /** 
     * \brief Obtener la dimensión del vector
     * \return Dimensión del vector
     */
    int ObtenerDim() const;
  
    double ObtenerComponente(int i) const; 

    void ModificarComponente(int i, double valor) const;

    /** 
     * \brief Imprimir el vector en formato (x1, x2, ..., xn)
     */
    void Imprimir() const;

    /** 
     * \brief Capturar los valores de las componentes del vector desde la entrada estándar
     */
    void Capturar();

    /** 
     * \brief Operador de suma de vectores
     * \param v Vector a sumar
     * \return Vector resultante de la suma
     */
    Vector operator+(const Vector v) const;

    /** 
     * \brief Operador de resta de vectores
     * \param v Vector a restar
     * \return Vector resultante de la resta
     */
    Vector operator-(const Vector v) const;

    /** 
     * \brief Operador de producto punto (multiplicación de vectores)
     * \param v Vector con el que se realiza el producto punto
     * \return Resultado del producto punto
     */
    double operator*(const Vector v) const;

    /** 
     * \brief Operador de multiplicación por escalar
     * \param escalar Valor por el cual se multiplica el vector
     * \return Vector resultante de la multiplicación
     */
    Vector operator*(const double escalar) const;

    /** 
     * \brief Calcular la magnitud (norma) del vector
     * \return Magnitud del vector
     */
    double Magnitud() const;

    /** 
     * \brief Operador de acceso a las componentes del vector (lectura)
     * \param i Índice de la componente a acceder
     * \return Componente en el índice i
     */
    double operator[](int i) const;

    /** 
     * \brief Operador de acceso a las componentes del vector (escritura)
     * \param i Índice de la componente a modificar
     * \return Referencia a la componente en el índice i
     */
    double & operator[](int i);

private:
    int dim;                          ///< Dimensión del vector
    //double componente[MAX_DIM];        ///< Arreglo para almacenar las componentes del vector
    double* componente;        ///< Arreglo para almacenar las componentes del vector
    /** 
     * \brief Establecer la dimensión del vector, validando su valor
     * \param dimension Nueva dimensión del vector
     * \throw Excepción si la dimensión es inválida
     */
    void EstablecerDim(int dimension);
};

#endif // VECTOR_HPP_INCLUDED
