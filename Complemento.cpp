#include <iostream>
#include "Complemento.hpp"

Complemento::Complemento()
	{         
		temporal = nullptr;
		size = 0;
	}

void Complemento::Set_Complemento_temp(int c)
	{
		temporal = new char[c];
	}
	
void Complemento::Set_Complemento_size(int s)
	{
		size = s;
	}
	
int Complemento::Get_Complemento_size()
	{	
		return size;
	}
	
void Complemento::Memoria_justa_cadena(char *&x, int c, char *llenar)
	{
		if (llenar == nullptr)
		{
			std::cin>>temporal;
		}
		else
		{
			Copiar_Puntero(llenar, temporal, c);
		}

		for (int i=0; i < c; i++)
		{
			if (*(temporal+i) == '\0')
				break;
			else
				size++;
		}
		
		x = new char[size+1];
		
		for (int i=0; i < size+1; i++)
		{
			*(x+i) = *(temporal+i);
		}

		delete [] temporal;
	}

void Complemento::Copiar_Puntero(char *&x, char *&b, int c)
	{
		for (int i=0; i < c+1; i++)
		{
			*(b+i) = *(x+i);
		}
	}

bool Complemento::Comparar_Punteros(char *&x, char *&b, int c)
	{
		int verificador = 0;
		
		for (int i=0; i<c+1; i++)
		{
			if (*(x+1) == *(b+i))
				verificador++;
		}
		
		if (verificador = c+1)
			return 1;
		else
			return 0;
	}

bool Complemento::Contenido_archivo(std::ifstream &x)
	{
		x.seekg(0, std::ios::end);  
		if (x.tellg() == 0)
		{
			x.seekg(0, std::ios::beg);
			return 0;
		}		
		else
		{
			x.seekg(0, std::ios::beg);
			return 1;
		}
	}
	