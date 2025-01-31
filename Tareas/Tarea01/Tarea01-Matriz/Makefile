CXX = g++
CXXFLAGS = -g
OBJ = main.o Matriz.o

# Regla principal
main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o ClaseMatriz $(OBJ)

# Regla para compilar main.o
ClaseMatriz.o: main.cpp Matriz.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regla para compilar Vector.o
Matriz.o: Matriz.cpp Matriz.hpp
	$(CXX) $(CXXFLAGS) -c Matriz.cpp

# Limpiar archivos intermedios
.PHONY: clean
clean:
	rm -rf *.o main

