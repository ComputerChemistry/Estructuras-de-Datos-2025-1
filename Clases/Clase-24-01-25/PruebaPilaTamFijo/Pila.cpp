#include <iostream>
#include "Pila.hpp"

//****************************************

Pila::Pila() : tope (-1){}

//***************************************
void Pila::Apilar(double valor)

{
  if (EstaLlena()) throw "Pila esta llena"
  ++tope; 
  elemento[tope = valor];
}

//***************************************
void Pila::Vaciar()
{
  tope  = -1; 
}

//***************************************

void Pila::Desapilar()
{
  if(EstaVacia()) throw "Pila vac\241a"; 
  --tope;
}

//***************************************
double Pila::ObtenerTope() const
{
  
  if(EstaVacia()) throw "Pila vac\241a"; 
  return elemento[tope]; 
}
//***************************************

bool Pila::EstaVacia() const 
{
  
  return tope == -1; 

}

//***************************************

bool Pila::EstaLlena() const
{

  return tope + 1 == MAX_TAM; 

}

//***************************************
void Pila::Imprimir() const
{

 for(int i = 0; i <= tope; ++i){

  std::cout << elemento[i] << ", ";


  }
   cout << "\b\b"; 
}


//***************************************
