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

void Complemento::Convertir_mayusculas_minusculas(char &x, bool y)
	{
		if (y == 1)				//SI X ES MAYUSCULA CONVERTIRLO EN MINUSCULA
		{
			if (int(x) >= 65 && int(x) <= 90)
			{
				x = char(int(x)+32);
			}
			else {}
		}
		else						//SI X ES MINUSCULA CONVERTIRLO A MAYUSCULA
		{
			if (int(x) >= 97 && int(x) <= 122)
			{
				x = char(int(x)-32);
			}
			else {}
		}
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
			if (*(x+i) == *(b+i))
				verificador++;
		}
		
		if (verificador == c+1)
			return 1;
		else
			return 0;
	}

bool Complemento::Contenido_archivo(std::ifstream &file)
	{
		file.seekg(0, std::ios::end);  
		if (file.tellg() < 1)
		{
			file.clear();
			file.seekg(0, std::ios::beg);
			return 0;
		}		
		else
		{
			file.clear();
			file.seekg(0, std::ios::beg);
			return 1;
		}
	}

bool Complemento::Fechas_mayor(char* x, char* y)
	{
		if (x != nullptr && y != nullptr)
		{
			int dia_t = 0;
			int mes_t = 0;
			int year_t = 0;
			
			for (int i=0; i<11; i++)
			{
				switch (i)
				{
				case 0:	if (int(x[0]) > int(y[0]))
							dia_t = dia_t+5;
						else if (int(x[0]) == int(y[0]))
							dia_t = dia_t+1;
						break;
						
				case 1: if (int(x[1]) > int(y[1]))
							dia_t = dia_t+3;
						else if (int(x[1]) == int(y[1]))
							dia_t = dia_t+1;
						break;
						
				case 3: if (int(x[3]) > int(y[3]))
							mes_t = mes_t+5;
						else if (int(x[3]) == int(y[3]))
							mes_t = mes_t+1;
						break;
						
				case 4: if (int(x[4]) > int(y[4]))
							mes_t = mes_t+3;
						else if (int(x[4]) == int(y[4]))
							mes_t = mes_t+1;
						break;
				
				case 6: if (int(x[6]) > int(y[6]))
							year_t = year_t+12;
						else if (int(x[6]) == int(y[6]))
							year_t = year_t+1;
						break;
						
				case 7: if (int(x[7]) > int(y[7]))
							year_t = year_t+10;
						else if (int(x[7]) == int(y[7]))
							year_t = year_t+1;
						break;
				case 8: if (int(x[8]) > int(y[8]))
							year_t = year_t+8;
						else if (int(x[8]) == int(y[8]))
							year_t = year_t+1;
						break;
				case 9: if (int(x[9]) > int(y[9]))
							year_t = year_t+6;
						else if (int(x[9]) == int(y[9]))
							year_t = year_t+1;
						break;
				}
			}
			
			if (year_t > 4) { return 1; }
			else if (year_t == 4 && mes_t > 2) { return 1; }
			else if (year_t == 4 && mes_t == 2 && dia_t > 2) { return 1; }
			else if (year_t == 4 && mes_t == 2 && dia_t == 2) { return 1; }
			else { return 0; }
		}
		else
		{
			std::cout << "Aviso: Comparacion con objeto vacio" << std::endl;
			return 0;
		}
	}

void Complemento::Borrar_Puntero(char *&x)
	{
		if (x != nullptr)
		{
			delete [] x;
		}
	}

void Complemento::Borrar_Asignar_ptr(char *&x)
	{
		if (x != nullptr)
		{
			delete [] x;
			x = nullptr;
		}
	}

int Complemento::Longitud_Puntero(char *&x)
	{
		int longitud = 0;
		if(x != nullptr)
		{
			while ( x[longitud] != '\0' )
			{
				longitud ++;
			}
		}
		return longitud;
	}
	