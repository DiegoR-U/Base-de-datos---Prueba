#include <iostream>
#include "Ganancias.hpp"

Ganancias::Ganancias()
	{         
		ganancia = 0;
		perdidas = 0;
		dia = nullptr;
	}

void Ganancias::Sumar_utilidad()
	{	
		READ.open("Utilidades.txt");
		WRITE.open("Utilidades.txt", std::ios::app);
		
		std::cout << "Que dia es?" << "\n\n";
		comp.Set_Complemento_temp(15);
		comp.Memoria_justa_cadena(dia, 15);
		comp.Set_Complemento_size(0);
		std::cout << "\n\n";

		std::cout << "Que ganancias obtuviste?" << "\n\n";
		std::cin >> ganancia;
		std::cout << "\n\n";
			
		std::cout << "Que perdidas obtuviste?" << "\n\n";
		std::cin >> perdidas;
		std::cout << "\n\n";
			
		int util = ganancia-perdidas;
		
		WRITE << "Dia:" << "\n" << dia << "\n";
		WRITE << "Utilidad:" << "\n" << util << "\n\n";
		
		delete [] dia;
		
		READ.close();
		WRITE.close();
	}

void Ganancias::Modificar_utilidades()
	{
		READ.open("Utilidades.txt");
		WRITE.open("Utilidades_temp.txt", std::ios::app);
		
		bool validacion = 0;
		int longitud = 0;
		char *temp = nullptr;
		char *Dia_t = new char[5];
		char *Utilidad_t = new char[10];
		
		std::cout << "Pon el dia que quieres modificar sus ganancias" << "\n\n";
		comp.Set_Complemento_temp(15);
		comp.Memoria_justa_cadena(dia, 15);
		longitud = comp.Get_Complemento_size();
		comp.Set_Complemento_size(0);
		std::cout << "\n\n";
		
		temp = new char[longitud+1];
		
		while (!READ.eof())
		{
			READ >> Dia_t;
			READ >> temp;
			READ >> Utilidad_t;
			READ >> ganancia;
			
			if (comp.Comparar_Punteros(dia, temp, longitud))
			{
				std::cout << "Que cantidad de ganancia quieres sobreponer?" << std::endl;
				std::cout << "\n\n";
				std::cin >> ganancia;
				std::cout << "\n\n";
						
				WRITE << "Dia:" << "\n" << temp << "\n";
				WRITE << "Utilidad:" << "\n" << ganancia << "\n\n";
						
				validacion = 1;
			}
			else
			{
				WRITE << "Dia:" << "\n" << temp << "\n";
				WRITE << "Utilidad:" << "\n" << ganancia << "\n\n";
			}
		}
		if (validacion == 0)
		{
			std::cout << "No se encontro el dia pedido" << "\n\n";
		}
		
		delete [] temp;
		delete [] dia;
		delete [] Dia_t;
		delete [] Utilidad_t;
		
		WRITE.close();
		READ.close();
		
		std::remove("Utilidades.txt");
		std::rename("Utilidades_temp.txt", "Utilidades.txt");
	}

void Ganancias::Mostrar_utilidades()
	{
		READ.open("Utilidades.txt");
		
		char *Dia_t = new char[5];
		char *Utilidad_t = new char[10];
		dia = new char[11];
				
		while (!READ.eof())
		{
			READ >> Dia_t;
			READ >> dia;
			READ >> Utilidad_t;
			READ >> ganancia;
			
			std::cout << "Dia: " << dia << "\n"; 
			std::cout << "Utilidad: " << ganancia << "\n\n";
		}
		
		delete [] dia;
		delete [] Dia_t;
		delete [] Utilidad_t;
		
		READ.close();
	}

