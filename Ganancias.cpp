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
		
		WRITE << "Dia N: " << dia << "   -   " << "Utilidad: " << util << "\n\n";
		
		READ.close();
		WRITE.close();
		
		delete [] temp;
	}

void Ganancias::Modificar_utilidades()
	{
		temp = new char[30];
		
		READ.open("Ganancias.txt");
		WRITE.open("Ganancias_remp.txt", std::ios::app);
		
		std::cout << "Pon el dia que quieres modificar sus ganancias" << "\n\n";
		std::cin >> temp;
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
			READ >> dia;
			READ >> util;
			
			if (temp == dia)
			{
				std::cout << "Quieres modificar la utilidad -> s (si) o n (no)" << "\n\n";
				std::cin >> confirmacion;
				if (confirmacion == 's')
				{
					std::cout << "\n\n";
					std::cin >> util;
					std::cout << "\n\n";
				}
				
				WRITE << "Dia N: " << dia << "   -   " << "Utilidad: " << util << "\n\n";
				
				incremento++;
			}
			else
			{
				if (temporal != dia)
				{
					WRITE << "Dia N: " << dia << "   -   " << "Utilidad: " << util << "\n\n";
				}
			}
		}
		if (incremento == 0)
		{
			std::cout << "No se encontro el dia pedido" << "\n\n";
		}
		
		WRITE.close();
		READ.close();
		
		std::remove("Ganancias.txt");
		std::rename("Ganancias_remp.txt", "Ganancias.txt");
		
		delete [] temp;
		temp = nullptr;
	}

void Ganancias::Mostrar_utilidades()
	{
		temp = new char[10];
		
		READ.open("Ganancias.txt");
		
		while (!READ.eof())
		{
			READ >> temp;
			READ >> util;
			std::cout << "Dia N: " << temp << "   -   " << "Utilidad: " << util << "\n\n";

		}
		
		READ.close();
		delete [] temp;
		temp = nullptr;
	}
