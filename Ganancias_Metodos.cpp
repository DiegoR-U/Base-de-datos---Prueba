#include <iostream>
#include "Ganancias.hpp"

Ganancias::Ganancias()
	{         
		complm;
		Dia1_G;
		Dia2_G;
		Dia3_G;
		Lista_Ganancias = new Ganancias[3];
	}

void Ganancias::Sumar_utilidad(Ganancias d, int M)
	{
		int ganancia_t, perdidas_t, utilidad_t;

		std::cout << "Que dia es?" << "\n\n";
		d.Set_dia(comp, nullptr);
		std::cout << "\n\n";
		
		std::cout << "Cuantas ganancias hay?" << "\n\n";
		std::cin >> ganancia_t;
		d.Set_ganancia(ganancia_t);
		std::cout << "\n\n";
		
		std::cout << "Cuantas perdidas hay?" << "\n\n";
		std::cin >> perdidas_t;
		d.Set_perdidas(perdidas_t);
		std::cout << "\n\n";
		
		utilidad_t = ganancia_t-perdidas_t;
		d.Set_utilidad(utilidad_t);
		std::cout << "\n\n";
		
		Ganancias *Lista_temp = new Ganancias[M+1];
		
		for (int i=0; i<M; i++)
		{
			Lista_temp[i] = Lista_Ganancias[i];
		}
		
		delete [] Lista_Ganancias;
		Lista_temp[M] = d;
		Lista_Ganancias = new Ganancias[M+1];
		
		for (int i=0; i<M+1; i++)
		{
			Lista_Ganancias[i] = Lista_temp[i];
		}
		
		delete [] Lista_temp;
		
		Guardar(M+1);
		
		
		READ.open("Utilidades.txt");
		WRITE.open("Utilidades.txt", std::ios::app);
		
		std::cout << "Que dia es?" << "\n\n";
		comp.Set_Complemento_temp(15);
		comp.Memoria_justa_cadena(dia, 15, nullptr);
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

void Ganancias::Modificar_utilidades(int M)
	{
		char* dia_t = nullptr;
		char* dia_t2 = nullptr;
		int ganancia_t, perdidas_t, utilidad_t;
		
		dia_t = new char[11];
		dia_t2 = new char[11];
		
		std::cout << "Escribe el dia que quieras modificar" << std::endl;
		std::cin >> dia_t;
		
		for (int i=0; i<M; i++)
		{
			dia_t2 = Lista_Ganancias[i].Get_dia();
			
			if (complm.Comparar_Punteros(dia_t, dia_t2, 11))
			{
				std::cout << "Que cantidad de ganancia quieres sobreponer?" << std::endl;
				std::cout << "\n\n";
				std::cin >> ganancia_t;
				std::cout << "\n\n";
				Lista_Ganancias[i].Set_ganancia(ganancia_t);
				
				std::cout << "Que cantidad de ganancia quieres sobreponer?" << std::endl;
				std::cout << "\n\n";
				std::cin >> perdidas_t;
				std::cout << "\n\n";
				Lista_Ganancias[i].Set_perdidas(perdidas_t);
				
				utilidad_t = ganancia_t - perdidas_t;
				std::cout << "\n\n";
				Lista_Ganancias[i].Set_utilidad(utilidad_t);
			}
		}
		
		delete [] dia_t;
		delete [] dia_t2;
	}

void Ganancias::Mostrar_utilidades(int M)
	{
		for (int i=0; i<M; i++)
		{
			std::cout << "Dia :";
			std::cout << Lista_Ganancias[i].Get_dia() << std::endl;
			std::cout << "Ganancias :";
			std::cout << Lista_Ganancias[i].Get_ganancia() << std::endl;
			std::cout << "Perdidas :";
			std::cout << Lista_Ganancias[i].Get_perdidas() << std::endl;
			std::cout << "Utilidad :";
			std::cout << Lista_Ganancias[i].Get_utilidad() << std::endl;
		}
		
		
		
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
	
void Ganancias::Llenar(int M)
	{
		Lista_Ganancias[0] = Dia1_G;
		Lista_Ganancias[1] = Dia2_G;
		Lista_Ganancias[2] = Dia3_G;

		READ.open("Ganancias.txt");
		
		int ganancia_t = 0;
		int perdidas_t = 0;
		int util_t = 0;
		char *dia_t = new char[11];
		
		for (int i=0; i<M; i++)
		{
			READ >> dia_t;
			READ >> ganancia_t;
			READ >> perdidas_t;
			READ >> util_t;
			
			Lista_Ganancias[i].Set_dia(comp, dia_t);	
			Lista_Ganancias[i].Set_ganancia(ganancia_t);
			Lista_Ganancias[i].Set_perdidas(perdidas_t);
			Lista_Ganancias[i].Set_utilidad(util_t);
		}
		
		delete [] dia_t;
		
		READ.close();
	}
	
void Ganancias::Guardar(int M)
	{
		READ.open("Ganancias.txt");
		WRITE.open("Ganancias_temp.txt", std::ios::app);

		for (int i=0; i<M; i++)
		{
			WRITE << Lista_Ganancias[i].Get_dia() << std::endl;
			WRITE << Lista_Ganancias[i].Get_ganancia() << std::endl;
			WRITE << Lista_Ganancias[i].Get_perdidas() << std::endl;
			WRITE << Lista_Ganancias[i].Get_utilidad() << "\n\n";
		}

		WRITE.close();
		READ.close();
		
		std::remove("Ganancias.txt");
		std::rename("Ganancias.txt", "Ganancias.txt");
	}

