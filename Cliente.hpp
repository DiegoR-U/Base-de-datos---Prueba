#ifndef Cliente_h
#define Cliente_h

#include "Complemento.hpp"
#include "Fecha.hpp"

class Cliente{
	public:
	explicit Cliente();
	void Set_puntos(int p);
	void Set_inscripcion(int d=0, int m=0, int y=0);
	int Get_puntos() const;
	Fecha& Get_inscripcion();
	Cliente& operator=(Cliente& E);

	protected:
	Fecha Inscripcion;
	int puntos;
};
#endif