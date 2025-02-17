#include "../Headers/Polinomio.hpp"

Polinomio::Polinomio() : coeficientes() {}

Polinomio::Polinomio(std::initializer_list<double> coef) : coeficientes(coef) {}

Polinomio::Polinomio(const std::vector<double>& coef) : coeficientes(coef) {}

void Polinomio::Imprimir() const {
    for (size_t i = 0; i < coeficientes.size(); ++i) {
        std::cout << coeficientes[i] << "x^" << i;
        if (i != coeficientes.size() - 1) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
}

Polinomio Polinomio::operator+(const Polinomio& otro) const {
    size_t max_size = std::max(coeficientes.size(), otro.coeficientes.size());
    std::vector<double> resultado(max_size, 0.0);

    for (size_t i = 0; i < coeficientes.size(); ++i) {
        resultado[i] += coeficientes[i];
    }

    for (size_t i = 0; i < otro.coeficientes.size(); ++i) {
        resultado[i] += otro.coeficientes[i];
    }

    return Polinomio(resultado); 
}
