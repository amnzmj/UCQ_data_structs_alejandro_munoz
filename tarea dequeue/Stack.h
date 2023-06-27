#pragma once

#include <iostream>

template <typename T>
class Stack
{
private:
	// Las dejas como privadas para que no sea tan f�cil para usuarios inexpertos modificarlas sin saber.
	T* InitialElement; // Tal cual los datos que estamos guardando en la Stack.
	int _size; // cu�ntos elementos puede tener antes de llenarse (overflow)
	int _top;  // cu�ntos elementos tiene ahorita

	bool _isDynamic;

public:
	Stack(int size, bool isDynamic=true) : _size(size), _isDynamic(isDynamic)
	{
		InitialElement = new T[_size];
		_top = 0;
	}

	~Stack()
	{
		std::cout << "entrada destructor de Stack" << '\n';
		delete[] InitialElement;
		std::cout << "salida destructor de Stack" << '\n';
	}


	// Funci�n que a�ade un elemento hasta arriba de la pila
	void Push(T ElementToPush)
	{
		if (_size == _top)
		{
			if (_isDynamic == true)
			{
				// Pedir m�s memoria
				T* AuxPointer = new T[_size * 2];
				// dato cultural, el tama�o por defecto de las estructuras de datos es una potencia de 2, por ejemplo 128
				// Copiar lo de la vieja memoria a esta nueva memoria
				for (int i = 0; i < _size; i++)
				{
					AuxPointer[i] = InitialElement[i];
				}

				// borrar la memoria vieja
				delete[] InitialElement;
				// cambiar a d�nde apunta InitialElement
				InitialElement = AuxPointer;
				_size = _size * 2; // _size *= 2; es lo mismo

				// lo podr�amos a�adir aqu�, pero al pensar bien las ramificaciones de la ejecuci�n, nos lo podemos ahorrar.
				// InitialElement[_top] = ElementToPush;
				// _top++; // incrementamos el tope en una unidad (_top++; es lo mismo que _top = _top + 1;)
			}
			else 
			{
				// esto ser�a un error de Overflow
				std::cout << "Error de Overflow" << '\n';
				return;
			}
		}

		// si no, lo metemos hasta el tope de la pila, y lo hacemos el nuevo top
		InitialElement[_top] = ElementToPush;
		_top++; // incrementamos el tope en una unidad (_top++; es lo mismo que _top = _top + 1;)

	}

	// Quita el elemento del tope de la Pila.
	void Pop()
	{
		if (IsEmpty())  // este de aqu� no le importa si tu stack es din�mica o no, siempre es un error
		{
			// Error, underflow, que es: quieres quitar elementos donde no hay.
			std::cout << "Error de Underflow" << '\n';
			return;
		}

		// Comparar si vamos a un cuarto (1/4) de la capacidad de nuestra stack
		if (_isDynamic == true && _top <= _size / 4)
		{
			// Entonces hacemos un resize para no gastar memoria.

			// Pedir m�s memoria, pero m�s chica, solo la mitad de la capacidad actual
			// PENDIENTE, HACER EL REDONDEO PARA LOS N�MEROS IMPARES
			T* AuxPointer = new T[_size / 2];

			// Copiar lo de la vieja memoria a esta nueva memoria
			// OJO: a�qu� usamos _top en vez de _size para ahorrar operaciones.
			for (int i = 0; i < _top; i++)
			{
				AuxPointer[i] = InitialElement[i];
			}

			// borrar la memoria vieja
			delete[] InitialElement;
			// cambiar a d�nde apunta InitialElement
			InitialElement = AuxPointer;
			_size = _size / 2; // _size /= 2; es lo mismo			
		}
		
		// Podr�amos poner en 0 este elemento, pero no es necesario, porque el _top nos dice 
		// que ya no lo leamos o tomemos en cuenta, y cuando se a�ada algo nuevo, se sobreescribir�.
		// InitialElement[_top-1] = NULL; 
		_top--;
	}

	bool IsEmpty()
	{
		if (_top == 0)
		{
			return true;
		}
		// Aqu� no puse el "else" porque con el return true; de arriba se saldr�a de la funci�n.
		return false;
	}

	// Funci�n que nos permite leer el elemento al tope de la Pila.
	T Top()
	{
		if (IsEmpty())
			return NULL;

		return InitialElement[_top - 1];
	}

	// Imprimir
	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			std::cout<< InitialElement[i] << ", ";
		}
		std::cout << '\n';

	}

	// Funci�n Resize
};

