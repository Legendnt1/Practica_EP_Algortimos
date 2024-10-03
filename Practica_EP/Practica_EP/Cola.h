#pragma once
#include"Nodo.h"
#include<iostream>
using namespace std;

template<class T>
class Cola
{
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Cola()
	{
		inicio = NULL;
		fin = NULL;
	}

	~Cola(){}



	bool esVacia()
	{
		return inicio == NULL;
	}
	
	void encolar(T v)
	{
		Nodo<T>* nodo = new Nodo<T>(v);
		if (esVacia())
		{
			inicio = nodo;
			fin = inicio;
		}
		else
		{
			fin->sgte = nodo;
			fin = nodo;
		}
		nodo = NULL;
	}

	T desencolar()
	{
		T dato = inicio->elem;
		if (inicio == fin)
		{
			inicio = NULL;
			fin = NULL;
		}
		else
		{
			inicio = inicio->sgte;
		}
		return dato;
	}

	int getSize()
	{
		int cont = 0;
		Nodo<T>* aux = inicio;
		while (aux != NULL)
		{
			cont++;
			aux = aux->sgte;
		}
		return cont;
	}

    T obtenerPos(int pos)
    {
        if (pos < 0 || pos >= getSize())
        {
			return NULL;
        }

        Nodo<T>* aux = inicio;
        for (int i = 0; i < pos; i++)
        {
            aux = aux->sgte;
        }

        return aux->elem;
    }
};
