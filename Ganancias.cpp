#include <iostream>
#include "Ganancias.hpp"

Ganancias::Ganancias()
	{
		ganancia = -1;
		perdidas = -1;
		util = 0;
	}

void Ganancias::Set_ganancia(int i)
	{
		ganancia = i;
	}

int Ganancias::Get_ganancia() const
	{
		return ganancia;
	}

void Ganancias::Set_perdidas(int i)
	{
		perdidas = i;
	}

int Ganancias::Get_perdidas() const
	{
		return perdidas;
	}

void Ganancias::Set_utilidad(int i)
	{
		util = i;
	}

int Ganancias::Get_utilidad() const
	{
		return util;
	}

void Ganancias::Set_DMY(int d, int m, int y)
	{
		if (d != 0 && m != 0 && y != 0)
		{
			DMY.Set_dia(d);
			DMY.Set_mes(m);
			DMY.Set_year(y);
		}
		else
		{
			std::cin >> DMY;
		}
	}

Fecha& Ganancias::Get_DMY()
	{
		return DMY;
	}

Ganancias& Ganancias::operator=(Ganancias& G)
	{
		this->DMY = G.Get_DMY();
		this->ganancia = G.Get_ganancia();
		this->perdidas = G.Get_perdidas();
		this->util = G.Get_utilidad();
		
		return *this;
	}


