/* [10 Puntos extra]:

GetIndicesOf, que igual recibe un valor X, pero esta regresa TODOS los indices de los elementos con valor X, 
si no hay ninguno, regresa un array cuyo primer y único elemento es -1.
int [] GetIndicesOf(int x); ó RawArray GetIndicesOf(int x); la que prefieran. */

#include <iostream>
#include <vector>

class RawArray {
private:
    std::vector<int> data;

public:
    void SetData(const std::vector<int>& newData) {
        data = newData;
    }

    RawArray GetIndicesOfValue(int value) const {
        RawArray indices;
        
        for (std::vector<int>::size_type i = 0; i < data.size(); i++) {
            if (data[i] == value) {
                indices.AddElement(i);
            }
        }
        
        if (indices.GetSize() == 0) {
            indices.AddElement(-1);
        }
        
        return indices;
    }

    void AddElement(int element) {
        data.push_back(element);
    }

    int GetSize() const {
        return data.size();
    }

    int GetElementAt(int index) const {
        return data[index];
    }
};

int main() {
    RawArray arr;
    int size;
    int value;
    
    std::cout << "Ingrese el tamaño del arreglo: ";
    std::cin >> size;

    std::vector<int> inputData;
    
    std::cout << "Ingrese los elementos del arreglo: ";
    for (int i = 0; i < size; i++) {
        int element;
        std::cin >> element;
        inputData.push_back(element);
    }
    
    arr.SetData(inputData);
    
    std::cout << "Ingrese el valor a buscar: ";
    std::cin >> value;
    
    RawArray result = arr.GetIndicesOfValue(value);
    
    std::cout << "Indices de " << value << ": ";
    
    for (int i = 0; i < result.GetSize(); i++) {
        std::cout << result.GetElementAt(i) << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}