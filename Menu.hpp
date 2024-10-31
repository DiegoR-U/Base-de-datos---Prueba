#include <iostream>

class Menu_de_inicio : public Empleados, public Ganancias {
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