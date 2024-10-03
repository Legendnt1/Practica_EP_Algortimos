#pragma once
#include<sstream>
using namespace std;
template<class T>
class Cliente
{
private:
	T codigo;
	T nombre;
	T apellido;
	T sexo;
	T estado_civil;
	T tipo_cliente;

public:
	Cliente(T p_codigo, T p_nombre, T p_apellido, T p_sexo, T p_estado_civil, T p_tipo_cliente)
	{
		this->codigo = p_codigo; this->nombre = p_nombre; this->apellido = p_apellido;
		this->sexo = p_sexo; this->estado_civil = p_estado_civil; this->tipo_cliente = p_tipo_cliente;
	}
	~Cliente(){}

	T getCodigo() { return this->codigo; }
	T getNombre() { return this->nombre; }
	T getApellido() { return this->apellido; }
	T getSexo() { return this->sexo; }
	T getEstadoCivil() { return this->estado_civil; }
	T getTipoCliente() { return this->tipo_cliente; }

	void setCodigo(T p_codigo) { this->codigo = p_codigo; }
	void setNombre(T p_nombre) { this->nombre = p_nombre; }
	void setApellido(T p_apellido) { this->apellido = p_apellido; }
	void setSexo(T p_sexo) { this->sexo = p_sexo; }
	void setEstadoCivil(T p_estado_civil) { this->estado_civil = p_estado_civil; }
	void setTipoCliente(T p_tipo_cliente) { this->tipo_cliente = p_tipo_cliente; }

	string toString()
	{
		auto datos = [] (T p_codigo, T p_nombre, T p_apellido, T p_sexo, T p_estado_civil, T p_tipo_cliente) {
			stringstream ss;
			ss << "Codigo: " << p_codigo << "\n";
			ss << "Nombre: " << p_nombre << "\n";
			ss << "Apellido: " << p_apellido << "\n";
			ss << "Sexo: " << p_sexo << "\n";
			ss << "Estado civil: " << p_estado_civil << "\n";
			ss << "Tipo cliente: " << p_tipo_cliente << "\n";
			return ss.str();
		};

		return datos(getCodigo(), getNombre(), getApellido(), getSexo(), getEstadoCivil(), getTipoCliente());
	}

};
