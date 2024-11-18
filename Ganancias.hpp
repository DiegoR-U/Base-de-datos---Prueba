#ifndef Ganancias_h
#define Ganancias_h

#include "Complemento.hpp"
#include "Fecha.hpp"

class Ganancias {
	public:
	explicit Ganancias();
	void Set_ganancia(int i);
	int Get_ganancia() const;
	void Set_perdidas(int i);
	int Get_perdidas() const;
	void Set_utilidad(int i);
	int Get_utilidad() const;
	void Set_DMY(int d=0, int m=0, int y=0);
	Fecha& Get_DMY();
	Ganancias& operator=(Ganancias& G);

	
	private:
	int ganancia;
	int perdidas;
	int util;
	Fecha DMY;
};
#endif