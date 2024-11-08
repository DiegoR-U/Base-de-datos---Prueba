#ifndef Menu_de_inicio_h
#define Menu_de_inicio_h

#include <iostream>
#include "Ganancias.hpp"
#include "Vehiculo.hpp"
#include "Empleado_Metodos.hpp"

class Menu_de_inicio {
	public:
	
	explicit Menu_de_inicio();
	void Mostrar_menu();
	void Menu_Empleados();
	void Menu_Vehiculos();
	void Menu_Ganancias();
	void Menu_Inscripcion();

	private:
	
	int Elegir_funcion;
	Empleados_Metodos ListaP;
	Empleados Persona5;
	Ganancias_Metodos ListaG;
	Ganancias Dia4_G;
	Vehiculo Vehiculo1;
	/*registro Registro1;
	char prueba[100];*/
};
#endif