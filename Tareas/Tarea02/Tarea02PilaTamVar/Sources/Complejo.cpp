#include "../Headers/Complejo.hpp"
#include <iostream>

Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

double Complejo::ObtenerReal() const {
    return real;
}

double Complejo::ObtenerImaginario() const {
    return imaginario;
}

Complejo Complejo::operator+(const Complejo& otro) const {
    return Complejo(real + otro.real, imaginario + otro.imaginario);
}

void Complejo::Imprimir() const {
    std::cout << real << " + " << imaginario << "i" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Complejo& c) {
    out << c.real << " + " << c.imaginario << "i";
    return out;
}
