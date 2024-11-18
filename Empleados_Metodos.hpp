#ifndef Empleados_Metodos_h
#define Empleados_Metodos_h

#include <fstream>
#include "Empleado.hpp"

class Empleado_Metodos{
	public:
	explicit Empleado_Metodos();
	~Empleado_Metodos();
	void Listar_empleados();
	void Anadir_empleados();
	void Quitar_empleados();
	void Mostrar_informacion_empleados();
	void Modificar_informacion_empleados();
	void Determinar_tamano();
	void Llenar();
	void Guardar();

	private:
	std::ifstream LECTURA;
	std::ofstream ESCRITURA;
	Complemento comp;
	int size;
	Empleado* Lista_Empleados;
};
#endif