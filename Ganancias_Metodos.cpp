#include <iostream>
#include "Ganancias_Metodos.hpp"

Ganancias_Metodos::Ganancias_Metodos()
	{         
		complm;
		size = 0;
		Lista_Ganancias = nullptr;
	}

void Ganancias_Metodos::Sumar_utilidad()
	{
		int ganancia_t, perdidas_t, utilidad_t;
		
		Ganancias *Lista_temp = new Ganancias[size+1];
		
		for (int i=0; i<size; i++)
		{
			Lista_temp[i] = Lista_Ganancias[i];
		}
		
		delete [] Lista_Ganancias;
		
		Lista_temp[size].Set_DMY();
		std::cout << "\n\n";
		
		std::cout << "Cuantas ganancias hay?" << "\n\n";
		std::cin >> ganancia_t;
		Lista_temp[size].Set_ganancia(ganancia_t);
		std::cout << "\n\n";
		
		std::cout << "Cuantas perdidas hay?" << "\n\n";
		std::cin >> perdidas_t;
		Lista_temp[size].Set_perdidas(perdidas_t);
		std::cout << "\n\n";
		
		utilidad_t = ganancia_t-perdidas_t;
		Lista_temp[size].Set_utilidad(utilidad_t);
	
		
		Lista_Ganancias = new Ganancias[size+1];
		
		for (int i=0; i<size+1; i++)
		{
			Lista_Ganancias[i] = Lista_temp[i];
		}
		
		delete [] Lista_temp;
		
		size++;
		
		Guardar();
	}

void Ganancias_Metodos::Modificar_utilidades()
	{
		if (Lista_Ganancias[0].Get_ganancia() != -1)
		{
			int ganancia_t, perdidas_t, utilidad_t;
			bool Existe = 0;
			Fecha DMY_t;
			
			std::cout << "Escribe la fecha que quieras modificar" << std::endl;
			std::cin >> DMY_t;
			
			for (int i=0; i<size; i++)
			{
				
				if (Lista_Ganancias[i].Get_DMY() == DMY_t)
				{
					Existe = 1;
					
					std::cout << "Que cantidad de ganancia quieres sobreponer?" << std::endl;
					std::cout << "\n\n";
					std::cin >> ganancia_t;
					std::cout << "\n\n";
					Lista_Ganancias[i].Set_ganancia(ganancia_t);
					
					std::cout << "Que cantidad de perdidas quieres sobreponer?" << std::endl;
					std::cout << "\n\n";
					std::cin >> perdidas_t;
					std::cout << "\n\n";
					Lista_Ganancias[i].Set_perdidas(perdidas_t);
					
					utilidad_t = ganancia_t - perdidas_t;
					Lista_Ganancias[i].Set_utilidad(utilidad_t);
					
					break;
				}
			}
			
			if (Existe == 0)
			{
				std::cout << "No se encontró el día" << std::endl;
			}
			
			Guardar();
		}
		else
		{
			std::cout << "No hay ganancias para modificar" << std::endl;
		}
	}

void Ganancias_Metodos::Mostrar_utilidades()
	{
		if (Lista_Ganancias[0].Get_ganancia() != -1)
		{
			Fecha DMY_min;
			Fecha DMY_max;
			
			std::cout << "Desde que fecha quieres mostrar las utilidades? | (Pon 00/00/0000 para empezar desde el inicio)" << "\n\n";
			std::cin >> DMY_min;
			
			do
			{
				std::cout << "Hasta que fecha quieres mostrar las utilidades? | (Pon 00/00/3000 para llegar hasta el final)" << "\n\n";
				std::cin >> DMY_max;
			} while (DMY_min > DMY_max);
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Ganancias[i].Get_DMY() >= DMY_min && DMY_max >= Lista_Ganancias[i].Get_DMY())
				{
					std::cout << "Fecha :";
					std::cout << Lista_Ganancias[i].Get_DMY() << std::endl;
					std::cout << "Ganancias :";
					std::cout << Lista_Ganancias[i].Get_ganancia() << std::endl;
					std::cout << "Perdidas :";
					std::cout << Lista_Ganancias[i].Get_perdidas() << std::endl;
					std::cout << "Utilidad :";
					std::cout << Lista_Ganancias[i].Get_utilidad() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay ninguna ganancia para mostrar" << std::endl;
		}
	}

void Ganancias_Metodos::Determinar_tamano()
	{
		WRITE.open("Ganancias.txt", std::ios::app);
		READ.open("Ganancias.txt");
		
		if (complm.Contenido_archivo(READ))
		{
			READ >> size;
			Lista_Ganancias = new Ganancias[size];
			WRITE.close();
			READ.close();
			Llenar();
		}
		else
		{
			size = 0;
			Lista_Ganancias = new Ganancias[1];
			WRITE.close();
			READ.close();
		}
	}

void Ganancias_Metodos::Llenar()
	{
		READ.open("Ganancias.txt");
		
		int dia_t, mes_t, year_t, ganancia_t, perdidas_t, util_t;
		char *nombre_t = new char[15];
		char *espacio_t = new char[5];
		
		READ >> nombre_t >> espacio_t >> nombre_t >> espacio_t >> nombre_t >> espacio_t >> nombre_t;
		
		READ >> size;
		
		for (int i=0; i<size; i++)
		{
			READ >> dia_t;
			READ >> espacio_t;
			
			READ >> mes_t;
			READ >> espacio_t;
			
			READ >> year_t;
			READ >> espacio_t;
			
			READ >> ganancia_t;
			READ >> espacio_t;
			
			READ >> perdidas_t;
			READ >> espacio_t;
			
			READ >> util_t;
			
			Lista_Ganancias[i].Set_DMY(dia_t, mes_t, year_t);	
			Lista_Ganancias[i].Set_ganancia(ganancia_t);
			Lista_Ganancias[i].Set_perdidas(perdidas_t);
			Lista_Ganancias[i].Set_utilidad(util_t);
		}
		
		READ.close();
	}
	
void Ganancias_Metodos::Guardar()
	{
		READ.open("Ganancias.txt");
		WRITE.open("Ganancias_temp.txt", std::ios::app);
		
		WRITE << "Fecha  ->  Ganancia ->  Perdidas ->  Utilidad" << "\n\n";
		
		WRITE << size << "\n\n";

		for (int i=0; i<size; i++)
		{
			WRITE << Lista_Ganancias[i].Get_DMY() << " | ";
			WRITE << Lista_Ganancias[i].Get_ganancia() << " | ";
			WRITE << Lista_Ganancias[i].Get_perdidas() << " | ";
			WRITE << Lista_Ganancias[i].Get_utilidad() << "\n\n";
		}

		WRITE.close();
		READ.close();
		
		std::remove("Ganancias.txt");
		std::rename("Ganancias_temp.txt", "Ganancias.txt");
	}

