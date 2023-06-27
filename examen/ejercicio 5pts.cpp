/* [5 Puntos extra]:

GetLastOf, funciona igual que GetIndexOf, pero debe regresar la posición del último elemento con el valor X dado, 
en lugar del primero. Y si no hay, regresar -1.

int GetLastOf(int x); */

#include <iostream>
#include <vector>

class RawArray {
private:
  std::vector<int> arr;

public:
  RawArray() {}

  void ReadArray() {
    int size;
    std::cout << "Ingrese el tamano del arreglo: ";
    std::cin >> size;

    arr.resize(size);

    std::cout << "Ingrese los valores del arreglo separados por espacios: ";
    for (int i = 0; i < size; i++) {
      std::cin >> arr[i];
    }
  }

  int GetLastOf(int x) {
    for (int i = arr.size() - 1; i >= 0; i--) {
      if (arr[i] == x) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
  RawArray rawArray;
  rawArray.ReadArray();

  int x;
  std::cout << "Ingrese el valor a buscar: ";
  std::cin >> x;

  int lastPosition = rawArray.GetLastOf(x);

  if (lastPosition != -1) {
    std::cout << "El último elemento con valor " << x << " se encuentra en la posicion " << lastPosition << std::endl;
  } else {
    std::cout << "No se encontró ningún elemento con valor " << x << std::endl;
  }

  return 0;
}