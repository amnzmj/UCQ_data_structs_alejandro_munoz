/* Cuarto Ejercicio de Examen

Añadir al RawArray A todos los elementos del RawArray B 
(llamado arrayToAppend en la declaración de función que les puse aquí abajo). Debe tener los elementos de A y
 luego todos los elementos de B.
 
void AppendArray(RawArray arrayToAppend); */ 


#include <iostream>
#include <algorithm>

class RawArray {
private:
    int* data;
    size_t size;

public:
    RawArray(size_t size) : size(size) {
        data = new int[size];
    }

    ~RawArray() {
        delete[] data;
    }

    void Init(int value) {
        for (size_t i = 0; i < size; i++) {
            data[i] = value;
        }
    }

    void AppendArray(const RawArray& array_to_append) {
        size_t new_size = size + array_to_append.size;
        int* new_data = new int[new_size];

        std::copy(data, data + size, new_data);
        std::copy(array_to_append.data, array_to_append.data + array_to_append.size, new_data + size);

        delete[] data;
        data = new_data;
        size = new_size;
    }

    void Print() const {
        std::cout << "[";
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i];
            if (i != size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    size_t size_a, size_b;
    int value_a, value_b;

    std::cout << "Ingrese el tamaño del primer arreglo (myArray): ";
    std::cin >> size_a;
    std::cout << "Ingrese el valor para inicializar el primer arreglo (myArray): ";
    std::cin >> value_a;

    std::cout << "Ingrese el tamaño del segundo arreglo (otherArray): ";
    std::cin >> size_b;
    std::cout << "Ingrese el valor para inicializar el segundo arreglo (otherArray): ";
    std::cin >> value_b;

    RawArray my_array(size_a);
    my_array.Init(value_a);
    RawArray other_array(size_b);
    other_array.Init(value_b);

    std::cout << "myArray antes de AppendArray: ";
    my_array.Print();

    std::cout << "otherArray antes de AppendArray: ";
    other_array.Print();

    my_array.AppendArray(other_array);

    std::cout << "myArray después de AppendArray: ";
    my_array.Print();

    return 0;
}