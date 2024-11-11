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
	
Empleados::Empleados()
	{
		nombre = nullptr;
		correo = nullptr;
		telefono = -1;
		DNI = -1;
	}

Empleados::~Empleados()
	{
		if (nombre != nullptr)
		{
			delete [] nombre;
		}
		if (correo != nullptr)
		{
			delete [] correo;
		}
	}

void Empleados::Set_nombre(Complemento c, char* llenar)
	{
		if (nombre != nullptr)
		{
			delete [] nombre;
			nombre = nullptr;
		}
		c.Set_Complemento_temp(15);
		if (llenar == nullptr)
		{
			c.Memoria_justa_cadena(nombre, 15, nullptr);
		}
		else
		{
			c.Memoria_justa_cadena(nombre, 15, llenar);
		}
		c.Set_Complemento_size(0);
	}

char* Empleados::Get_nombre()
	{
		return nombre;
	}

void Empleados::Set_correo(Complemento c, char* llenar)
	{
		if (correo != nullptr)
		{
			delete [] correo;
			correo = nullptr;
		}
		c.Set_Complemento_temp(50);
		if (llenar == nullptr)
		{
			c.Memoria_justa_cadena(correo, 50, nullptr);
		}
		else
		{
			c.Memoria_justa_cadena(correo, 50, llenar);
		}
		c.Set_Complemento_size(0);
	}
	
char* Empleados::Get_correo()
	{
		return correo;
	}

void Empleados::Set_telefono(int i)
	{
		telefono = i;
	}

int Empleados::Get_telefono()
	{
		return telefono;
	}

void Empleados::Set_dni(int i)
	{
		DNI = i;
	}

int Empleados::Get_dni()
	{
		return DNI;
	}

Empleados& Empleados::operator=(Empleados& E)
	{
		std::cout << "llega" << std::endl;
		Complemento p;
		p.Set_Complemento_temp(15);
		p.Memoria_justa_cadena(nombre, 15, E.Get_nombre());
		std::cout << "llega2" << std::endl;
		p.Set_Complemento_size(0);
		p.Set_Complemento_temp(50);
		p.Memoria_justa_cadena(correo, 50, E.Get_correo());
		std::cout << "llega3" << std::endl;
		p.Set_Complemento_size(0);
		telefono = E.Get_telefono();
		DNI = E.Get_dni();
		std::cout << "gg" << std::endl;
		
		return *this;
	}
