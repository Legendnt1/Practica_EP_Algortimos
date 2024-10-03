#pragma once
#include<sstream>
using namespace std;
template<class T>
class Prestamo
{
private:
	T codigo_prestamo;
	T cliente;
	T monto;
	T fecha;
public:
	Prestamo(T p_codigo_prestamo, T p_cliente, T p_monto, T p_fecha)
	{
		this->codigo_prestamo = p_codigo_prestamo;
		this->cliente = p_cliente;
		this->monto = p_monto;
		this->fecha = p_fecha;
	}
	~Prestamo(){}

	T getCodigoPrestamo() { return this->codigo_prestamo; }
	T getCliente() { return this->cliente; }
	T getMonto() { return this->monto; }
	T getFecha() { return this->fecha; }

	void setCodigoPrestamo(T p_codigo_prestamo) { this->codigo_prestamo = p_codigo_prestamo; }
	void setCliente(T p_cliente) { this->cliente = p_cliente; }
	void setMonto(T p_monto) { this->monto = p_monto; }
	void setFecha(T p_fecha) { this->fecha = p_fecha; }

	string toString()
	{
		stringstream ss;
		ss << "Codigo prestamo: " << this->codigo_prestamo << "\n";
		ss << "Cliente: " << this->cliente << "\n";
		ss << "Monto: " << this->monto << "\n";
		ss << "Fecha: " << this->fecha << "\n";
		return ss.str();
	}
};
