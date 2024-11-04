#ifndef Empleados_h
#define Empleados_h

#include <fstream>
#include "Complemento.hpp"

class Empleados{
	public:
	
	explicit Empleados();
	void Listar_empleados();
	void Anadir_empleados();
	void Quitar_empleados();
	void Mostrar_informacion_empleado();
	void Modificar_informacion_empleado();

	private:
	std::ifstream LECTURA;
	std::ofstream ESCRITURA;
	Complemento comp;
	char *nombre;
	char *correo;
	int telefono;
	int DNI;
};
#endif