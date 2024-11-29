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
Vehiculo::Vehiculo(Vehiculo& other)
	{
		if (other.marcaAuto != nullptr)
		{
			int size = Longitud_Puntero(other.marcaAuto);
			marcaAuto = new char[size + 1];
			Copiar_Puntero(marcaAuto, other.marcaAuto, size);
		}
		else
		{
			marcaAuto = nullptr;
		}

		if (other.placa != nullptr)
		{
			int size = Longitud_Puntero(other.placa);
			placa = new char[size + 1];
			Copiar_Puntero(placa, other.placa, size);
		}
		else
		{
			placa = nullptr;
		}

		if (other.color != nullptr)
		{
			int size = Longitud_Puntero(other.color);
			color = new char[size + 1];
			Copiar_Puntero(color, other.color, size);
		}
		else
		{
			color = nullptr;
		}

		if (other.estado != nullptr)
		{
			int size = Longitud_Puntero(other.estado);
			estado = new char[size + 1];
			Copiar_Puntero(estado, other.estado, size);
		}
		else
		{
			estado = nullptr;
		}
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
		Memoria_justa_cadena(placa, 8, llenarplaca);
	}

void Vehiculo::setColor(char *llenarcolor)
	{
		Borrar_Asignar_ptr(color);
		Memoria_justa_cadena(color, 15, llenarcolor);
	}

void Vehiculo::setEstado(char *llenarestado)
	{
		Borrar_Asignar_ptr(estado);
		Memoria_justa_cadena(estado, 11, llenarestado);
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

void Vehiculo:: mostrarInformacion() const
	{
		std::cout << "Marca: " << marcaAuto << ", Placa: " << placa
                  << ", Color: " << color << ", Estado: " << estado << std::endl;
	}