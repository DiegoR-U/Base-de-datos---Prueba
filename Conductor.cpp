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

void Conductor::Set_licencia()
	{
		Borrar_Asignar_ptr(Numero_licencia);	
		Memoria_justa_cadena(Numero_licencia, 11, nullptr);
	}
	
void Conductor::Set_licencia(char*& llenar)
	{
		Borrar_Asignar_ptr(Numero_licencia);
		Memoria_justa_cadena(Numero_licencia, 11, llenar);

	}

void Conductor::Set_nivel()
	{
		Borrar_Asignar_ptr(Nivel);
		Memoria_justa_cadena(Nivel, 3, nullptr);
	}

void Conductor::Set_nivel(char*& llenar)
	{
		Borrar_Asignar_ptr(Nivel);
		Memoria_justa_cadena(Nivel, 3, llenar);
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
		Memoria_justa_cadena(nombre, 60, C.Get_nombre());
		
		this->telefono = C.Get_telefono();
		
		this->DNI = C.Get_dni();

		Memoria_justa_cadena(Email, 60, C.Get_email());
		Memoria_justa_cadena(Direccion, 60, C.Get_direccion());

		this->Salario = C.Get_salario();
		
		this->Contrato = C.Get_Contrato();
		
		this->Nacimiento = C.Get_Nacimiento();
		
		this->Edad = C.Get_edad();
		
		Memoria_justa_cadena(Numero_licencia, 11, C.Get_licencia());
		Memoria_justa_cadena(Nivel, 3, C.Get_nivel());
		
		this->Vencimiento = C.Get_vencimiento();
		
		return *this;
	}
