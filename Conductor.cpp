#include <iostream>
#include "Conductor.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Conductor::Conductor() : Empleado()
	{
		Numero_licencia = nullptr;
		Nivel = nullptr;
	}

Conductor::~Conductor()
	{
		if (Numero_licencia != nullptr)
		{
			delete [] Numero_licencia;
		}
		if (Nivel != nullptr)
		{
			delete [] Nivel;
		}
	}

void Conductor::Set_licencia(Complemento c)
	{
		c.Borrar_Asignar_ptr(Numero_licencia);
		
		c.Set_Complemento_temp(11);
			
		c.Memoria_justa_cadena(Numero_licencia, 11, nullptr);

		c.Set_Complemento_size(0);
	}
	
void Conductor::Set_licencia(Complemento c, char*& llenar)
	{
		c.Borrar_Asignar_ptr(Numero_licencia);
		
		c.Set_Complemento_temp(11);
		
		c.Memoria_justa_cadena(Numero_licencia, 11, llenar);

		c.Set_Complemento_size(0);
	}

void Conductor::Set_nivel(Complemento c)
	{
		c.Borrar_Asignar_ptr(Nivel);
		
		c.Set_Complemento_temp(3);
			
		c.Memoria_justa_cadena(Nivel, 3, nullptr);

		c.Set_Complemento_size(0);
	}

void Conductor::Set_nivel(Complemento c, char*& llenar)
	{
		c.Borrar_Asignar_ptr(Nivel);
		
		c.Set_Complemento_temp(3);
		
		c.Memoria_justa_cadena(Nivel, 3, llenar);

		c.Set_Complemento_size(0);
	}
	
void Conductor::Set_vencimiento(int d, int m, int y)
	{
		if (d != 0 && m != 0 && y != 0)
		{
			Vencimiento.Set_dia(d);
			Vencimiento.Set_mes(m);
			Vencimiento.Set_year(y);
		}
		else
		{
			std::cin >> Vencimiento;
		}
	}
	
char* Conductor::Get_licencia()
	{
		return Numero_licencia;
	}
	
char* Conductor::Get_nivel()
	{
		return Nivel;
	}
	
Fecha& Conductor::Get_vencimiento()
	{
		return Vencimiento;
	}

Conductor& Conductor::operator=(Conductor& C)
	{
		Complemento p;
	
		p.Set_Complemento_temp(60);
		p.Memoria_justa_cadena(nombre, 60, C.Get_nombre());
		p.Set_Complemento_size(0);
		
		this->telefono = C.Get_telefono();
		
		this->DNI = C.Get_dni();
		
		p.Set_Complemento_temp(60);
		p.Memoria_justa_cadena(Email, 60, C.Get_email());
		p.Set_Complemento_size(0);
		
		p.Set_Complemento_temp(60);
		p.Memoria_justa_cadena(Direccion, 60, C.Get_direccion());
		p.Set_Complemento_size(0);
		
		this->Salario = C.Get_salario();
		
		this->Contrato = C.Get_Contrato();
		
		this->Nacimiento = C.Get_Nacimiento();
		
		this->Edad = C.Get_edad();
		
		p.Set_Complemento_temp(11);
		p.Memoria_justa_cadena(Numero_licencia, 11, C.Get_licencia());
		p.Set_Complemento_size(0);
		
		p.Set_Complemento_temp(3);
		p.Memoria_justa_cadena(Nivel, 3, C.Get_nivel());
		p.Set_Complemento_size(0);
		
		this->Vencimiento = C.Get_vencimiento();
		
		return *this;
	}
