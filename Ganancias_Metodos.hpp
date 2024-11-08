#ifndef Ganancias_Metodos_h
#define Ganancias_Metodos_h

#include <fstream>
#include "Ganancias.hpp"

class Ganancias_Metodos {
	public:

	explicit Ganancias_Metodos();
	void Sumar_utilidad(Ganancias d, int M);
	void Modificar_utilidades(int M);
	void Mostrar_utilidades(int M);
	
	private:
	std::ifstream READ;
	std::ofstream WRITE;
	Complemento complm;
	Ganancias Dia1_G;
	Ganancias Dia2_G;
	Ganancias Dia3_G;
	Ganancias* Lista_Ganancias;
};
#endif