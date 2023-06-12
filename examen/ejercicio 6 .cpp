/* Sexto Ejercicio de Examen

Función Insert.
void Insert(RawArray arrayToInsert, int startIndex); 
añade los arrayToInsert.Size-elementos al RawArray que llamó la función Insert,
 a partir del elemento en startIndex.

*/

#include <iostream>
#include <vector>

class RawArray {
private:
    std::vector<int> data;

public:
    RawArray(int size) {
        data.resize(size, 0);
    }

    void init(int value) {
        std::fill(data.begin(), data.end(), value);
    }

    void insert(const RawArray& arrayToInsert, int startIndex) {
        if (startIndex < 0 || startIndex > data.size()) {
            std::cout << "Índice de inicio inválido" << std::endl;
            return;
        }

        std::vector<int> newData(data.size() + arrayToInsert.data.size());

        // Copiar los elementos antes del índice de inicio
        std::copy(data.begin(), data.begin() + startIndex, newData.begin());

        // Copiar los elementos de arrayToInsert
        std::copy(arrayToInsert.data.begin(), arrayToInsert.data.end(), newData.begin() + startIndex);

        // Copiar los elementos después del índice de inicio
        std::copy(data.begin() + startIndex, data.end(), newData.begin() + startIndex + arrayToInsert.data.size());

        // Actualizar los datos del RawArray
        data = newData;
    }

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < data.size(); i++) {
            std::cout << data[i];
            if (i != data.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    int size1, size2;

    std::cout << "Ingrese el tamaño del primer RawArray: ";
    std::cin >> size1;

    std::cout << "Ingrese el tamaño del segundo RawArray: ";
    std::cin >> size2;

    RawArray myArray(size1);
    RawArray toBeInserted(size2);

    int value;

    std::cout << "Ingrese el valor para inicializar el primer RawArray: ";
    std::cin >> value;
    myArray.init(value);

    std::cout << "Ingrese el valor para inicializar el segundo RawArray: ";
    std::cin >> value;
    toBeInserted.init(value);

    int startIndex;
    std::cout << "Ingrese el índice de inicio: ";
    std::cin >> startIndex;

    myArray.insert(toBeInserted, startIndex);

    std::cout << "El resultado es: ";
    myArray.print();

    return 0;
}