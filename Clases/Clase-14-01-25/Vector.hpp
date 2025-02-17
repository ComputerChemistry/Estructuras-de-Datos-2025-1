#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
class Vector {


public: 
  Vector(); 
  Vector(int dimension);
  Vector (int dimension, double valor);

  void Imprimir();

private: 
  int dim; 
  double componente[10]; 

};


#endif 
