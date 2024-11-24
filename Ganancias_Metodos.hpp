#ifndef Ganancias_Metodos_h
#define Ganancias_Metodos_h

#include <fstream>
#include "Complemento.hpp"
#include "Ganancias.hpp"

class Ganancias_Metodos {
	public:

	explicit Ganancias_Metodos();
	void Sumar_utilidad();
	void Modificar_utilidades();
	void Mostrar_utilidades();
	void Determinar_tamano();
	void Llenar();
	void Guardar();
	
	private:
	std::ifstream READ;
	std::ofstream WRITE;
	int size;
	Ganancias* Lista_Ganancias;
};
#endif