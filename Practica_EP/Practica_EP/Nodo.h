#pragma once
template <class T>
class Nodo
{
public:
	//propiedades o atributos
	T elem;
	Nodo* sgte;
	//Constructores
	Nodo()
	{
		sgte = nullptr;
	}
	Nodo(T pelem)
	{
		elem = pelem;
		sgte = nullptr;
	}

	//Métodos Setter / Getter
	void set_Elem(T pelem)
	{
		elem = pelem;
	}
	T get_Elem()
	{
		return elem;
	}
	void set_Sgte(Nodo* pSgte)
	{
		sgte = pSgte;
	}
	Nodo* get_Sgte()
	{
		return sgte;
	}

	//Métodos de Servicio
	bool es_vacio()
	{
		return sgte == NULL;
	}

};