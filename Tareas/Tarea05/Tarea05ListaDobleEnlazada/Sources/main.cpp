#include <iostream>
#include "../Headers/ListaDoble.hpp"

int main() {

    Lista<int> lista;


   
    lista.pushFront(10);  
    lista.pushBack(20);   
    lista.pushBack(30);   
    lista.pushFront(5);   

 
    std::cout << "Lista original: ";
    lista.print();  

    
    std::cout << "Lista en reversa: ";
    lista.printReverse();  


    std::cout << "Elemento en índice 2: " << lista[2] << std::endl; 
    lista[2] = 15;  
    std::cout << "Elemento en índice 2 después de modificar: " << lista[2] << std::endl; 

    
    lista.popFront();  
    lista.popBack();   
    std::cout << "Lista después de eliminar primero y último: ";
    lista.print();  

  
    lista.removeAt(1);  
    std::cout << "Lista después de eliminar el elemento en índice 1: ";
    lista.print();  

    
    int searchValue = 20;
    int position = lista.search(searchValue);
    std::cout << "El valor " << searchValue << " se encuentra en la posición: " << position << std::endl;

    
    position = lista.findPosition(10);  
    std::cout << "La posición de 10 es: " << position << std::endl;  


    std::cout << "La lista está vacía: " << (lista.isEmpty() ? "Sí" : "No") << std::endl;


    std::cout << "Primer elemento: " << lista.front() << std::endl;  
    std::cout << "Último elemento: " << lista.back() << std::endl;   


    std::cout << "Tamaño de la lista: " << lista.getSize() << std::endl;  


    lista.clear();
    std::cout << "Lista vacía después de clear: ";
    lista.print(); 


    lista.pushBack(40);
    lista.pushBack(50);
    lista.pushBack(60);

   
    std::cout << "Lista después de agregar nuevos elementos: ";
    lista.print(); 

    // Ordenar la lista
    lista.sort();
    std::cout << "Lista ordenada: ";
    lista.print();  

   
    Lista<int> lista2;
    lista2.pushBack(70);
    lista2.pushBack(80);

    std::cout << "Lista 2 antes de transferir: ";
    lista2.print(); 

    lista.transferFrom(lista2);
    std::cout << "Lista 1 después de transferir: ";
    lista.print();  

    
    lista.swap(lista2);
    std::cout << "Lista 1 después de intercambiar: ";
    lista.print();  
    std::cout << "Lista 2 después de intercambiar: ";
    lista2.print();  

    return 0;
}
