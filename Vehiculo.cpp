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
			int size = comprobar.Longitud_Puntero(marcaAuto);
			marcaAuto = new char[size + 1];
			comprobar.Copiar_Puntero(o.marcaAuto, marcaAuto, size);
		}

		if (placa != nullptr)
		{
			int size = comprobar.Longitud_Puntero(placa);
			placa = new char[size + 1];
			comprobar.Copiar_Puntero(o.placa, placa, size);
		}

		if (color != nullptr)
		{
			int size = comprobar.Longitud_Puntero(color);
			color = new char[size + 1];
			comprobar.Copiar_Puntero(o.color, color, size);
		}
	
		if (estado != nullptr)
		{
			int size = comprobar.Longitud_Puntero(estado);
			estado = new char[size + 1];
			comprobar.Copiar_Puntero(o.estado, estado, size);
		}

	}
	
Vehiculo::~Vehiculo()
	{
		comprobar.Borrar_Puntero(marcaAuto);
		comprobar.Borrar_Puntero(placa);
		comprobar.Borrar_Puntero(estado);
		comprobar.Borrar_Puntero(color);
	}

void Vehiculo::setMarca(Complemento c, char *llenarmarca)
	{
		c.Borrar_Asignar_ptr(marcaAuto);
		c.Set_Complemento_temp(20);
		if (llenarmarca == nullptr)
		{
			c.Memoria_justa_cadena(marcaAuto, 20, nullptr);
		}
		else
		{
			c.Memoria_justa_cadena(marcaAuto, 20, llenarmarca);
		}
	}

void Vehiculo::setPlaca(Complemento c, char *llenarplaca)
	{
		c.Borrar_Asignar_ptr(placa);
		c.Set_Complemento_temp(8);
		if (llenarplaca == nullptr)
		{
			c.Memoria_justa_cadena(placa, 8, nullptr);
		}
		else
		{
			c.Memoria_justa_cadena(placa, 8, llenarplaca);
		}
	}

void Vehiculo::setColor(Complemento c, char *llenarcolor)
	{
		c.Borrar_Asignar_ptr(color);
		c.Set_Complemento_temp(15);
		if (llenarcolor == nullptr)
		{
			c.Memoria_justa_cadena(color, 15, nullptr);
		}
		else
		{
			c.Memoria_justa_cadena(color, 15, llenarcolor);
		}
	}

void Vehiculo::setEstado(Complemento c, char *llenarestado)
	{
		c.Borrar_Asignar_ptr(estado);
		c.Set_Complemento_temp(11);
		if (llenarestado == nullptr)
		{
			c.Memoria_justa_cadena(estado, 11, nullptr);
		}
		else
		{
			c.Memoria_justa_cadena(estado, 11, llenarestado);
		}
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