#ifndef Menu_de_inicio_h
#define Menu_de_inicio_h

#include <iostream>
#include "Ganancias_Metodos.hpp"
#include "Vehiculo.hpp"
#include "Conductor_Metodos.hpp"

class Menu_de_inicio {
	public:
	
	explicit Menu_de_inicio();
	void Mostrar_menu();
	void Menu_Empleados();
	void Menu_Clientes();
	void Menu_Vehiculos();
	void Menu_Ganancias();
	void Menu_Registro();
    void Menu_Conductores();
	void Menu_Tecnicos();
	void Menu_Supervisores();
	void Menu_Cliente_Habitual();
	void Menu_Cliente_Empresarial();
	void Salir();

	private:
	
	int Elegir_funcion;
	Conductor_Metodos ListaP;
	Ganancias_Metodos ListaG;
	Vehiculo Vehiculo1;
	/*registro Registro1;
	char prueba[100];*/
};
#endif