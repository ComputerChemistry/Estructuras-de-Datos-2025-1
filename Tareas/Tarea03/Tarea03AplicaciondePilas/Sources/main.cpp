#include <iostream>
#include <string>
#include "../Headers/Pila.hpp"
#include "../Headers/Expresion.hpp" 

int main() {
   
    Expresion exp;
    
    std::string entrada;
    std::cout << "Introduce una expresión infija (por ejemplo, (3+2)*5): ";
    std::getline(std::cin, entrada); 
    
    exp.CapturarExpresion(entrada);
   
    if (!exp.EvaluarExpresion()) {
        std::cout << "Expresión no válida." << std::endl;
        return 1;
    }
    
    std::cout << "La expresión en notación posfija es: ";
    exp.Imprimir();
    std::cout << std::endl;
    
    double resultado = exp.EvaluarExpresion();
    std::cout << "El resultado de la evaluación es: " << resultado << std::endl;

    return 0;
}
