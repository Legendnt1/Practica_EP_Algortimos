#pragma once
#include"Prestamo.h"
#include"Cliente.h"
#include"Lista.h"
#include"Cola.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<stack>
using namespace std;


class Banco
{
private:
	//Listas de clientes
	Lista<Cliente<string>*>* l_clientes;
	//Lista de Prestamos
	Lista<Prestamo<string>*>* l_prestamos;

	//Colas auxiliares
	Cola<string>* c_nombres;
	Cola<string>* c_apellidos;
	Cola<string>* c_estados_civiles;
	Cola<string>* c_tipos_clientes;

	int n_clientes;
public:
	Banco()
	{
		l_clientes = new Lista<Cliente<string>*>();
		l_prestamos = new Lista<Prestamo<string>*>();
		n_clientes = 0;

		//Lista de nombres
		c_nombres = new Cola<string>();
		c_nombres->encolar("Juan");
		c_nombres->encolar("Maria");
		c_nombres->encolar("Pedro");
		c_nombres->encolar("Ana");

		
		//Lista de apellidos
		c_apellidos = new Cola<string>();
		c_apellidos->encolar("Perez");
		c_apellidos->encolar("Gomez");
		c_apellidos->encolar("Gonzalez");
		c_apellidos->encolar("Lopez");

		//Lista de estados civiles
		c_estados_civiles = new Cola<string>();
		c_estados_civiles->encolar("S");
		c_estados_civiles->encolar("C");
		c_estados_civiles->encolar("V");

		//Lista de tipos de clientes
		c_tipos_clientes = new Cola<string>();
		c_tipos_clientes->encolar("N");
		c_tipos_clientes->encolar("V");
		c_tipos_clientes->encolar("P");
		c_tipos_clientes->encolar("O");
	}

	~Banco()
	{
		delete l_clientes;
		delete l_prestamos;
		delete c_nombres;
		delete c_apellidos;
		delete c_estados_civiles;
		delete c_tipos_clientes;
	}

	void menu()
	{
		srand(time(NULL));
		int opcion;
		while (true)
		{
			cout << "\n============MENU===========\n";
			cout << "<1>Ingresar el numero de clientes\n";
			cout << "<2>Generar los clientes y prestamos\n";
			cout << "<3>Eliminar Prestamo\n";
			cout << "<4>Ingresar los clientes y prestamos a los archivos de texto\n";
			cout << "<5>Salir\n";
			cout << "Ingresar opcion: "; cin >> opcion;
			if (opcion == 5) break;
			switch (opcion)
			{
			case 1:
				ingresarNClientes();
				break;
			case 2:
				generarClientes();
				break;
			case 3:
				eliminarPrestamo();
			case 4:
				ingresarClienteArchivo();
				break;
			}
		}
	}
	void ingresarNClientes()
	{
		while (true)
		{
			cout << "\nIngresar el numero de clientes <10:100>: "; cin >> n_clientes;
			if (n_clientes > 10 && n_clientes < 100)
			{
				break;
			}
			else
			{
				cout << "\nNumero fuera del rango!\n";
			}
		}
	}
	void generarClientes()
	{
		//Clientes
		string codigo, nombre, apellido, sexo, estado_civil, tipo_cliente;
		//Prestamos
		string codigo_prestamo, monto, fecha;

		if (n_clientes != 0)
		{
			for (int i = 0; i < this->n_clientes; i++)
			{
				//indices
				int inombre = rand() % (c_nombres->getSize());
				int iapellido = rand() % (c_apellidos->getSize());
				int iestado_civil = rand() % (c_estados_civiles->getSize());
				int itipo_cliente = rand() % (c_tipos_clientes->getSize());

				//Datos de los clientes
				codigo = "C" + to_string(i + 1);
				nombre = c_nombres->obtenerPos(inombre);
				apellido = c_apellidos->obtenerPos(iapellido);
				if (nombre == "Maria" || nombre == "Ana")
				{
					sexo = "F";
				}
				else
				{
					sexo = "M";
				}
				estado_civil = c_estados_civiles->obtenerPos(iestado_civil);
				tipo_cliente = c_tipos_clientes->obtenerPos(itipo_cliente);

				//Datos de los prestamos
				codigo_prestamo = "P" + to_string(i + 1);
				monto = to_string(rand() % 1000 + 500);
				fecha = "01/10/2024";

				//Ingresando los clientes y prestamos
				l_clientes->agregarPos(new Cliente<string>(codigo, nombre, apellido, sexo, estado_civil, tipo_cliente), i);
				l_prestamos->agregarPos(new Prestamo<string>(codigo_prestamo, nombre, monto, fecha), i);
			}
		}
		else
		{
			cout << "\nNo ingresaste un numero de clientes!\n";
		}
	}

	void eliminarPrestamo()
	{
		if (l_prestamos->longitud() != 0)
		{
			string codigo_prestamo;
			bool encontrado = false;
			cout << "\nIngresar el codigo del prestamo a eliminar: "; cin >> codigo_prestamo;
			for (int i = 0; i < l_prestamos->longitud(); i++)
			{
				if (l_prestamos->obtenerPos(i)->getCodigoPrestamo() == codigo_prestamo)
				{
					l_prestamos->eliminarPos(i);
					encontrado = true;
					break;
				}
			}
			if (encontrado)
				cout << "\nSe elimino el prestamo!\n";
			else
				cout << "\nNo se encontro el prestamo!\n";
		}
		else
		{
			cout << "\nNo hay prestamos!\n";
		}
	}

	void ingresarClienteArchivo()
	{
		if (l_clientes->longitud() != 0 || l_prestamos->longitud() != 0)
		{
			ofstream archivo("Clientes.txt", ios::out);
			if (archivo.is_open())
			{
				for (int i = 0; i < l_clientes->longitud(); i++)
				{
					archivo << l_clientes->obtenerPos(i)->toString();
					archivo << "\n--------------------------------\n";
				}
				archivo.close();
			}
			else
			{
				cout << "\nNo se pudo abrir el archivo!\n";
			}

			ofstream archivo2("Prestamos.txt", ios::out);
			if (archivo2.is_open())
			{
				for (int i = 0; i < l_prestamos->longitud(); i++)
				{
					archivo2 << l_prestamos->obtenerPos(i)->toString();
					archivo2 << "\n--------------------------------\n";
				}

				archivo2.close();
			}
			else
			{
				cout << "\nNo se pudo abrir el archivo!\n";
			}
		}
		else
		{
			cout << "\nNo hay clientes y Reclamos!\n";
		}
	}
};