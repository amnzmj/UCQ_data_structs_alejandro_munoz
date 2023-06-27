#pragma once



// Clase para entender la base de c�mo hacer nuestras estructuras de datos
// espec�ficamente la vamos a hacer para ints
// no podemos usar los [] nosotros, porque lo que queremos es simular ese comportamiento a trav�s del 
// uso de punteros.
class RawArray
{
public:
	RawArray(int in_Size);

	~RawArray();

	void Init(int InitialValue = 0);

	void Print();

	// Ojo, AddElement lo a�ade al final.
	void AddElement(int value);

	void RemoveLastElement();

	static RawArray SumArrays(RawArray A, RawArray B)
	{
		RawArray newArray = RawArray(A.Size + B.Size);

		// Falta m�s c�digo.

		return newArray;
	}

	//void Asignar(int valor, int posicion);

	/*void Reemplazar(int posicion, int valor)
	{
	
	}*/

	// puntero a la primera direcci�n de los N enteros continuos en memoria
	int* InitialElement;  // es decir, es el elemento '0' de un Array[0]
	// int* auxPosition = InitialElement;
	// InitialElement++;  // nos mueve 4 bytes en memoria
	// si auxPosition est� apuntando a x1, y luego hacemos auxPosition++
	// al hacer auxPosition++ una vez m�s nos llevar�a al tercer elemento

	int Size;

	// int myArray[5] = {0};
	// x1, x2, x3, x4, x5
	/*
	x1 -> 0-4,
	x2 -> 5-8,
	x3 -> 9-12,
	x4 -> 13-16,
	x5 -> 17-20
	*/
	// myArray[3] = 90;

};

