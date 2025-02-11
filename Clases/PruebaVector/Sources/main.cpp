#include <iostream>
#include <cstdlib>

#include "../Headers/Vector.hpp"

using namespace std;

int main()
{
//    const Vector v(3,1.5);
//    Vector w(3);
//
//    cout << "Capturando un vector" << endl;
//    w.Capturar();
//
//    Vector z;
//
//    z = v + w; // Llamada implícita
//
//    //z = v.operator+(w); // Llamada explícita
//
//
//    cout << "Suma: ";
//    z.Imprimir();

    int n1, n2;

    cout << "Programa que calcula operaciones con vectores" << endl;
    try{
        do{
            cout << "Dimensi\242n del primer vector [1," << MAX_DIM << "]: ";
            cin >> n1;
        }while(n1 < 1 || n1 > MAX_DIM);
        Vector v(n1);

        cout << "Capturando en primer vector" << endl;
        cin >> v;

        do{
            cout << "Dimensi\242n del primer vector [1," << MAX_DIM << "]: ";
            cin >> n2;
        }while(n2 < 1 || n2 > MAX_DIM);
        Vector w(n2);

        cout << "Capturando en segundo vector" << endl;
        cin >> w;

        Vector z;

        z = w + Vector(3);

        cout << "\n\n";

        cout << v << " + " << w << " = " << z << "\n\n";

        z = v - w;

        cout << v << " - " << w << " = " << z << "\n\n";

        cout << v << " * " << w << " = " << w * v << "\n\n";

        double escalar;
        cout << "Escalar: ";
        cin >> escalar;

        z = escalar * v;

        cout << "\n" << v << " * " << escalar << " = " << z << "\n\n";

        z = w * escalar;

        cout << w << " * " << escalar << " = " << z << "\n\n";

        cout << "|" << v << "| = " << v.Magnitud() << "\n\n";

        cout << "|" << w << "| = " << w.Magnitud();

    }catch(const char *mensaje){
        cerr << "Error: " << mensaje << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado" << endl;
    }

    cout << "\n\n";
    system("pause");
    return 0;
}
