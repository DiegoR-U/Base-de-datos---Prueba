#include <iostream>
#include <fstream>

class Ganancias{
	public:

	explicit Ganancias();
	void Sumar_utilidad();
	void Modificar_utilidades();
	void Mostrar_utilidades();
	
	private:
	std::ifstream READ;
	std::ofstream WRITE;
	int ganancia;
	int perdidas;
	int util;
	int incremento;
	char *dia;
	char *temp;
	char confirmacion;
};
