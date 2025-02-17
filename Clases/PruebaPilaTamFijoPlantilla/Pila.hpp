#ifndef PILA_HPP_INCLUDED 
#define PILA_HPP_INCLUDED 
#define MAX_TAM 100

template <typename Tipo>

class Pila{
  public: 
  Pila(); 
  void Apilar(Tipo valor);
  void Desapilar();  
  Tipo ObtenerTope() const; 
  bool EstaVacia() const; 
  bool EstaLlena() const; 
//Por pruebas
  void Imprimir() const; 
  void  Vaciar(); 

private: 
  int tope;
  Tipo elemento [MAX_TAM];

};
#include "Pila.tpp"
#endif //PILA_HPP_INCLUDED 
