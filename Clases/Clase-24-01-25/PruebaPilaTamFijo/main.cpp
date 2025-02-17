#include <iostream>
#include "Pila.hpp"

using namespace std; 

int main()

{

try{

  Pila miPila; 
  
  if(miPila.EstaVacia()) cout << "La Pila es\240 vac\241a";
                         cout << "La Pila no est\240 vac\241a";

miPila.Apilar(3.2);
miPila.Apilar(5.19);
miPila.Apilar(-9.1);
miPila.Apilar(31.5);
miPila.Apilar(-1.4);

miPila.Imprimir();

cout << "\n\n"; 

miPila.Vaciar();

miPila.Desapilar();
miPila.Desapilar();


miPila.Vaciar();

miPila.Imprimir();



}catch(const char *mensaje ){

  cout << "Error: " << mensaje << endl; 

 }


 return 0; 


}
