/* Segundo Ejercicio de Examen

Ordenamiento de los elementos del RawArray de menor a mayor (o mayor a menor, son prácticamente lo mismo). 
Puede ser selection sort, bubble sort, etc. 
void SortFunction(); */ 

#include <iostream>
#include <vector>

class RawArray {
private:
    std::vector<int> arr;

public:
    RawArray(const std::vector<int>& input_arr) : arr(input_arr) {}

    void assignEveryXElements(int value, int interval) {
        for (int i = interval - 1; i < arr.size(); i += interval) {
            arr[i] = value;
        }
    }

    void sortArray() {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                std::swap(arr[i], arr[min_index]);
            }
        }
    }

    void printArray() const {
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> input_arr;
    int value, num_values;

    std::cout << "\nIngrese la cantidad de valores: ";
    std::cin >> num_values;

    std::cout << "\nIngrese los valores:";
    for (int i = 0; i < num_values; i++) {
        std::cin >> value;
        input_arr.push_back(value);
    }
    
    RawArray arr_obj(input_arr);
    arr_obj.sortArray();

    // Imprimir el arreglo ordenado
    arr_obj.printArray();

    return 0;
}