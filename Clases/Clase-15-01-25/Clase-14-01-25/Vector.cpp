#include <iostream>
#include "Vector.hpp"

using std::cout; 
using std::cin; 

Vector::Vector()
{

  dim = 7; 
    for (int i = 0; i < dim; ++i) {
    
     componente[i] = 0;  

  }
}

//.......................................................................................................................................

Vector::Vector(int dimension)
{

  dim = dimension; 
    for (int i = 0; i < dim; ++i) {
    
     componente[i] = 0;  

  }
  
}

Vector::Vector(int dimension, double valor){

dim = dimension; 
    for (int i = 0; i < dim; ++i) {
    
     componente[i] = valor;  

  }
  
}

//.......................................................................................................................................

void Vector::Imprimir()
{

  std::cout << "(";   
  for (int i = 0; i < dim; ++i) {
    
    std::cout << componente[i] << ", "; 

  }

 std::cout << "\b\b)"; 

}

void Vector::Capturar()
{

for(int i = 0; i < dim; ++i){

  cout <<"componente" << i + 1 << ": ";
    cin >> componente[i];

 }

}

//.......................................................................................................................................

 Vector Vector::Sumar(Vector v)
{
  if(dim != v.dim) throw "Vector incompatible para la suma ";  Vector s(dim); 
  for(int i = 0 ; i < dim; ++i){

    s.componente[i] = componente[i] + v.componente[i]; 

  
}

 return s;


}

Vector Vector::Resta(Vector v)
{
  if(dim != v.dim) throw "Vector incompatible para la suma ";  Vector s(dim); 
  for(i = 0 ; i < dim; ++i){

    s.componente[i] = componente[i] - v.componente[i]; 
    
    return s; 

  }

}

Vector Vector::Multiplicar(Vector v, const escalar)
{

  if(dim != v.dim) throw "No compatible con la multiplicacion"; Vector s(dim);  
   for(int i = 0; i < dim ++i){

      s.componente = componente[i] * v.compoente[i]; 

      return s; 

    }
    
}



