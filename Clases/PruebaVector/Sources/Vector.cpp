#include <cmath>
#include "../Headers/Vector.hpp"

using std::cout;
using std::cin;
using std::sqrt;

//********************************************
Vector::Vector(int dimension, double valor)
{
    EstablecerDim(dimension);
    delete [] componente;  
    dim = v.dim; 
    try{
      componente = new double[dim]; 
       dim = v.dim; 
       for(int i = 0 ; i < dim ; ++i){
	 componente[i] = v.componente[i];
       }
    }catch (std::bad_alloc &){
      throw "Problemas de asignacion de memoria";
 }
}

//********************************************
Vector::Vector(int dimension)
{
    EstablecerDim(dimension);
    for(int i = 0 ; i < dim ; ++i){
        componente[i] = 0;
    }
}

//********************************************
Vector::Vector(int dimension, double valor)
{
    EstablecerDim(dimension);
    for(int i = 0 ; i < dim ; ++i){
        componente[i] = valor;
    }
}

//********************************************
Vector::Vector(const Vector &v) : componente(NULL)
{

  componente = NULL;
  *this = v; 
  
}

//********************************************
Vector::~Vector()
{
  delete [] componente; 
}

//********************************************
Vector & Vector::operator=(const Vector &v)
{
  if(this == &v) return; 
 delete [] componente; 
 dim = v.dim; 
    try{
      componente = new double[dim]; 
       dim = v.dim; 
       for(int i = 0 ; i < dim ; ++i){
	 componente[i] = v.componente[i];
       }
    }catch (std::bad_alloc &){
      throw "Problemas de asignaci\242n de memoria";
 }
    return *this;
}
//********************************************
void Vector::Imprimir() const
{
    cout << "(";
    for(int i = 0 ; i < dim ; ++i){
        cout << componente[i] << ", ";
    }
    cout << "\b\b)";
}
//********************************************
void Vector::Capturar()
{
    for(int i = 0 ; i < dim ; ++i){
        cout << "Componente " << i+1 << ": ";
        cin >> componente[i];
    }
}
//********************************************
int Vector::ObtenerDim() const
{
    return dim;
}
//********************************************
Vector Vector::operator+(const Vector v) const
{
    if(dim != v.dim) throw "Vectores incompatibles para sumar";
    Vector s(dim);
    for(int i = 0 ; i < s.dim ; ++i){
        s.componente[i] = componente[i] + v.componente[i];
    }
    return s;
}
//********************************************
Vector Vector::operator-(const Vector v) const
{
    if(dim != v.dim) throw "Vectores incompatibles para restar";
    Vector r(dim);
    for(int i = 0 ; i < r.dim ; ++i){
        r.componente[i] = componente[i] - v.componente[i];
    }
    return r;
}
//********************************************
double Vector::operator*(const Vector v) const
{
    if(dim != v.dim) throw "Vectores incompatibles para multiplicar";
    double prodPunto = 0;
    for(int i = 0 ; i < dim ; ++i){
        prodPunto += componente[i] * v.componente[i];
    }
    return prodPunto;
}
//********************************************
Vector Vector::operator*(const double escalar) const
{
    Vector r(dim);
    for(int i = 0 ; i < r.dim ; ++i){
        r.componente[i] = escalar * componente[i];
    }
    return r;
}
//********************************************
double Vector::Magnitud() const
{
    double suma = 0;
    for(int i = 0 ; i < dim ; ++i){
        suma += componente[i] * componente[i];
    }
    return sqrt(suma);
}
//********************************************
double Vector::operator[](int i) const
{
    if(i < 0 || i >= dim) throw "\326ndice inv\240lido";
    return componente[i];
}
//********************************************
double & Vector::operator[](int i)
{
    if(i < 0 || i >= dim) throw "\326ndice inv\240lido";
    return componente[i];
}

//********************************************
//    Métodos externos
//********************************************
Vector operator*(double escalar, const Vector v)
{
    Vector r(v.dim);
    for(int i = 0 ; i < v.dim ; ++i){
        r.componente[i] = v.componente[i] * escalar;
    }
    return r;
}

//********************************************
//   Métodos de utilería
//********************************************
void Vector::EstablecerDim(int dimension)
{
    if(dimension < 1 || dimension >MAX_DIM){
        throw "Dimensi\242n inv\240lida";
    }
    dim = dimension;
}
//********************************************
std::ostream & operator<<(std::ostream &salida, const Vector v)
{
    salida << "(";
    for(int i = 0 ; i < v.dim ; ++i){
        salida << v.componente[i] << ", ";
    }
    salida << "\b\b)";
    return salida;
}
//********************************************
std::istream & operator>>(std::istream &entrada, Vector &v)
{
    for(int i = 0 ; i < v.dim ; ++i){
        cout << "Componente " << i+1 << ": ";
        entrada >> v.componente[i];
    }
    return entrada;
}





