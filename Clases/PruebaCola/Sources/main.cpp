#include <iostream>
#include "../Headers/Cola.hpp"

using namespace std;

int main()
{

//**********_Prueba-Cola_***************//

  Cola p(5);

  p.encolar(1);
  p.encolar(2);
  p.encolar(4);
  p.encolar(8);

  cout << "El Elemento del inicio es " <<  p.ultimo(); << endl;
  p.desencolar();

  p.encolar(4); 
 
 cout << "el tamanio de la cola es: " << p.ObtenerTamanio() << endl;

  p.desencolar();
  p.desencolar();
  p.desencolar();
 

if(EstaVacia()){

  cout << "la cola esta vacia \n";

else {

  cout << "la cola no esta vacia \n";

  }    

}

return 0; 

}
