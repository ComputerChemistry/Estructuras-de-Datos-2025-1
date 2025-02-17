/*
Estructuras de Datos 2025-1
Clase: 02
Fecha: 15/01/2025
Autor: Carlos Eduardo Moreno Vargas
*/

#include <iostream> 
#include "Vector.hpp"

using namespace std; 
int main()
{

// Vector v,w(3), z(5,3,2); 
  
//  v.Imprimir();  

//  cout << endl; 
  
//  w.Imprimir();

//  cout << endl; 
 
//  z.Imprimir();


 Vector v(n), w(n), z(n); 

 cout << "Capturando un Primer Vector \n\n" << endl; 
  
  v.Capturar();
 
cout << "\n\n Capturando el Segundo Vector:" << endl; 
  
  w.Capturar(); 

cout << " \n\n Capturando el Tercer Vector:" << endl; 
  
  z.Capturar(); 

 do{

    cout << "Dimen\242n  [" <<  MAX_DIM; "]";
 
}while( n < 1 || n > MAX_DIM); 

  
 z = v.Sumar(w); 

 v.Imprimir(); 
 
 cout << " + "; 

  w.Imprimir(); 

 cout << " = ";

 z.Imprimir(); 

  return 0; 

}
