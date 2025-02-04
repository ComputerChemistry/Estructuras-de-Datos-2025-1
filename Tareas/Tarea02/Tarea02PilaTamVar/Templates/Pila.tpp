// Pila.tpp
#include <iostream>
#include "../Headers/Pila.hpp"

using std::cout;
using std::endl;

//****************************************
template <typename Tipo>
Pila<Tipo>::Pila() : tope(-1), capacidad(10){

	elemento = new Tipo[capacidad];

}
//****************************************
// Constructor de copia
template <typename Tipo>
Pila<Tipo>::Pila(const Pila<Tipo>& otra) {
    capacidad = otra.capacidad;            // Copiar la capacidad
    tope = otra.tope;                      // Copiar el índice del tope
    elemento = new Tipo[capacidad];        // Crear un nuevo arreglo con la misma capacidad

    for (int i = 0; i <= tope; ++i) {     // Copiar los elementos uno por uno
        elemento[i] = otra.elemento[i];
    }
}

//****************************************
// Operador de asignación
template <typename Tipo>
Pila<Tipo>& Pila<Tipo>::operator=(const Pila<Tipo>& otra) {
    if (this != &otra) {  // Evitar la autoasignación
        delete[] elemento;  // Eliminar el arreglo existente

        capacidad = otra.capacidad;    // Copiar la capacidad
        tope = otra.tope;              // Copiar el índice del tope
        elemento = new Tipo[capacidad]; // Crear un nuevo arreglo con la misma capacidad

        for (int i = 0; i <= tope; ++i) {   // Copiar los elementos uno por uno
            elemento[i] = otra.elemento[i];
        }
    }
    return *this;  // Devolver el objeto actual
}

//***************************************
template <typename Tipo>
void Pila<Tipo>::Apilar(Tipo valor) {
    if (tope + 1 == capacidad) {
        Redimensionar(); 
    }
    elemento[++tope] = valor;
}

//***************************************
template <typename Tipo>
void Pila<Tipo>::Vaciar() {
    tope = -1;
}

//***************************************
template <typename Tipo>
Tipo Pila<Tipo>::Desapilar() {
    if (EstaVacia()) {
        throw std::underflow_error("Error: La pila está vacía");
    }
    --tope; // Mover el índice del tope hacia abajo
    return elemento[tope]; // Devuelves el valor desapilado
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
    return capacidad;  // Retorna la capacidad total de la pila
}

//***************************************
template <typename Tipo>
int Pila<Tipo>::ObtenerTamanio() const {
    return tope + 1;  // Retorna el número de elementos en la pila (tope + 1)
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
    delete [] elemento;
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
