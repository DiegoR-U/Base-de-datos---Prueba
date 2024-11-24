#ifndef Conductor_h
#define Conductor_h

#include "Complemento.hpp"
#include "Fecha.hpp"
#include "Empleado.hpp"

class Conductor : public Empleado{
	public:
	explicit Conductor();
	~Conductor();
	void Set_licencia();
	void Set_licencia(char*& llenar);
	void Set_nivel();
	void Set_nivel(char*& llenar);
	void Set_vencimiento(int d=0, int m=0, int y=0);
	char* Get_licencia();
	char* Get_nivel();
	Fecha& Get_vencimiento();
	Conductor& operator=(Conductor& E);

	private:
	char* Numero_licencia;
	char* Nivel;
	Fecha Vencimiento;
};
#endif