CXX = g++
CXXFLAGS = -g
OBJ = main.o Vector.o

# Regla principal
main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o PruebaVector $(OBJ)

# Regla para compilar main.o
PruebaVector.o: main.cpp Vector.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regla para compilar Vector.o
Vector.o: Vector.cpp Vector.hpp
	$(CXX) $(CXXFLAGS) -c Vector.cpp

# Limpiar archivos intermedios
.PHONY: clean
clean:
	rm -rf *.o main

