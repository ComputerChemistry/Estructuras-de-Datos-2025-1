#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
#include "../Headers/Expresion.hpp"
#include "../Headers/Pila.hpp" 

using std::cout;
using std::cin;
using std::endl;

Expresion::Expresion() : infija(""), posfija(""), esValida(false) {}

Expresion::Expresion(const std::string &expresion) {
    CapturarExpresion(expresion);
}

void Expresion::CapturarExpresion(const std::string &expresion) {
    infija = expresion;
    esValida = ValidarExpresion(expresion);
    if (esValida) {
        posfija = ConvertirAPosfija(expresion);
    }
}

void Expresion::Imprimir() const {
    cout << "Expresión en notación posfija: ";
    if (esValida) {
        cout << posfija << endl;
    } else {
        cout << "Expresión inválida" << endl;
    }
}

double Expresion::EvaluarExpresion() {
    if (!esValida) {
        throw std::runtime_error("La expresión no es válida");
    }
    return EvaluarPosfija(posfija);
}

bool Expresion::ValidarExpresion(const std::string &expresion) {
    std::stack<char> pila;
    for (char c : expresion) {
        if (c == '(' || c == '[' || c == '{') {
            pila.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pila.empty() || 
                (c == ')' && pila.top() != '(') || 
                (c == ']' && pila.top() != '[') || 
                (c == '}' && pila.top() != '{')) {
                return false;
            }
            pila.pop();
        }
    }
    return pila.empty();
}

int Expresion::Precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool Expresion::EsOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Expresion::EsFuncion(const std::string &s) {
    return s == "sin" || s == "cos" || s == "tan" || s == "log" || s == "exp";
}

bool Expresion::EsNumero(char c) {
    return isdigit(c) || c == '.';
}

std::string Expresion::ConvertirAPosfija(const std::string &expresion) {
    std::stack<char> pila;
    std::ostringstream salida;

    for (size_t i = 0; i < expresion.size(); ++i) {
        char c = expresion[i];

        if (EsNumero(c)) {
            salida << c;
    
            while (i + 1 < expresion.size() && EsNumero(expresion[i + 1])) {
                salida << expresion[++i];
            }
            salida << ' ';  
        } else if (c == '(' || c == '[' || c == '{') {
            pila.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            while (!pila.empty() && pila.top() != '(' && pila.top() != '[' && pila.top() != '{') {
                salida << pila.top() << ' ';
                pila.pop();
            }
            pila.pop();  
        } else if (EsOperador(c)) {
            while (!pila.empty() && Precedencia(pila.top()) >= Precedencia(c)) {
                salida << pila.top() << ' ';
                pila.pop();
            }
            pila.push(c);
        } else if (isalpha(c)) { 
            std::string funcion;
            while (i < expresion.size() && isalpha(expresion[i])) {
                funcion += expresion[i++];
            }
            --i; // Ajuste de índice después del loop
            salida << funcion << ' ';
        }
    }

    while (!pila.empty()) {
        salida << pila.top() << ' ';
        pila.pop();
    }

    return salida.str();
}

double Expresion::EvaluarPosfija(const std::string &expresion) {
    std::stack<double> pila;
    std::istringstream tokens(expresion);
    std::string token;

    while (tokens >> token) {
        if (isdigit(token[0])) {
            pila.push(std::stod(token));
        } else if (EsOperador(token[0])) {
            double b = pila.top(); pila.pop();
            double a = pila.top(); pila.pop();
            switch (token[0]) {
                case '+': pila.push(a + b); break;
                case '-': pila.push(a - b); break;
                case '*': pila.push(a * b); break;
                case '/': pila.push(a / b); break;
                case '^': pila.push(std::pow(a, b)); break;
            }
        } else if (EsFuncion(token)) {
            double a = pila.top(); pila.pop();
            if (token == "sin") pila.push(std::sin(a));
            else if (token == "cos") pila.push(std::cos(a));
            else if (token == "tan") pila.push(std::tan(a));
            else if (token == "log") pila.push(std::log(a));
            else if (token == "exp") pila.push(std::exp(a));
        }
    }
    return pila.top();
}
