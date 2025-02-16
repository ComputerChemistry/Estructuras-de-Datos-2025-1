/**
 * @file Expresion.hpp
 * @brief Definición de la clase Expresion para manejar expresiones aritméticas en notación infija y posfija.
 * \author: Carlos Eduardo Moreno Vargas, Joan Antonio Lazaro Silva
 * \date: 15/02/2025
 * Esta clase proporciona métodos para validar, convertir y evaluar expresiones aritméticas
 * usando pilas. Las expresiones se pueden ingresar en notación infija y se convierten a notación
 * posfija para su evaluación.
 */

#ifndef EXPRESION_HPP
#define EXPRESION_HPP

#include <string>
#include <stack>
#include <cmath>
#include <stdexcept>
#include "../Headers/Pila.hpp" 

/**
 * @class Expresion
 * @brief Clase que representa una expresión aritmética.
 * 
 * La clase Expresion permite representar una expresión en notación infija, validarla,
 * convertirla a notación posfija (polaca inversa) y evaluarla.
 */
class Expresion {
private:
    std::string infija;  ///< Expresión en notación infija.
    std::string posfija; ///< Expresión en notación posfija.
    bool esValida; ///< Indicador de si la expresión es válida.

    /**
     * @brief Valida que la expresión sea correcta.
     * 
     * Realiza la validación de la expresión para asegurar que contiene solo caracteres
     * válidos (números, operadores, y símbolos de agrupación).
     * 
     * @param expresion La cadena de caracteres que representa la expresión infija.
     * @return true si la expresión es válida, false si no lo es.
     */
    bool ValidarExpresion(const std::string &expresion);

    /**
     * @brief Obtiene la precedencia de un operador.
     * 
     * Devuelve un valor que representa la precedencia de un operador aritmético.
     * Los operadores con mayor precedencia tienen un valor mayor.
     * 
     * @param op El operador cuyo valor de precedencia se desea obtener.
     * @return Un valor entero que representa la precedencia del operador.
     */
    int Precedencia(char op);

    /**
     * @brief Verifica si un carácter es un operador aritmético.
     * 
     * Comprueba si el carácter pasado como argumento es uno de los operadores
     * aritméticos válidos: +, -, *, /, ^.
     * 
     * @param c El carácter a verificar.
     * @return true si el carácter es un operador, false si no lo es.
     */
    bool EsOperador(char c);

    /**
     * @brief Verifica si una cadena es una función válida.
     * 
     * Verifica si la cadena pasada como argumento corresponde a una función
     * matemática válida como "sin", "cos", "log", etc.
     * 
     * @param s La cadena que representa una posible función.
     * @return true si la cadena es una función válida, false si no lo es.
     */
    bool EsFuncion(const std::string &s);

    /**
     * @brief Verifica si un carácter es un número.
     * 
     * Verifica si el carácter pasado es un número o un dígito.
     * 
     * @param c El carácter a verificar.
     * @return true si el carácter es un número, false si no lo es.
     */
    bool EsNumero(char c);

    /**
     * @brief Convierte una expresión infija a su equivalente en notación posfija.
     * 
     * Este método convierte una expresión aritmética escrita en notación infija
     * a notación posfija (polaca inversa) para facilitar su evaluación.
     * 
     * @param expresion La expresión infija a convertir.
     * @return La expresión en notación posfija.
     */
    std::string ConvertirAPosfija(const std::string &expresion);

    /**
     * @brief Evalúa una expresión en notación posfija.
     * 
     * Este método evalúa una expresión matemática escrita en notación posfija
     * y devuelve el resultado de la evaluación.
     * 
     * @param expresion La expresión en notación posfija a evaluar.
     * @return El resultado de la evaluación.
     */
    double EvaluarPosfija(const std::string &expresion);

public:
    /**
     * @brief Constructor por defecto.
     * 
     * Crea una instancia de la clase Expresion con una expresión vacía e inválida.
     */
    Expresion();

    /**
     * @brief Constructor que inicializa una expresión.
     * 
     * Crea una instancia de la clase Expresion con la expresión infija pasada como
     * argumento, valida la expresión y la convierte a notación posfija.
     * 
     * @param expresion La expresión infija que se desea inicializar.
     */
    Expresion(const std::string &expresion);

    /**
     * @brief Captura y valida una expresión infija.
     * 
     * Permite capturar una expresión infija desde un string, validarla y convertirla
     * a su equivalente en notación posfija.
     * 
     * @param expresion La expresión infija a capturar y procesar.
     */
    void CapturarExpresion(const std::string &expresion);

    /**
     * @brief Imprime la expresión.
     * 
     * Imprime la expresión infija y su equivalente en notación posfija.
     */
    void Imprimir() const;

    /**
     * @brief Evalúa la expresión y devuelve el resultado.
     * 
     * Evalúa la expresión en notación posfija y devuelve el resultado de la operación.
     * 
     * @return El resultado de la evaluación.
     */
    double EvaluarExpresion();
};

#endif
