#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#define MAX_DIM 10 

using std::cout;

class Vector {

friend Vector operator*(double escalar, const Vector v); 
friend void operator <<(std::ostream &salida, const Vector v );  

public: 
  Vector(); 
  Vector(int dimension);
  Vector (int dimension, double valor);

  int ObtenerDim() const;

  void Imprimir() const;
  void Capturar();

  Vector Sumar(const Vector v) const;
  Vector Restar(const Vector v) const; 
  double Multiplicar(const Vector v ) const ;
  Vector Multiplicar (const double escalar) const; 
  double Magnitud() const; 

private: 
  int dim; 
  double componente[MAX_DIM]; 
  void EstablecerDim(int dimension); 

};

Vector operator* (double escalar, const Vector v); 
void operator <<(std::ostream &salida, const Vector v );


#endif 
