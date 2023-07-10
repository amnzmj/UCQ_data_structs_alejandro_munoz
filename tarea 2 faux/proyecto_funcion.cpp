#include <iostream>
#include "Operaciones.h"

int main()
{
    List<char> myList; // Crea una instancia de la lista vac�a

    // Agrega elementos a la lista
    myList.PushBack('a');
    myList.PushBack('b');
    myList.PushBack('c');

    std::cout << "Lista original: ";
    myList.Print(); // Imprime los elementos de la lista

    const int arraySize = 5;
    int myArray[arraySize] = { 1, 2, 5, 7, 9 };

    List<int> myList2(myArray, arraySize); // Crea una instancia de la lista con elementos de un array

    std::cout << "Lista con elementos: ";
    myList2.Print();

    myList2.Reverse(); // Invierte el orden de los elementos en la lista

    std::cout << "Lista invertida: ";
    myList2.Print();

    const int arraySize3 = 8;
    int myArray3[arraySize3] = { 1, 1, 2, 3, 4, 2, 3, 1 };

    List<int> myList3(myArray3, arraySize3); // Crea una instancia de la lista con elementos duplicados

    std::cout << "Lista original: ";
    myList3.Print();

    myList3.Unique(); // Elimina los elementos duplicados de la lista

    std::cout << "Lista sin duplicados: ";
    myList3.Print();

    return 0;
}


