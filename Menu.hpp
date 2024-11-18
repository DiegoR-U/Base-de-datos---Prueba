#ifndef Menu_de_inicio_h
#define Menu_de_inicio_h

#include <iostream>
#include "Ganancias_Metodos.hpp"
#include "Vehiculo.hpp"
#include "Persona_Metodos.hpp"

class Menu_de_inicio {
	public:
	
	explicit Menu_de_inicio();
	void Mostrar_menu();
	void Menu_Personas();
	void Menu_Vehiculos();
	void Menu_Ganancias();
	void Menu_Inscripcion();

	private:
	
	int Elegir_funcion;
	Persona_Metodos ListaP;
	Ganancias_Metodos ListaG;
	Vehiculo Vehiculo1;
	/*registro Registro1;
	char prueba[100];*/
};
#endif