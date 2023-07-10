#pragma once

#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>

template <typename T>
class ListNode
{
public:
    T data;               // Almacena los datos del nodo
    ListNode<T>* next;    // Puntero al siguiente nodo

    ListNode(T value) : data(value), next(nullptr) {}  // Constructor que inicializa los datos del nodo
};

template <typename T>
class List
{
private:
    ListNode<T>* head;    // Puntero al primer nodo de la lista

public:
    List() : head(nullptr) {}  // Constructor que inicializa la lista vac�a

    List(T* in_data, int in_size) : head(nullptr)  // Constructor que inicializa la lista con datos de un array
    {
        for (int i = 0; i < in_size; i++)
        {
            PushBack(in_data[i]);  // Agrega cada elemento del array a la lista
        }
    }

    void PushBack(T value)
    {
        ListNode<T>* newNode = new ListNode<T>(value);  // Crea un nuevo nodo con el valor especificado

        if (head == nullptr)  // Si la lista esta vacia, el nuevo nodo se convierte en el primer nodo
        {
            head = newNode;
        }
        else  // Si la lista no est� vac�a, se agrega el nuevo nodo al final
        {
            ListNode<T>* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void Print()
    {
        ListNode<T>* current = head;
        while (current != nullptr)  // Recorre la lista y muestra los elementos
        {
            std::cout << current->data;
            if (current->next != nullptr)
            {
                std::cout << ", ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    void Reverse()
    {
        ListNode<T>* prev = nullptr;
        ListNode<T>* current = head;
        ListNode<T>* next = nullptr;

        while (current != nullptr)  // Invierte el orden de los nodos en la lista
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;  
    }

    void Unique()
    {
        if (head == nullptr)
            return;

        ListNode<T>* current = head;
        while (current != nullptr && current->next != nullptr)
        {
            ListNode<T>* runner = current;
            while (runner->next != nullptr)  // Elimina los nodos duplicados en la lista
            {
                if (runner->next->data == current->data)
                {
                    ListNode<T>* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }


    ~List()
    {
        ListNode<T>* current = head;
        while (current != nullptr)  // Libera la memoria de todos los nodos de la lista
        {
            ListNode<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

#endif // OPERACIONES_H

//Referencias de las funciones:

//Nota estas referencias o fuentes solo son utilizadas por mi y el equipo para darse una idea,
//de como utilizar cada funcion y poder crear todo el codigo 
//
// void print()
// https://cplusplus.com/forum/beginner/85507/
// 
// void Reverse();
// https://www.geeksforgeeks.org/reverse-a-linked-list/
// https://cplusplus.com/reference/algorithm/reverse/
// 
// void Unique()
// https://cplusplus.com/reference/list/list/unique/
//
// List(T* in_data, int in_size)
// Nota este si tuvimos que ver muchos videos y ver otra vez la clase que tuvimos donde lo vimos 
// la siguiente pagina solo es una fuente de estructura de datos 
// https://cplusplus.com/doc/tutorial/structures/


