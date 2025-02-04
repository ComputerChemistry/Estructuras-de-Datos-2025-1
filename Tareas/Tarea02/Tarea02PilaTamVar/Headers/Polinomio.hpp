#ifndef POLINOMIO_HPP_INCLUDED
#define POLINOMIO_HPP_INCLUDED

#include <vector>
#include <initializer_list>
#include <iostream>

class Polinomio {
private:
    std::vector<double> coeficientes;

public:
    // Declaración de los constructores, sin definición
    Polinomio();  // Constructor predeterminado
    Polinomio(std::initializer_list<double> coef);
    Polinomio(const std::vector<double>& coef);

    void Imprimir() const;
    Polinomio operator+(const Polinomio& otro) const;
};

#endif // POLINOMIO_HPP_INCLUDED
