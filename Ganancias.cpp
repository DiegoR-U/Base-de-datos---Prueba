#include <iostream>
#include "Ganancias.hpp"

Ganancias::Ganancias()
	{
		dia = nullptr;
		ganancia = -1;
		perdidas = 1;
	}

Ganancias::~Ganancias()
	{
		if (dia != nullptr)
		{
			delete [] dia;
		}
	}

void Ganancias::Set_dia(Complemento c, char* llenar)
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

char* Ganancias::Get_dia()
	{
		return dia;
	}

void Ganancias::Set_ganancia(int i)
	{
		ganancia = i;
	}

int Ganancias::Get_ganancia()
	{
		return ganancia;
	}

void Ganancias::Set_perdidas(int i)
	{
		perdidas = i;
	}

int Ganancias::Get_perdidas()
	{
		return perdidas;
	}

void Ganancias::Set_utilidad(int i)
	{
		util = i;
	}

int Ganancias::Get_utilidad()
	{
		return util;
	}


