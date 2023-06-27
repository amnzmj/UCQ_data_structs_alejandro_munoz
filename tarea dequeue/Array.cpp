#include "Array.h"

#include <iostream>

// int myArray[5]

// POD = Plain Old Data, por ejemplo: int, float, bool, etc.
// NO-POD: objetos de clases y structs definidos por usuarios.

RawArray::RawArray(int in_Size): Size(in_Size)
{
	// Size = in_Size;
	// estoy pidiendo espacio en memoria igual a n ints, donde n = Size.
	InitialElement = new int[Size];

	// Internamente "new int[Size]" har�a:
	// InitialElement = new int;
	// int* auxPosition = InitialElement;
	// for (int i = 0; i < Size; i++)
	// {
	// 	 auxPosition++;
	// 	 auxPosition = new int;
	// }
}

RawArray::~RawArray()
{
	std::cout << "entrada destructor de RawArray" << '\n';
	// Hay que liberar la memoria din�mica
	delete[] InitialElement;
	/*int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		int* toDelete = auxPosition;
		delete toDelete;
		auxPosition++;
	}*/
	std::cout << "salida destructor de RawArray" << '\n';
}

// Asignamos el mismo valor InitialValue a todas las posiciones de nuestro arreglo
void RawArray::Init(int InitialValue)
{
	int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		*auxPosition = InitialValue;
		auxPosition++;
	}
}  // El return nos manda autom�ticamente hasta fuera del Scope de la funci�n en que est�s.
// al llegar ac�, se manda llamar el destructor de TODAS las variables (est�ticas) 
// que solo viven en ese scope.

void RawArray::Print()
{
	int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		std::cout<<*auxPosition << ", ";
		auxPosition++;
	}
	std::cout << '\n';
}


void RawArray::AddElement(int value)
{
	// Primero que nada, mantener una referencia a nuestros valores originales del arreglo que aumentar� su tama�o
	// Si no mantenemos referencia a esos valores originales, no podr�amos copiarlos al nuevo arreglo, ni liberar esa memoria.
	int* auxPointer = InitialElement;  // auxPointer ahora apunta a al primer elemento de [0, 1, 2]

	InitialElement = new int[Size + 1]; // esto nos va a dar [basura, basura, basura, basura]

	// Ahora, hay que copiar los elementos del arreglo antes de que se aumentara el tama�o, a las posiciones donde apunta InitialElement
	for (int i = 0; i < Size; i++)
	{
		InitialElement[i] = auxPointer[i];
	}
	// Despu�s de esto ya tendr�amos [0, 0, 0, basura]
	// AQU� TODAV�A FALTA ALGO, �QU� ES?

	// 1) Debi� haber impreso el 4to elemento que se agreg�. CORREGIDO.
	// �por qu� ahorita no lo imprimi�? -> porque nos faltaba a�adir ese +1 al Size de nuestro RawArray
	Size = Size + 1; // Size++;

	// 2) Nos falta tal cual agregar ese "value" pasado a la funci�n, a nuestro RawArray
	InitialElement[Size - 1] = value; // Debe ir en la �ltima posici�n del arreglo.

	// Todav�a falta una cosa m�s!
	// Borrar la memoria din�mica que ya no nos es �til
	delete[] auxPointer; // Esto va a borrar el arreglo "original" (el de tama�o m�s chico) porque ya no es �til.
}

void RawArray::RemoveLastElement()
{
	int* auxPointer = InitialElement; // Una asignaci�n, solo 1 operaci�n

	Size = Size - 1;  // 1 operaci�n
	InitialElement = new int[Size]; // 1 operaci�n, PERO, tiene 'n' extra de memoria.

	// en este momento en que pedimos esta memoria, est� usando Size + (Size-1) de memoria.
	// 1,000,000 + 999,999 = 1,999,999, casi Size*2 de memoria.

	// este ciclo for se ejecutar� Size veces
	// como solo tiene 1 operaci�n dentro, el total de este for ser� Size*x operaciones.
	for (int i = 0; i < Size; i++)
	{
		InitialElement[i] = auxPointer[i]; // 1 operaci�n
	}

	// Podr�amos decir que tiene una complejidad de Size operaciones, y 2*Size memoria

	delete[] auxPointer;
}


