#include "Complemento.hpp"
#include <iostream>

Complemento::Complemento()
	{         
		temporal = nullptr;
		size = 0;
	}

Complemento::~Complemento()
	{
		if (temporal != nullptr)
			delete [] temporal;
	}
	
void Complemento::Set_Complemento_temp(int c)
	{
		temporal = new char[c];
	}
	
void Complemento::Set_Complemento_size(int s)
	{
		size = s;
	}
	
int Complemento::Get_Complemento_size() const
	{	
		return size;
	}

void Complemento::Copiar_Puntero(char *&x, char *&b, int c)
	{
		if (x != nullptr && b != nullptr)
		{
			for (int i=0; i < c+1; i++)
			{
				*(b+i) = *(x+i);
			}
		}
		else
		{
			std::cout << "No se puede copiar con un puntero vacio" << std::endl;
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
		else
		{
			std::cout << "No se puede hallar la longitud de un puntero vacio" << std::endl;
		}
		
		return longitud;
	}

void Complemento::Memoria_justa_cadena(char *&x, int c, char *llenar)
	{

		if (llenar == nullptr)
		{
			std::cin.ignore();				//importante poner antes de un getline
			std::cin.getline(temporal, c);
			
			size = Longitud_Puntero(temporal);
			
			x = new char[size+1];
		
			Copiar_Puntero(temporal, x, size);
		}
		else
		{
			size = Longitud_Puntero(llenar);
			
			x = new char[size+1];
			
			Copiar_Puntero(llenar, x, size);
		}
	}

bool Complemento::Comparar_Punteros(char *&x, char *&b, int c)
	{
		if (x != nullptr && b != nullptr)
		{
			int verificador = 0;
			
			for (int i=0; i<c+1; i++)
			{
				if (*(x+i) == *(b+i))
					verificador++;
			}
			
			if (verificador == c+1)
				return 1;				//SON IGUALES
			else
				return 0;				//SON DIFERENTES
		}
		else
		{
			std::cout << "Antes inicialice ambos punteros para compararlos" << std::endl;
			return 0;
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

bool Complemento::Contenido_archivo(std::ifstream &file)
	{
		file.seekg(0, std::ios::end);  
		if (file.tellg() < 1)				//EL ARCHIVO NO TIENE NI 1 LETRA
		{
			file.clear();					//REINICIA LAS OPERACIONES EN EL ARCHIVO
			file.seekg(0, std::ios::beg);		//DEVUELVE EL PUNTERO AL INICIO
			return 0;
		}		
		else								//EL ARCHIVO TIENE CONTENIDO
		{
			file.clear();
			file.seekg(0, std::ios::beg);
			return 1;
		}
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

	