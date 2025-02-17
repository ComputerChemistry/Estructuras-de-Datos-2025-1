#include <iostream>
#include "Vector.hpp"

using std::cout; 
using std::cin; 
using std::sqrt; 

Vector::Vector()
{

  EstablecerDim(MAX_DIM); 
    
  for (int i = 0; i < dim; ++i) {
  
    componente[i] = 0;  

  }
}

//.......................................................................................................................................

Vector::Vector(int dimension)
{
  EstablecerDim(dimension);  

  for (int i = 0; i < EstablecerDim; ++i) {
    
    componente[i] = 0;  

  }
  
}

Vector::Vector(int dimension, double valor){
 
  dimension = EstablecerDim;

  for (int i = 0; i < EstablecerDim; ++i) {
    
    componente[i] = valor;  

  }
  
}

//.......................................................................................................................................

void Vector::Imprimir()
{

  std::cout << "(";   
  for (int i = 0; i < EstablecerDim; ++i) {
    
    std::cout << componente[i] << ", "; 

   }

  std::cout << "\b\b)"; 

}

void Vector::Capturar()
{

  for(int i = 0; i < EstablecerDim; ++i){

    cout << "componente" << i + 1 << ": ";
    cin >> componente[i];

  }

}

//.......................................................................................................................................

Vector Vector::Sumar(const Vector v) const
{
  if(dim != v.EstablecerDimension) throw "Vector incompatible para la suma ";  Vector s(EstablecerDim); 
  for(int i = 0 ; i < EstablecerDim; ++i){

    s.componente[i] = componente[i] + v.componente[i]; 

  
  }

  return s;

}

Vector::Vector::Resta(Vector v)
{
  if(dim != v.EstablecerDim) throw "Vector incompatible para la suma ";  Vector s(dim); 
  for(i = 0 ; i < EstablecerDim; ++i){

    s.componente[i] = componente[i] - v.componente[i]; 
    
    return s; 

  }

}

Vector::Vector::Multiplicar(Vector v)
{

  if(dim != v.dim) throw "Vector incompatible con la multiplicacion "; Vector s(dim);

  for (int i = 0; i < EstablecerDim; ++i){

   s.componente[i] = componente[i] * v.componente[i];  

    return s;  
  } 
 

}

//.......................................................................................................................................

int Vector:ObtenerDim() const
{

  return EstablecerDim ;

}


//.......................................................................................................................................

Vector operator* (double escalar, const  Vector){

  Vector r(v.EstablecerDim);
  for(int i = 0;  i < EstablacerDim; ++i ){

    r.componente[i] = v.componente[i] * escalar;   


  }
  return r; 
}



void Vector::EstablecerDim(int dimension)
{


  if (dimension < 1 || dimension > MAX_DIM)
    { 

      throw "Dimen\24n inv\240lida ";

    } 

}



