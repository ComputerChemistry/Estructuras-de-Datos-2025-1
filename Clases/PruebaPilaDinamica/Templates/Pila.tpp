// Pila.tpp
#include <iostream>
#include "../Headers/Pila.hpp"

using std::cout;
using std::endl;

//****************************************
template <typename Tipo>
Pila<Tipo>::Pila() : numElem(0), tope(NULL){}
//****************************************
// Constructor de copia
template <typename Tipo>
Pila<Tipo>::Pila(const Pila<Tipo>& p) {
          *this = p;  
}
//****************************************
// Operador de asignación
template <typename Tipo>
Pila<Tipo>& Pila<Tipo>::operator=(const Pila<Tipo>&s otra) {

   if(this == &p) return *this; 
  
     return *this; 
}

//***************************************
template <typename Tipo>
void Pila<Tipo>::Apilar(Tipo valor) 
{
  Elemento *nuevo = new Elemento;
  nuevo -> valor = valor; 
  nuevo -> valor = tope;
  tope = nuevo; 
  ++numElem; 
}

//***************************************
template <typename Tipo>
void Pila<Tipo>::Vaciar() {

    while(!EstaVacia()) Desapilar(); 
    tope = -1;
}

//***************************************
template <typename Tipo>
Tipo Pila<Tipo>::Desapilar() {
   if(EstaVacia()) throw "Fila vac\24ia";
   Elemento *porBorrar = tope;
   tope = tope -> siguiente; 
   delete porBorrar; 
   --numElem; 
}
//***************************************
template <typename Tipo>
Tipo Pila<Tipo>::ObtenerTope() const {
    if (EstaVacia()) {
        throw std::underflow_error("Error: La pila está vacía");
    }
    return elemento[tope];
}

//***************************************
template <typename Tipo>
bool Pila<Tipo>::EstaVacia() const {
    
    return tope == -1;
}

//***************************************
template <typename Tipo>
int Pila<Tipo>::ObtenerCapacidad() const {
    return capacidad;  
}

//***************************************
template <typename Tipo>
int Pila<Tipo>::ObtenerTamanio() const {
    return tope + 1;  
}

//***************************************
template <typename Tipo>
bool Pila<Tipo>::EstaLlena() const {
    return tope + 1 == capacidad;
}
//***************************************
template <typename Tipo> 
void Pila<Tipo>::Redimensionar() {
  int nuevaCapacidad = capacidad * 2;
  Tipo* nuevoArreglo = new Tipo[nuevaCapacidad];

   for(int i = 0; i <= tope; ++i){
    nuevoArreglo[i] = elemento[i]; 
   } 

   delete [] elemento; 
   elemento = nuevoArreglo; 
   capacidad = nuevaCapacidad; 
}

//***************************************
//Destructor 
template <typename Tipo> 
Pila<Tipo>::~Pila(){
    Vaciar();
}
//***************************************
template <typename Tipo>
void Pila<Tipo>::Imprimir() const {
    if (EstaVacia()) {
        cout << "Pila vacía" << endl;
        return;
    }
    for (int i = 0; i <= tope; ++i) {
        cout << elemento[i] << " ";
    }
    cout << endl;

}
