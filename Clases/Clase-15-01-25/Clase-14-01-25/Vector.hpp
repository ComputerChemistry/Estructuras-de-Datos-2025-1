#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include <iostream> 
#define MAX_DIM 10 

class Vector {

public: 
  Vector(); 
  Vector(int dimension);
  Vector (int dimension, double valor);
  
  void Imprimir();
  void Capturar();
  Vector Sumar(Vector v&);
  //Vector Restar(Vector v); 
  //Vector ProductoPunto(Vector v);
  
private: 
  int dim; 
  double componente[MAX_DIM]; 

};
#endif 
