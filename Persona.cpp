#include <iostream>
#include "Persona.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Persona::Persona()
	{
		nombre = nullptr;
		telefono = -1;
		DNI = -1;
	}

Persona::~Persona()
	{
		if (nombre != nullptr)
		{
			delete [] nombre;
		}
	}
void Persona::Set_nombre(Complemento c)
	{
		c.Borrar_Asignar_ptr(nombre);
		
		c.Set_Complemento_temp(60);
			
		c.Memoria_justa_cadena(nombre, 60, nullptr);

		c.Set_Complemento_size(0);
	}

void Persona::Set_nombre(Complemento c, char*& llenar)
	{
		c.Borrar_Asignar_ptr(nombre);
		
		c.Set_Complemento_temp(60);
		
		c.Memoria_justa_cadena(nombre, 60, llenar);

		c.Set_Complemento_size(0);
	}

char* Persona::Get_nombre() const
	{
		return nombre;
	}

void Persona::Set_telefono(int i)
	{
		telefono = i;
	}

int Persona::Get_telefono() const
	{
		return telefono;
	}

void Persona::Set_dni(int i)
	{
		DNI = i;
	}

int Persona::Get_dni() const
	{
		return DNI;
	}

Persona& Persona::operator=(Persona& E)
	{
		Complemento p;
		
		p.Set_Complemento_temp(60);
		p.Memoria_justa_cadena(nombre, 60, E.Get_nombre());
		p.Set_Complemento_size(0);
		
		this->telefono = E.Get_telefono();
		
		this->DNI = E.Get_dni();
		
		return *this;
	}
