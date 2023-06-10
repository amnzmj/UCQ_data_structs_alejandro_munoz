#include <iostream>

class RawArray {
private:
    int* arreglo;
    int size;

public:
    RawArray(int in_Size);
    void asignarValor(int posicion, int valor);
    int accederElemento(int posicion) const;
    void imprimirArreglo() const;
    void inicializarArreglo();
}; 

RawArray::RawArray(int in_Size) : size(in_Size)
{
    arreglo = new int[size];
}

void RawArray::asignarValor(int posicion, int valor)
{
    arreglo[posicion] = valor;
}

int RawArray::accederElemento(int posicion) const
{
    return arreglo[posicion]; 
    //return * (arreglo + posicion); son equivalentes 
}

void RawArray::imprimirArreglo() const
{
    std::cout << "Arreglo actualizado: ";
    int* ptr = arreglo;
    for (int i = 0; i < size; i++) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;
}

void RawArray::inicializarArreglo()
{
    int* ptr = arreglo;
    for (int i = 0; i < size; i++) {
        *(ptr + i) = i;
    }
}

int main()
{
    int size;
    std::cout << "Ingrese el tamaño del arreglo: ";
    std::cin >> size;

    RawArray rawArray(size);

    // Inicializar el arreglo con valores iniciales
    rawArray.inicializarArreglo();

    int posicion, valor;
    bool posicionValida = false;

    do {
        std::cout << "Ingrese la posicion (menor al tamaño del arreglo): ";
        std::cin >> posicion;

        if (posicion < size) {
            posicionValida = true;
        } else {
            std::cout << "Ingrese un número menor al tamaño del arreglo." << std::endl;
        }
    } while (!posicionValida);

    std::cout << "Ingrese el valor: ";
    std::cin >> valor;

    // Asignar el valor en la posición solicitada
    rawArray.asignarValor(posicion, valor);

    // Acceder al elemento en la posición solicitada
    int elemento = rawArray.accederElemento(posicion);

    // Imprimir el arreglo actualizado
    rawArray.imprimirArreglo();

    std::cout << "Elemento en la posicion " << posicion << ": " << elemento << std::endl;

    return 0;
} 