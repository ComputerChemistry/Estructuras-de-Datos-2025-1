#include <iostream>
#include "Vector.hpp"

Vector::Vector()
{

  dim = 7; 
    for (int i=0; i < dim; ++i) {
    
     componente[i] = 0;  

  }

}

//...................................
Vector::Vector(int dimension)
{

  dim = dimension; 
    for (int i=0; i < dim; ++i) {
    
     componente[i] = 0;  

  }
  
}


//....................................

void Vector::Imprimir()
{

  std::cout << "(";   
  for (int i=0; i < dim; ++i) {
    
    std::cout << componente[i] << ", "; 

  }

 std::cout << "\b\b)"; 

}
