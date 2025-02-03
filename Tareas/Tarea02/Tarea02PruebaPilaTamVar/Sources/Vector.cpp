#include <cmath>
#include "../Headers/Vector.hpp"

using std::cout;
using std::cin;
using std::sqrt;

//********************************************
// Constructor: Vector con dimensión y valor inicial
Vector::Vector(int dimension, double valor) {
    EstablecerDim(dimension);
    componente = new double[dim];
    for (int i = 0; i < dim; ++i) {
        componente[i] = valor;
    }
}

//********************************************
// Constructor: Vector con dimensión y componentes a 0
/*Vector::Vector(int dimension) {
    EstablecerDim(dimension);
    componente = new double[dim];
    for (int i = 0; i < dim; ++i) {
        componente[i] = 0;
    }
}
*/
//********************************************
// Constructor de copia
Vector::Vector(const Vector &v) {
    dim = v.dim;
    componente = new double[dim];
    for (int i = 0; i < dim; ++i) {
        componente[i] = v.componente[i];
    }
}

//********************************************
// Destructor
Vector::~Vector() {
    delete[] componente;
}

//********************************************
// Operador de asignación
Vector& Vector::operator=(const Vector &v) {
    if (this == &v) return *this;  // Evitar la autoasignación

    // Liberar memoria previa
    delete[] componente;

    // Asignar nueva memoria y copiar los valores
    dim = v.dim;
    componente = new double[dim];
    for (int i = 0; i < dim; ++i) {
        componente[i] = v.componente[i];
    }

    return *this;
}

//********************************************
// Imprimir el vector
void Vector::Imprimir() const {
    cout << "(";
    for (int i = 0; i < dim; ++i) {
        cout << componente[i];
        if (i < dim - 1) cout << ", ";  // Evitar coma al final
    }
    cout << ")";
}

//********************************************
// Capturar componentes del vector
void Vector::Capturar() {
    for (int i = 0; i < dim; ++i) {
        cout << "Componente " << i + 1 << ": ";
        cin >> componente[i];
    }
}

//********************************************
// Obtener dimensión del vector
int Vector::ObtenerDim() const {
    return dim;
}


//********************************************
// Obtener componente del vector

double Vector::ObtenerComponente(int i) const {
    if (i < 0 || i >= dim) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return componente[i];  
}

//********************************************

void Vector::ModificarComponente(int i, double valor) const {
   if(i < 0 || i >= dim){
    
   throw std::out_of_range("indice fuera de rango");
  }
   componente[i] = valor; 
}

//********************************************
// Operador de suma de vectores
Vector Vector::operator+(const Vector v) const {
    if (dim != v.dim) throw "Vectores incompatibles para sumar";
    Vector s(dim);
    for (int i = 0; i < dim; ++i) {
        s.componente[i] = componente[i] + v.componente[i];
    }
    return s;
}

//******************************************** 
// Operador de resta de vectores
Vector Vector::operator-(const Vector v) const {
    if (dim != v.dim) throw "Vectores incompatibles para restar";
    Vector r(static_cast<int>(dim));
    for (int i = 0; i < dim; ++i) {
        r.componente[i] = componente[i] - v.componente[i];
    }
    return r;
}

//********************************************
// Operador de producto punto
double Vector::operator*(const Vector v) const {
    if (dim != v.dim) throw "Vectores incompatibles para multiplicar";
    double prodPunto = 0;
    for (int i = 0; i < dim; ++i) {
        prodPunto += componente[i] * v.componente[i];
    }
    return prodPunto;
}

//********************************************
// Operador de multiplicación por escalar
Vector Vector::operator*(const double escalar) const {
    Vector r(static_cast<int>(dim));
    for (int i = 0; i < dim; ++i) {
        r.componente[i] = escalar * componente[i];
    }
    return r;
}

//********************************************
// Magnitud del vector
double Vector::Magnitud() const {
    double suma = 0;
    for (int i = 0; i < dim; ++i) {
        suma += componente[i] * componente[i];
    }
    return sqrt(suma);
}

//********************************************
// Operador de acceso a los componentes (const)
double Vector::operator[](int i) const {
    if (i < 0 || i >= dim) throw "Índice inválido";
    return componente[i];
}

//********************************************
// Operador de acceso a los componentes (no const)
double& Vector::operator[](int i) {
    if (i < 0 || i >= dim) throw "Índice inválido";
    return componente[i];
}

//********************************************
// Operador externo de multiplicación por escalar
Vector operator*(double escalar, const Vector v) {
    Vector r(v.ObtenerDim());
    for (int i = 0; i < v.ObtenerDim(); ++i) {
       r.ModificarComponente(i,  v.ObtenerComponente(i) * escalar);
    }
    return r;
}

//********************************************
// Método de establecimiento de la dimensión
void Vector::EstablecerDim(int dimension) {
    if (dimension < 1 || dimension > MAX_DIM) {
        throw "Dimensión inválida";
    }
    dim = dimension;
}

//********************************************
// Operador de salida de flujo (ostream)
std::ostream& operator<<(std::ostream &salida, const Vector &v) {
    salida << "(";
    for (int i = 0; i < v.ObtenerDim(); ++i) {
        salida << v.ObtenerComponente(i);
        if (i < v.ObtenerDim() - 1) salida << ", ";  // Evitar coma al final
    }
    salida << ")";
    return salida;
}

//********************************************
// Operador de entrada de flujo (istream)
std::istream& operator>>(std::istream &entrada, Vector &v) {
    for (int i = 0; i < v.dim; ++i) {
        cout << "Componente " << i + 1 << ": ";
        entrada >> v.componente[i];
    }
    return entrada;
}
