CXX = g++
CXXFLAGS = -g
OBJ = main.o Pila.o

# Regla principal
main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o PruebaPilaTamFijo $(OBJ)

# Regla para compilar main.o
Pila.o: main.cpp Pila.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regla para compilar Vector.o
Pila.o: Pila.cpp Pila.hpp
	$(CXX) $(CXXFLAGS) -c Pila.cpp

# Limpiar parchivos intermedios
.PHONY: clean
clean:
	rm -rf *.o main

