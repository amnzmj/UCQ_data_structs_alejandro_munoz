/* Quinto Ejercicio de Examen

Función CambiarTamaño/SetSize.
void SetSize(int newSize); modifica el RawArray para tener un número de elementos igual a newSize. 
Si newSize es mayor al Size actual del RawArray que la llame, se deben conservar los Size-elementos que ya tenía. 
Si newSize es menor que el Size actual del RawArray que la llame, se deben conservar los primeros elementos de dicho 
RawArray hasta newSize */


#include <iostream>
#include <vector>

class RawArray {
private:
    std::vector<int> data;

public:
    RawArray() {}

    void Init(int size, int value) {
        data.assign(size, value);
    }

    void SetSize(int newSize) {
        if (newSize == data.size()) {
            return;
        }

        if (newSize < data.size()) {
            data.resize(newSize);
        } else {
            data.resize(newSize);
        }
    }

    void Print() {
        std::cout << "[";
        for (int i = 0; i < data.size(); i++) {
            std::cout << data[i];
            if (i != data.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    RawArray myArray;

    int size, value;
    std::cout << "Ingrese el tamaño del arreglo: ";
    std::cin >> size;

    std::cout << "Ingrese el valor para inicializar el arreglo: ";
    std::cin >> value;

    myArray.Init(size, value);

    std::cout << "Arreglo inicializado:" << std::endl;
    myArray.Print();

    int newSize;
    std::cout << "Ingrese el nuevo tamaño del arreglo: ";
    std::cin >> newSize;

    myArray.SetSize(newSize);

    std::cout << "Arreglo modificado (nuevo tamaño: " << newSize << "):" << std::endl;
    myArray.Print();

    return 0;
}