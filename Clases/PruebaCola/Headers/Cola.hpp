#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED 

template <typename Tipo>

class Cola {
  public:
  //Costructor por Default 
  Cola(); 
  //Constructor de Copia
  Cola(const Cola <Tipo>& otra); 
  //Operador de Asignacion  
  Cola<Tipo>& operator=(const Pila<Tipo>& otra);
  //Destructor
  ~Cola(); 
  //Encolar 
  void Encolar(Tipo valor);
  //Imprimir 
  void Imprimir(); 
  //Tipo para desencolar
  Tipo Desencolar(); 
  //Obtener numero de elemetos
  int ObtenerTamanio(); 
  //Conocer si esta Vacia 
  bool EstaVacia() const; 

 private: 
   int numElem; 
   Tipo* elemento;
   struct elemento{

    }*ultimo;

  #include "../Templates/Pila.tpp"
} #endif //COLA_HPP_INCLUDED
