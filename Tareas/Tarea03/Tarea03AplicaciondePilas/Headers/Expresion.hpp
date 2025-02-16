#ifndef EXPRESION_HPP
#define EXPRESION_HPP

#include <string>
#include <stack>
#include <cmath>
#include <stdexcept>
#include "../Headers/Pila.hpp" 
class Expresion {
private:
    std::string infija;
    std::string posfija;
    bool esValida;

    bool ValidarExpresion(const std::string &expresion);
    int Precedencia(char op);
    bool EsOperador(char c);
    bool EsFuncion(const std::string &s);
    bool EsNumero(char c);
    std::string ConvertirAPosfija(const std::string &expresion);
    double EvaluarPosfija(const std::string &expresion);

public:
    Expresion();
    Expresion(const std::string &expresion);
    void CapturarExpresion(const std::string &expresion);
    void Imprimir() const;
    double EvaluarExpresion();
};

#endif
