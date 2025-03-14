#include <iostream>
#include "../Headers/OrderedList.hpp"

int main() {
    OrderedList<int> list1;
    list1.add(3);
    list1.add(1);
    list1.add(4);
    list1.add(2);

    std::cout << "Lista 1 en orden ascendente: ";
    list1.printAscend();

    std::cout << "Lista 1 en orden descendente: ";
    list1.printDescend();

    list1.remove(3);
    std::cout << "Lista 1 después de eliminar el 3: ";
    list1.printAscend();

    OrderedList<int> list2;
    list2.add(5);
    list2.add(6);

    std::cout << "Lista 2 en orden ascendente: ";
    list2.printAscend();

    list1.merge(list2);
    std::cout << "Lista 1 después de combinar con la Lista 2: ";
    list1.printAscend();

    return 0;
}
