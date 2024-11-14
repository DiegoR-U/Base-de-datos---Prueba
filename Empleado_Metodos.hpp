#ifndef Empleados_Metodos_h
#define Empleados_Metodos_h

#include <fstream>
#include "Empleado.hpp"

class Empleados_Metodos{
	public:
	explicit Empleados_Metodos();
	~Empleados_Metodos();
	void Listar_empleados();
	void Anadir_empleados();
	void Quitar_empleados();
	void Mostrar_informacion_empleado();
	void Modificar_informacion_empleado();
	void Determinar_tamano();
	void Llenar();
	void Guardar();

	private:
	std::ifstream LECTURA;
	std::ofstream ESCRITURA;
	Complemento comp;
	int size;
	Empleados* Lista_Empleados;
};
#endif