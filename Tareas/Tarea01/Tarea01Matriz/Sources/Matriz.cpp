#include "../Headers/Matriz.hpp"

// Constructor con parámetros por defecto
Matriz::Matriz(unsigned int f, unsigned int c) : filas(f), columnas(c) {
    if (filas == 0 || columnas == 0) {
        throw std::invalid_argument("Las filas y columnas deben ser positivas.");
    }
    datos = new double*[filas];
    for (unsigned int i = 0; i < filas; ++i) {
        datos[i] = new double[columnas]();
    }
}

// Destructor
Matriz::~Matriz() {
    for (unsigned int i = 0; i < filas; ++i) {
        delete[] datos[i];
    }
    delete[] datos;
}

// Constructor de copia
Matriz::Matriz(const Matriz& otra) : filas(otra.filas), columnas(otra.columnas) {
    datos = new double*[filas];
    for (unsigned int i = 0; i < filas; ++i) {
        datos[i] = new double[columnas];
        for (unsigned int j = 0; j < columnas; ++j) {
            datos[i][j] = otra.datos[i][j];
        }
    }
}

// Operador de asignación
Matriz& Matriz::operator=(const Matriz& otra) {
    if (this != &otra) {
        for (unsigned int i = 0; i < filas; ++i) {
            delete[] datos[i];
        }
        delete[] datos;

        filas = otra.filas;
        columnas = otra.columnas;
        datos = new double*[filas];
        for (unsigned int i = 0; i < filas; ++i) {
            datos[i] = new double[columnas];
            for (unsigned int j = 0; j < columnas; ++j) {
                datos[i][j] = otra.datos[i][j];
            }
        }
    }
    return *this;
}

// Sobrecargas de operadores para operaciones de matrices
Matriz Matriz::operator+(const Matriz& otra) const {
    if (filas != otra.filas || columnas != otra.columnas) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma.");
    }
    Matriz resultado(filas, columnas);
    for (unsigned int i = 0; i < filas; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado.datos[i][j] = datos[i][j] + otra.datos[i][j];
        }
    }
    return resultado;
}

Matriz Matriz::operator-(const Matriz& otra) const {
    if (filas != otra.filas || columnas != otra.columnas) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la resta.");
    }
    Matriz resultado(filas, columnas);
    for (unsigned int i = 0; i < filas; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado.datos[i][j] = datos[i][j] - otra.datos[i][j];
        }
    }
    return resultado;
}

Matriz Matriz::operator*(const Matriz& otra) const {
    if (columnas != otra.filas) {
        throw std::invalid_argument("Dimensiones inválidas para la multiplicación de matrices.");
    }
    Matriz resultado(filas, otra.columnas);
    for (unsigned int i = 0; i < filas; ++i) {
        for (unsigned int j = 0; j < otra.columnas; ++j) {
            resultado.datos[i][j] = 0;
            for (unsigned int k = 0; k < columnas; ++k) {
                resultado.datos[i][j] += datos[i][k] * otra.datos[k][j];
            }
        }
    }
    return resultado;
}

Matriz Matriz::operator*(double escalar) const {
    Matriz resultado(filas, columnas);
    for (unsigned int i = 0; i < filas; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado.datos[i][j] = datos[i][j] * escalar;
        }
    }
    return resultado;
}

// Método para calcular la transpuesta de la matriz
Matriz Matriz::transpuesta() const {
    Matriz resultado(columnas, filas);
    for (unsigned int i = 0; i < filas; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado.datos[j][i] = datos[i][j];
        }
    }
    return resultado;
}

/*
// Método para calcular la inversa de una matriz cuadrada
Matriz Matriz::inversa() const {
    // La lógica de inversión se implementará aquí
    // Marcador de posición por ahora
    throw std::logic_error("Método de inversa no implementado aún.");
}
*/

// Método para redimensionar la matriz
void Matriz::redimensionar(unsigned int nuevasFilas, unsigned int nuevasColumnas) {
    double** nuevosDatos = new double*[nuevasFilas];
    for (unsigned int i = 0; i < nuevasFilas; ++i) {
        nuevosDatos[i] = new double[nuevasColumnas]();
        for (unsigned int j = 0; j < nuevasColumnas; ++j) {
            if (i < filas && j < columnas) {
                nuevosDatos[i][j] = datos[i][j];
            }
        }
    }
    for (unsigned int i = 0; i < filas; ++i) {
        delete[] datos[i];
    }
    delete[] datos;

    datos = nuevosDatos;
    filas = nuevasFilas;
    columnas = nuevasColumnas;
}

// Funciones amigas para entrada y salida
std::ostream& operator<<(std::ostream& os, const Matriz& matriz) {
    for (unsigned int i = 0; i < matriz.filas; ++i) {
        for (unsigned int j = 0; j < matriz.columnas; ++j) {
            os << matriz.datos[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matriz& matriz) {
    for (unsigned int i = 0; i < matriz.filas; ++i) {
        for (unsigned int j = 0; j < matriz.columnas; ++j) {
            is >> matriz.datos[i][j];
        }
    }
    return is;
}

// Operador no miembro para multiplicación escalar
Matriz operator*(double escalar, const Matriz& matriz) {
    return matriz * escalar;
}
