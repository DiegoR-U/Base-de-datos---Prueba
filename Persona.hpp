#ifndef Persona_h
#define Persona_h

#include "Complemento.hpp"

class Persona{
	public:
	explicit Persona();
	~Persona();
	void Set_nombre(Complemento c);
	void Set_nombre(Complemento c, char*& llenar);
	char *Get_nombre() const;
	void Set_telefono(int i);
	int Get_telefono() const;
	void Set_dni(int i);
	int Get_dni() const;
	Persona& operator=(Persona& E);

	protected:
	char *nombre;
	int telefono;
	int DNI;
};
#endif