#include <iostream>
#include "Empleado.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Empleado::Empleado() : Persona()
	{
		Email = nullptr;
		Direccion = nullptr;
		Salario = -1;
		Edad = -1;
	}

Empleado::~Empleado()
	{
		if (Email != nullptr)
		{
			delete [] Email;
		}
		if (Direccion != nullptr)
		{
			delete [] Direccion;
		}
	}
	
void Empleado::Set_Contrato(int d, int m, int y)
	{
		if (d != 0 && m != 0 && y != 0)
		{
			Contrato.Set_dia(d);
			Contrato.Set_mes(m);
			Contrato.Set_year(y);
		}
		else
		{
			std::cin >> Contrato;
		}
	}
	
void Empleado::Set_Nacimiento(int d, int m, int y)
	{
		if (d != 0 && m != 0 && y != 0)
		{
			Nacimiento.Set_dia(d);
			Nacimiento.Set_mes(m);
			Nacimiento.Set_year(y);
		}
		else
		{
			std::cin >> Nacimiento;
		}
	}

void Empleado::Set_email(Complemento c)
	{
		c.Borrar_Asignar_ptr(Email);
		
		c.Set_Complemento_temp(60);
			
		c.Memoria_justa_cadena(Email, 60, nullptr);

		c.Set_Complemento_size(0);
	}

void Empleado::Set_email(Complemento c, char*& llenar)
	{
		c.Borrar_Asignar_ptr(Email);
		
		c.Set_Complemento_temp(60);
		
		c.Memoria_justa_cadena(Email, 60, llenar);

		c.Set_Complemento_size(0);
	}

void Empleado::Set_direccion(Complemento c)
	{
		c.Borrar_Asignar_ptr(Direccion);
		
		c.Set_Complemento_temp(60);
			
		c.Memoria_justa_cadena(Direccion, 60, nullptr);

		c.Set_Complemento_size(0);
	}

void Empleado::Set_direccion(Complemento c, char*& llenar)
	{
		c.Borrar_Asignar_ptr(Direccion);
		
		c.Set_Complemento_temp(60);
		
		c.Memoria_justa_cadena(Direccion, 60, llenar);

		c.Set_Complemento_size(0);
	}
	
void Empleado::Set_salario(float s)
	{
		std::cout << "Si llega";
		Salario = s;
	}

void Empleado::Set_edad(int e)
	{
		Edad = e;
	}
	
char* Empleado::Get_email() const
	{
		return Email;
	}

char* Empleado::Get_direccion() const
	{
		return Direccion;
	}

float Empleado::Get_salario() const
	{
		return Salario;
	}

int Empleado::Get_edad() const
	{
		return Edad;
	}
	
Fecha& Empleado::Get_Contrato()
	{
		return Contrato;
	}
	
Fecha& Empleado::Get_Nacimiento()
	{
		return Nacimiento;
	}

Empleado& Empleado::operator=(Empleado& E)
	{
		Complemento p;
		
		p.Set_Complemento_temp(60);
		p.Memoria_justa_cadena(nombre, 60, E.Get_nombre());
		p.Set_Complemento_size(0);
		
		this->telefono = E.Get_telefono();
		
		this->DNI = E.Get_dni();
		
		p.Set_Complemento_temp(60);
		p.Memoria_justa_cadena(Email, 60, E.Get_email());
		p.Set_Complemento_size(0);
		
		p.Set_Complemento_temp(60);
		p.Memoria_justa_cadena(Direccion, 60, E.Get_direccion());
		p.Set_Complemento_size(0);
		
		this->Salario = E.Get_salario();
		
		this->Contrato = E.Get_Contrato();
		
		this->Nacimiento = E.Get_Nacimiento();
		
		this->Edad = E.Get_edad();
		
		return *this;
	}
