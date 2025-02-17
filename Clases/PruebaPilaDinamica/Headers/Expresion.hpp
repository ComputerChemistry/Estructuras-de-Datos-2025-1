#ifndef EXPRESION_HPP_INCLUDED 
#define EXPRESION_HPP_INCLUDED

#include <iostream>
#include <stdexcep> 

//template <Typename Tipo> 

Class Expresion {

  public: 

   Expresion(); 

   void ObtenerExpresion() const;

   bool VerificarExpresion() const; 

   void Imprimir() const;

   ~Expresion();


  private:
  
 string *cadena; 
  

};

#endif//EXPRESION_HPP_INCLUDED
