#ifndef PILA_HPP_INCLUDED 
#define PILA_HPP_INCLUDED 
#define MAX_TAM 100

class Pila{
  public: 
  Pila(); 
  void Apilar(double valor);
  void Desapilar();  
  double ObtenerTope() const; 
  bool EstaVacia() const; 
  bool EstaLlena() const; 
//Por pruebas
  void Imprimir() const; 
  void  Vaciar(); 

private: 
  int tope;
  double elemento [MAX_TAM];

};

#endif PILA_HPP_INCLUDED 
