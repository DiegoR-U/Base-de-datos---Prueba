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
		
		std::cout << "Que dia es?" << "\n\n";
		Lista_temp[size].Set_dia(complm, nullptr);
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
			char* dia_t = nullptr;
			char* dia_t2 = nullptr;
			int ganancia_t, perdidas_t, utilidad_t;
			
			dia_t = new char[11];
			dia_t2 = new char[11];
			bool Existe = 0;
			
			std::cout << "Escribe el dia que quieras modificar" << std::endl;
			std::cin >> dia_t;
			
			for (int i=0; i<size; i++)
			{
				dia_t2 = Lista_Ganancias[i].Get_dia();
				
				if (complm.Comparar_Punteros(dia_t, dia_t2, 11) && Existe==0)
				{
					Existe = 1;
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
	
					Lista_Ganancias[i].Set_utilidad(utilidad_t);
				}
			}
			
			if (Existe == 0)
			{
				std::cout << "No se encontró el día" << std::endl;
			}
			
			delete [] dia_t;
			delete [] dia_t2;
			
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
			char* Fecha_min = new char[11];
			char* Fecha_max = new char[11];
			
			std::cout << "Desde que fecha quieres mostrar las utilidades? | (Pon 00/00/0000 para empezar desde el inicio)" << "\n\n";
			std::cin >> Fecha_min;
			
			do
			{
			std::cout << "Hasta que fecha quieres mostrar las utilidades? | (Pon 00/00/3000 para llegar hasta el final)" << "\n\n";
			std::cin >> Fecha_max;
			} while (complm.Fechas_mayor(Fecha_min, Fecha_max));
			
			for (int i=0; i<size; i++)
			{
				if (complm.Fechas_mayor(Lista_Ganancias[i].Get_dia(), Fecha_min) && complm.Fechas_mayor(Fecha_max, Lista_Ganancias[i].Get_dia()))
				{
					std::cout << "Dia :";
					std::cout << Lista_Ganancias[i].Get_dia() << std::endl;
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
		
		int ganancia_t = 0;
		int perdidas_t = 0;
		int util_t = 0;
		char *dia_t = new char[11];
		
		READ >> size;
		
		for (int i=0; i<size; i++)
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
	
void Ganancias_Metodos::Guardar()
	{
		READ.open("Ganancias.txt");
		WRITE.open("Ganancias_temp.txt", std::ios::app);
		
		WRITE << size << "\n\n";

		for (int i=0; i<size; i++)
		{
			WRITE << Lista_Ganancias[i].Get_dia() << std::endl;
			WRITE << Lista_Ganancias[i].Get_ganancia() << std::endl;
			WRITE << Lista_Ganancias[i].Get_perdidas() << std::endl;
			WRITE << Lista_Ganancias[i].Get_utilidad() << "\n\n";
		}

		WRITE.close();
		READ.close();
		
		std::remove("Ganancias.txt");
		std::rename("Ganancias_temp.txt", "Ganancias.txt");
	}

