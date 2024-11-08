#ifndef Ganancias_h
#define Ganancias_h

#include "Complemento.hpp"

class Ganancias {
	public:
	explicit Ganancias();
	~Ganancias();
	void Set_dia(Complemento c, char* llenar);
	char *Get_dia();
	void Set_ganancia(int i);
	int Get_ganancia();
	void Set_perdidas(int i);
	int Get_perdidas();
	void Set_utilidad(int i);
	int Get_utilidad();

	
	private:
	int ganancia;
	int perdidas;
	int util;
	char *dia;
};
#endif