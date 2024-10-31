#include <iostream>
#include <fstream>
#include "Ganancias.hpp"

Ganancias::Ganancias()
	{         
		ganancia = 0;
		perdidas = 0;
		util = 0;
		incremento = 0;
		dia = nullptr;
		temp = nullptr;
	}

void Ganancias::Sumar_utilidad()
	{
		temp = new char[30];
		
		READ.open("Utilidades.txt");
		WRITE.open("Utilidades.txt", std::ios::app);
		
		std::cout << "Que dia es?" << "\n\n";
		
		std::cin >> temp;
		
		for (int i=0; i<30; i++)
		{
			if (*(temp+i) != '\0')
			{
				incremento++;
			}
			else
			{
				break;
			}
		}
		
		dia = new char[incremento+1];
		
		for (int i=0; i<incremento+1; i++)
		{
			*(dia+i) = *(temp+i);
		}
		
		std::cout << "Que ganancias obtuviste?" << "\n\n";
		std::cin >> ganancia;
		std::cout << "\n\n";
		
		std::cout << "Que perdidas obtuviste?" << "\n\n";
		std::cin >> perdidas;
		std::cout << "\n\n";
		
		util = ganancia-perdidas;
		
		WRITE << dia << "\n"; 
		WRITE << util << "\n\n";
		
		READ.close();
		WRITE.close();
		
		delete [] temp;
	}

void Ganancias::Modificar_utilidades()
	{
		temp = new char[30];
		
		READ.open("Utilidades.txt");
		WRITE.open("Utilidades_temp.txt", std::ios::app);
		
		std::cout << "Pon el dia que quieres modificar sus ganancias" << "\n\n";
		std::cin >> ganancia;
		std::cout << "\n\n";
		
		for (int i=0; i<30; i++)
		{
			if (*(temp+i) != '\0')
			{
				incremento++;
			}
			else
			{
				break;
			}
		}
		
		dia = new char[incremento+1];
		
		while (!READ.eof())
		{
			char *temporal = new char[incremento+1];
			temporal = dia;
			READ >> perdidas;
			READ >> util;
			
			if (perdidas == ganancia)
			{
				std::cout << "Quieres modificar la utilidad -> s (si) o n (no)" << "\n\n";
				std::cin >> confirmacion;
				if (confirmacion == 's')
				{
					std::cout << "\n\n";
					std::cin >> util;
					std::cout << "\n\n";
				}
				
				WRITE << perdidas << "\n"; 
				WRITE << util << "\n\n";
				
				incremento++;
			}
			else
			{
				if (temporal != dia)
				{
					WRITE << perdidas << "\n"; 
					WRITE << util << "\n\n";
				}
			}
		}
		if (incremento == 0)
		{
			std::cout << "No se encontro el dia pedido" << "\n\n";
		}
		
		WRITE.close();
		READ.close();
		
		std::remove("Utilidades.txt");
		std::rename("Utilidades_temp.txt", "Utilidades.txt");
		
		delete [] temp;
		temp = nullptr;
	}

void Ganancias::Mostrar_utilidades()
	{
		temp = new char[10];
		
		READ.open("Utilidades.txt");
		
		while (!READ.eof())
		{
			READ >> temp >> util;
			std::cout << temp << "\n"; 
			std::cout << util << "\n\n";
		}
		
		READ.close();
		delete [] temp;
		temp = nullptr;
	}
