#include <iostream>
#include "Ganancias.hpp"

Ganancias::Ganancias()
	{
		dia = nullptr;
		ganancias = -1;
		perdidas = 1;
	}

Ganancias::~Ganancias()
	{
		if (dia != nullptr)
		{
			delete [] dia;
		}
	}

void Empleados::Set_dia(Complemento c, char* llenar)
	{
		if (dia != nullptr)
		{
			delete [] dia;
			dia = nullptr;
		}
		c.Set_Complemento_temp(11);
		if (llenar == nullptr)
		{
			c.Memoria_justa_cadena(dia, 11, nullptr);
		}
		else
		{
			c.Memoria_justa_cadena(dia, 11, llenar);
		}
		c.Set_Complemento_size(0);
	}

char* Empleados::Get_dia()
	{
		return dia;
	}

void Empleados::Set_ganancia(int i)
	{
		ganancia = i;
	}

int Empleados::Get_ganancia()
	{
		return ganancia;
	}

void Empleados::Set_perdidas(int i)
	{
		perdidas = i;
	}

int Empleados::Get_perdidas()
	{
		return perdidas;
	}

void Empleados::Set_utilidad(int i)
	{
		utilidad = i;
	}

int Empleados::Get_utilidad()
	{
		return utilidad;
	}


