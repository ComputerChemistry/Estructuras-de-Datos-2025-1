#ifndef COMPLEJO_HPP_INCLUDED
#define COMPLEJO_HPP_INCLUDED

#include <iostream>

class Complejo {
private:
    double real, imaginario;

public:
    Complejo(double r = 0, double i = 0);
    double ObtenerReal() const;
    double ObtenerImaginario() const;
    Complejo operator+(const Complejo& otro) const;
    void Imprimir() const;
    friend std::ostream& operator<<(std::ostream& out, const Complejo& c);

};

#endif// COMPLEJO_HPP_INCLUDED
