#include "Vehiculo.hpp"
#include <iostream>

//Constructor
Vehiculo::Vehiculo()
	{
		marcaAuto = nullptr;
		placa = nullptr;
		color = nullptr;
		estado = nullptr;
	}
Vehiculo::Vehiculo(Vehiculo &o)
	{
		
		if (marcaAuto != nullptr)
		{
			int size = Longitud_Puntero(marcaAuto);
			marcaAuto = new char[size + 1];
			Copiar_Puntero(o.marcaAuto, marcaAuto, size);
		}

		if (placa != nullptr)
		{
			int size = Longitud_Puntero(placa);
			placa = new char[size + 1];
			Copiar_Puntero(o.placa, placa, size);
		}

		if (color != nullptr)
		{
			int size = Longitud_Puntero(color);
			color = new char[size + 1];
			Copiar_Puntero(o.color, color, size);
		}
	
		if (estado != nullptr)
		{
			int size = Longitud_Puntero(estado);
			estado = new char[size + 1];
			Copiar_Puntero(o.estado, estado, size);
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