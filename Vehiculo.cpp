#include "Vehiculo.hpp"
#include "Complemento.hpp"
#include <iostream>

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

Vehiculo::Vehiculo()
	{
		marcaAuto = nullptr;
		placa = nullptr;
		color = nullptr;
		estado = nullptr;
	}
Vehiculo& Vehiculo::operator=(Vehiculo& o)
	{
		if( this != &o)
		{
			Memoria_justa_cadena(marcaAuto, 20, o.getMarca());
			Memoria_justa_cadena(placa, 20, o.getPlaca());
			Memoria_justa_cadena(color, 20, o.getColor());
			Memoria_justa_cadena(estado, 20, o.getEstado());
		}
		return *this;
	}
	
Vehiculo::~Vehiculo()
	{
		if (marcaAuto != nullptr)
			delete [] marcaAuto;
		if (placa != nullptr)
			delete [] placa;
		if (color != nullptr)
			delete [] color;
		if (estado != nullptr)
			delete [] estado;
	}

void Vehiculo::setMarca(char *llenarmarca)
	{
		Borrar_Asignar_ptr(marcaAuto);
		Memoria_justa_cadena(marcaAuto, 20, llenarmarca);
		
	}

void Vehiculo::setPlaca(char *llenarplaca)
	{
		Borrar_Asignar_ptr(placa);
		Memoria_justa_cadena(placa, 8, nullptr);
	}

void Vehiculo::setColor(char *llenarcolor)
	{
		Borrar_Asignar_ptr(color);
		Memoria_justa_cadena(color, 15, nullptr);
	}

void Vehiculo::setEstado(char *llenarestado)
	{
		Borrar_Asignar_ptr(estado);
		Memoria_justa_cadena(estado, 11, nullptr);
	}

char* Vehiculo::getMarca()
	{
		return marcaAuto;
	}

char* Vehiculo::getPlaca()
	{
		return placa;
	}

char* Vehiculo::getEstado()
	{
		return estado;
	}

char* Vehiculo::getColor()
	{
		return color;
	}