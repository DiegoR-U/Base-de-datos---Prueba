#ifndef Empleados_Metodos_h
#define Empleados_Metodos_h

#include <fstream>
#include "Empleado.hpp"

class Empleados_Metodos{
	public:
	explicit Empleados_Metodos();
	void Listar_empleados(int N);
	void Anadir_empleados(Empleados p, int N);
	void Quitar_empleados(int N);
	void Mostrar_informacion_empleado(int N);
	void Modificar_informacion_empleado(int N);
	void Llenar(int N);
	void Guardar(int N);

	private:
	std::ifstream LECTURA;
	std::ofstream ESCRITURA;
	Complemento comp;
	Empleados Persona1;
	Empleados Persona2;
	Empleados Persona3;
	Empleados Persona4;
	Empleados* Lista_Empleados;
};
#endif