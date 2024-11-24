#ifndef Empleado_h
#define Empleado_h

#include "Complemento.hpp"
#include "Fecha.hpp"
#include "Persona.hpp"

class Empleado : public Persona{
	public:
	explicit Empleado();
	~Empleado();
	void Set_Contrato(int d=0, int m=0, int y=0);
	void Set_Nacimiento(int d=0, int m=0, int y=0);
	void Set_email();
	void Set_email(char*& llenar);
	void Set_direccion();
	void Set_direccion(char*& llenar);
	void Set_salario(float s);
	void Set_edad(int e);
	Fecha& Get_Contrato();
	Fecha& Get_Nacimiento();
	char *Get_email() const;
	char *Get_direccion() const;
	float Get_salario() const;
	int Get_edad() const;
	Empleado& operator=(Empleado& E);

	protected:
	Fecha Contrato;
	Fecha Nacimiento;
	char *Email;
	char *Direccion;
	float Salario;
	int Edad;
};
#endif