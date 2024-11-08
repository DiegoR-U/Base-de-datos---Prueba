#ifndef Menu_de_inicio_h
#define Menu_de_inicio_h

#include <iostream>
#include "Empleado.hpp"
#include "Ganancias.hpp"
#include "Vehiculo.hpp"

class Menu_de_inicio : public Empleados, public Ganancias, public Vehiculo {
	public:
	
	explicit Menu_de_inicio();
	void Mostrar_menu();
	void Menu_Empleados();
	void Menu_Vehiculos();
	void Menu_Ganancias();
	void Menu_Inscripcion();

	private:
	
	int Elegir_funcion;
};
#endif