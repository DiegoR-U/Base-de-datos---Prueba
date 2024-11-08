#include <iostream>
#include "Ganancias_Metodos.hpp"

Ganancias_Metodos::Ganancias_Metodos()
	{         
		complm;
		Dia1_G;
		Dia2_G;
		Dia3_G;
		Lista_Ganancias = new Ganancias[3];
	}

void Ganancias_Metodos::Sumar_utilidad(Ganancias d, int M)
	{
		int ganancia_t, perdidas_t, utilidad_t;

		std::cout << "Que dia es?" << "\n\n";
		d.Set_dia(complm, nullptr);
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
	}

void Ganancias_Metodos::Modificar_utilidades(int M)
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

void Ganancias_Metodos::Mostrar_utilidades(int M)
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
	}
	
void Ganancias_Metodos::Llenar(int M)
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
			
			Lista_Ganancias[i].Set_dia(complm, dia_t);	
			Lista_Ganancias[i].Set_ganancia(ganancia_t);
			Lista_Ganancias[i].Set_perdidas(perdidas_t);
			Lista_Ganancias[i].Set_utilidad(util_t);
		}
		
		delete [] dia_t;
		
		READ.close();
	}
	
void Ganancias_Metodos::Guardar(int M)
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

