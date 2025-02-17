/*
Curso: Estructuras de Datos 2025-1
Clase: 03
Fecha: 17/01/2025
Autor: Carlos Eduardo Moreno Vargas
Nombre: PruebaVector
*/

#include <iostream> 
#include <cstdlib>
#include "Vector.hpp"

using namespace std; 
int main()
{

  int n1, n2;
  
// const Vector v(3,1);

 const Vector v(n), w(n), z(n); 

 cout << "\n\n Capturando un Vector" << endl; 
  
 v.Capturar();

 cout << "\n\n Capturando un Segundo Vector:" << endl; 
  
 w.Capturar(); 

  z = v + w; 


 cout << "\n\n Suma: "; 


 z.Imprimir(); 

/*cout << "\n\n Capturando el Tercer Vector:" << endl; 
  
  z.Capturar(); 
*/
 
 do{

    cout << "Dimen\242n  [" <<  MAX_DIM; "]";
 
 }while( n1 < 1 || n1 > MAX_DIM); 

  
 z = v.Sumar(w); 
 
 v.Imprimir(); 
 
 cout << " + "; 
 
 w.Imprimir(); 
 
 cout << " = " << endl;
 
 cout <<  w + v << endl;
 
 
 z.Imprimir(); 
 
 
 return 0; 
 
}
