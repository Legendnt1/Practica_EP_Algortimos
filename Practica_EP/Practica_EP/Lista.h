#pragma once
#include "Nodo.h"
#include <functional>
typedef unsigned int uint;
template<class T>
class Lista
{
private:
	Nodo<T>* nodo;
	Nodo<T>* ini;
	//typedef function<int(T, T)> Comp;
	uint lon;

public:
	Lista() : ini(nullptr), lon(0)
	{
		nodo = new Nodo<T>();
	}
	~Lista() {}

	Lista(Nodo<T>* pNodo)
	{
		nodo = pNodo;
	}
	uint longitud()
	{
		return lon;
	}

	bool esVacia()
	{
		return lon == 0;
	}
	void agregarInicial(T elem)
	{
		Nodo<T>* nuevo = new Nodo<T>(elem);
		if (nuevo != nullptr)
		{
			ini = nuevo;
			lon++;
		}
	}

	T buscar(T elem)
	{
		Nodo<T>* aux = ini;
		while (aux != nullptr)
		{
			if (Comp(aux->elem, elem) == 0)
			{
				return aux->elem;
			}
		}
		return 0;
	}

	void agregarPos(T elem, uint pos)
	{
		if (pos > lon)return;
		if (pos == 0)
		{
			agregarInicial(elem);
		}
		else
		{
			Nodo<T>* aux = ini;
			for (uint i = 1; i < pos; i++)
			{
				aux = aux->get_Sgte();
			}
			Nodo<T>* nuevo = new Nodo<T>(elem);
			nuevo->set_Sgte(aux->get_Sgte());
			if (nuevo != nullptr)
			{
				aux->set_Sgte(nuevo);
				lon++;
			}
		}
	}

	void agregarFinal(T elem)
	{
		agregarPos(elem, lon);
	}

	void eliminarInicial()
	{
		if (lon > 0)
		{
			Nodo<T>* aux = ini;
			ini = ini->sgte;
			delete aux;
			lon--;
		}
	}

	void eliminarPos(uint pos)
	{
		if (pos > lon)return;
		if (pos == 0)
		{
			eliminarInicial();
		}
		else
		{
			Nodo<T>* aux = ini;
			for (uint i = 1; i < pos; i++)
			{
				aux = aux->get_Sgte();
			}
			Nodo<T>* eliminar = aux->get_Sgte();
			aux->set_Sgte(eliminar->get_Sgte());
			delete eliminar;
			lon--;
		}
	}

	void eliminarFinal()
	{
		eliminarPos(lon - 1);
	}

	void modificarInicial(T elem)
	{
		if (lon > 0)
		{
			ini->elem = elem;
		}

	}

	void moficarPos(T elem, uint pos)
	{
		if (pos >= 0 && pos < lon)
		{
			Nodo<T>* aux = ini;
			for (int i = 0; i < pos; i++)
			{
				aux = aux->sgte;
			}
			aux->elem = elem;
		}
	}

	void modificarFinal(T elem)
	{
		moficarPos(elem, lon - 1);
	}

	T obtenerInicial()
	{
		if (lon > 0)
		{
			obtenerPos(0);
		}
		return 0;

	}

	T obtenerPos(uint pos)
	{
		if (pos >= 0 && pos < lon)
		{
			Nodo<T>* aux = ini;
			for (uint i = 0; i < pos; i++)
			{
				aux = aux->sgte;
			}
			return aux->elem;
		}
		else
		{
			return nullptr;
		}
	}

	T obtnenerFinal()
	{
		return obtenerPos(lon - 1);
	}

	void agregar(T d)
	{
		Nodo<T>* nuevo = new Nodo<T>(d);
		nuevo->set_Sgte(nodo);
		nodo = nueov;
	}

};
