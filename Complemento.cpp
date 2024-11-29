#include "Complemento.hpp"
#include <iostream>

void Copiar_Puntero(char *&x, char *&b, int c)
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
	
int Longitud_Puntero(char *&x)
	{
		if (x == nullptr) 
		{
        	std::cerr << "Error: Puntero nulo. Longitud no válida." << std::endl;
        	return 0;
    	}

   	 	int longitud = 0;
    	while (x[longitud] != '\0') 
		{
        	longitud++;
		}
    	return longitud;
	}

void Memoria_justa_cadena(char *&x, int capacidad, char *llenar)
	{

		if (capacidad <= 0) 
		{
			std::cout << "Error: Capacidad no válida." << std::endl;
			return;
		}

		if (llenar != nullptr) 
		{
			delete[] llenar; 
		}

		char* temporal = new char[capacidad + 1];
		int size = 0;

		if (llenar == nullptr) 
		{
			std::cin.ignore();
			std::cin.getline(temporal, capacidad + 1, '\n');
			
			size = Longitud_Puntero(temporal);
			
			x = new char[size + 1];

			Copiar_Puntero(temporal, x, size);
		} 
		else 
		{
			size = Longitud_Puntero(llenar);
			x = new char[size + 1];
			Copiar_Puntero(llenar , x, size);
		}
	}

bool Comparar_Punteros(const char* ptr1, const char* ptr2, int longitud) 
	{
		if (ptr1 == nullptr || ptr2 == nullptr) 
		{
			std::cerr << "Error: Uno o ambos punteros son nulos. No se pueden comparar." << std::endl;
			return false;
		}

		for (int i = 0; i < longitud; i++) {
			if (ptr1[i] != ptr2[i]) {
				return false; //Diferentes
			}
		}

		return true; //Iguales
	}

void Borrar_Asignar_ptr(char *&x)
	{
		if (x != nullptr)
		{
			delete [] x;
			x = nullptr;
		}
	}

bool Contenido_archivo(std::ifstream &file)
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

void Convertir_mayusculas_minusculas(char &x, bool y)
	{
		if (y)  //Convertir minúscula
		{
			if (x >= 'A' && x <= 'Z')  
			{
				x = x + ('a' - 'A');  
			}
		}
		else  //Convertir mayúscula
		{
			if (x >= 'a' && x <= 'z')  
			{
				x = x - ('a' - 'A');  
			}
		}
	}

	