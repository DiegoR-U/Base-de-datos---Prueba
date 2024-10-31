//CUIDADO - NO COMPILA BIEN

#include "Vehiculo.hpp"
#include <iostream>
//Constructor
Vehiculo::Vehiculo()
{         
	id = 0;
	modelo = nullptr;
	matricula = nullptr;
	estado = nullptr;
}
//Método para agregar un nuevo auto
void agregarIDVehiculo()
{
	id++;
}
//Método para añadir el modelo del auto
void agregarModelo() 
{
	char longitudmax[50];
	int cont{0};
		
	std::cout << "Ingrese el modelo del auto: ";
	std::cin >> longitudmax;
	std::cout << std::endl;
	for(int i = 0; i<50; i++)
	{
		if(longitudmax[i] != '\0')
		{
			cont++;
		}
	}
		
	modelo = new char[cont + 1];
	for(int i = 0; i < cont + 1; i++)
	{
		*(modelo + i) = longitudmax[i];
	}
}
//Método para ingresar la placa del auto
void agregarMatricula()
{
	char placa[8];
	std::cout << "Ingrese la placa o matricula del auto: ";
	std::cin >> placa;
	std::cout << std::endl;
	
	matricula = new char[8];
	for(int i = 0; i < 8; i++)
	{
		*(matricula + i) = placa[i];
	}
}
//Método para clasificarlo como disponible o no
void estadoVehiculo()	
{
	char longitudmax[15];
	int cont{0};
		
	std::cout << "Ingrese la disponibilidad del auto: ";
	std::cin >> longitudmax;
	std::cout << std::endl;
	for(int i = 0; i<15; i++)
	{
		if(longitudmax[i] != '\0')
		{
			cont++;
		}
	}
		
	estado = new char[cont + 1];
	for(int i = 0; i < cont + 1; i++)
	{
		*(estado + i) = longitudmax[i];
	}
}
//Método para imprimir en consola
void mostrarDatos()
{
	std::cout << "ID: " << id << std::endl;
	std::cout << "Modelo: " << modelo << std::endl;
	std::cout << "Matricula: " << matricula << std::endl;
	std::cout << "Estado: " << estado << std::endl;
}
