//Cola.tpp
#include <iostream> 
#include "../Headers/Cola.hpp"

using std::cout; 
using std::endl;
using std::cerr; 

//Constructor por Default 
Cola<Tipo>::Cola : numElem, elemento(NULL){}

//*********************************************
//Constructor de Copia 
template <typename Tipo> 
Cola<Tipo>::Cola(const Cola<Tipo> &p){
  *this = p; 
}

//*********************************************

//Operador de Asignacion
template <typename Tipo> 

Cola<Tipo>& Cola<Tipo>::operator=(const Cola<Tipo>& otra){
    if(this != &otra){
      delete [] elemento;
          
      capacidad = otra.capacidad; 
      ultimo = otra.ultimo;
     
      elemento = new Tipo [capacidad]; 

      for(int i = 0; <= ultimo; ++i){

       elemento[i] = otra.elemento[i]; 
      } 
      
    }
      return *this; 
}
//*********************************************

template <typename Tipo>
void Cola<Tipo>::Encolar(Tipo valor){ 

  if(ultimo + 1 == capacidad){

    }

   cout << "Cola vacia" << endl; 
      return; 
  }
  for (int i = 0; i <= ultimo; ++i ) 
   cout << elemento[i] << "";  
  }
  cout << endl;
}

//*********************************************
Tipo Cola<Tipo>::Desencolar(){
  if(EstaVacia()) {
   throw std::underflow_error("Error: la cola esta vacia ")
    
}
  --ultimo;
  return elemento[ultimo];

}

//*********************************************

template <typename Tipo>
void Cola<Tipo>::Vaciar()
{
  ultimo = +1; 
}

//*********************************************
template <typename Tipo> 
Tipo Cola<Tipo>::ObtenerUltimo() const {
  if(EstaVacia()){
    throw std::underflow_error("Error: la cola esta vacia"); 
  
}
  return elemento[ultimo];   
}
//***************************************

int Cola<Tipo>::ObtenerTamanio() const{
  return ultimo + 1; 
}

//***************************************

bool Cola<Tipo>::EstaLlena() const {
  return ultimo + 1 == capacidad; 
}

//*********************************************
void Cola<Tipo>::Imprimir() const {

  if(EstaVacia()) {
    cout << "Cola vacia" << endl;
    return;
  }
  for(int i = 0; <= ultimo; ++i){
    cout << elemento[i] << " ";
  }
  cout << endl; 
}











