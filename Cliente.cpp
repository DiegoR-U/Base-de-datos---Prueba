#include <iostream>
#include "Cliente.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Cliente::Cliente()
	{
		puntos = -1;
	}

void Cliente::Set_puntos(int p)
	{
		puntos = p;
	}

void Cliente::Set_inscripcion(int d, int m, int y)
	{
		if (d != 0 && m != 0 && y != 0)
		{
			Inscripcion.Set_dia(d);
			Inscripcion.Set_mes(m);
			Inscripcion.Set_year(y);
		}
		else
		{
			std::cin >> Inscripcion;
		}
	}

int Cliente::Get_puntos() const
	{
		return puntos;
	}
	
Fecha& Cliente::Get_inscripcion()
	{
		return Inscripcion;
	}

Cliente& Cliente::operator=(Cliente& E)
	{
		Complemento p;
		
		this->Inscripcion = E.Get_inscripcion();
		
		p.Set_Complemento_temp(60);
		p.Memoria_justa_cadena(nombre, 60, E.Get_nombre());
		p.Set_Complemento_size(0);
		
		this->telefono = E.Get_telefono();
		
		this->DNI = E.Get_dni();
		
		this->puntos = E.Get_puntos();
		
		return *this;
	}
