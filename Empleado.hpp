#ifndef Empleados_h
#define Empleados_h

#include "Complemento.hpp"

class Empleados{
	public:
	explicit Empleados();
	~Empleados();
	void Set_nombre(Complemento c, char* llenar);
	char *Get_nombre();
	void Set_correo(Complemento c, char* llenar);
	char *Get_correo();
	void Set_telefono(int i);
	int Get_telefono();
	void Set_dni(int i);
	int Get_dni();
	Empleados& operator=(Empleados& E);

	private:
	char *nombre;
	char *correo;
	int telefono;
	int DNI;
};
#endif