#include <iostream>
#include "Empleado.hpp"
#include "Ganancias.hpp"
#include "Menu.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif


Menu_de_inicio::Menu_de_inicio()
	{
		Elegir_funcion = 0;
	}
	
void Menu_de_inicio::Mostrar_menu()
	{
		std::cout << "                    ~~~BASE DE DATOS~~~                    " << "\n\n";
		std::cout << "1. Empleados" << "\n\n";
		std::cout << "2. Vehiculos" << "\n\n";
		std::cout << "3. Ganancias" << "\n\n";
		std::cout << "4. Inscripcion" << "\n\n";
		std::cout << "5. Salir" << "\n\n";
		
		do
		{
		std::cout << "Elige la opcion a tomar: ";
		std::cin >> Elegir_funcion;
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4 && Elegir_funcion!=5);
		
		switch (Elegir_funcion)
		{
			case 1: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Menu_Empleados();
					break;
			case 2: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Menu_Vehiculos();
					break;
			case 3: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Menu_Ganancias();
					break;
			case 4: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Menu_Inscripcion();
					break;
			case 5: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					std::cout << "Programa terminado";
					break;
			default: std::cout << "Esto nunca debio pasar";
		}
	}
	
void Menu_de_inicio::Menu_Empleados()
	{
		std::cout << "                    ~~~BASE DE DATOS - EMPLEADOS~~~                    " << "\n\n";
		std::cout << "1. Listar empleados" << "\n\n";
		std::cout << "2. Agregar empleados" << "\n\n";
		std::cout << "3. Quitar empleados" << "\n\n";
		std::cout << "4. Mostrar informacion de empleados" << "\n\n";
		std::cout << "5. Modificar informacion empleados" << "\n\n";
		std::cout << "6. Salir" << "\n\n";
		
		do
		{
		std::cout << "Elige la opcion a tomar: ";
		std::cin >> Elegir_funcion;
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4 && Elegir_funcion!=5 && Elegir_funcion!=6);
		
		switch (Elegir_funcion)
		{
			case 1: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Listar_empleados();
					break;
			case 2: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Anadir_empleados();
					break;
			case 3: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Quitar_empleados();
					break;
			case 4: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Mostrar_informacion_empleado();
					break;
			case 5: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Modificar_informacion_empleado();
					break;
			case 6: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					std::cout << "Programa terminado";
					break;
			default: std::cout << "Esto nunca debio pasar";
		}
	}

void Menu_de_inicio::Menu_Vehiculos()
	{
		std::cout << "                    ~~~BASE DE DATOS - VEHICULOS~~~                    " << "\n\n";
		std::cout << "1. Agregar ID vehiculo" << "\n\n";
		std::cout << "2. Agregar modelo" << "\n\n";
		std::cout << "3. Agregar matricula" << "\n\n";
		std::cout << "4. Estado vehiculo" << "\n\n";
		std::cout << "5. Mostrar Datos" << "\n\n";
		std::cout << "6. Salir" << "\n\n";
		
	}
	
void Menu_de_inicio::Menu_Ganancias()
	{
		std::cout << "                    ~~~BASE DE DATOS - GANANCIAS~~~                    " << "\n\n";
		std::cout << "1. Sumar utilidad" << "\n\n";
		std::cout << "2. Modificar utilidad" << "\n\n";
		std::cout << "3. Ver utilidad" << "\n\n";
		std::cout << "4. Salir" << "\n\n";
		
		do
		{
		std::cout << "Elige la opcion a tomar: ";
		std::cin >> Elegir_funcion;
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4);
		
		switch (Elegir_funcion)
		{
			case 1: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Sumar_utilidad();
					break;
			case 2: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Modificar_utilidades();
					break;
			case 3: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Mostrar_utilidades();
					break;
			case 4: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					std::cout << "Programa terminado";
					break;
			default: std::cout << "Esto nunca debio pasar";
		}
	}
	
void Menu_de_inicio::Menu_Inscripcion()
	{
		std::cout << "                    ~~~BASE DE DATOS - GANANCIAS~~~                    " << "\n\n";
		std::cout << "1. Consultar precios" << "\n\n";
		std::cout << "2. Modificar precios" << "\n\n";
		std::cout << "3. Salir" << "\n\n";
	}