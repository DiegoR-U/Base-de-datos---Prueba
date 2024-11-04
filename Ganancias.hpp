#ifndef Ganancias_h
#define Ganancias_h

#include <fstream>
#include "Complemento.hpp"

class Ganancias : public Complemento{
	public:

	explicit Ganancias();
	void Sumar_utilidad();
	void Modificar_utilidades();
	void Mostrar_utilidades();
	
	private:
	std::ifstream READ;
	std::ofstream WRITE;
	Complemento comp;
	int ganancia;
	int perdidas;
	char *dia;
};
#endif