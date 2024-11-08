#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

#include <iostream>
#include "Menu.hpp"

Menu_de_inicio::Menu_de_inicio()
	{
		Elegir_funcion = 0;
		Persona5;
		ListaP;
		Dia4_G;
		ListaG;
		Vehiculo1;
		/* prueba = "prueba";
		Registro1(prueba, 11, 12, 2024) */
	}
	
void Menu_de_inicio::Mostrar_menu()
	{
		//MENU PRINCIPAL
		std::cout<< "\x1b[38;5;182m";
		std::cout << "					  ......     ..     ..     ......       ..          .......      ..    ..                   " << std::endl;
		std::cout << "					  ..         ...   ...     ..    ..     ..         ..     ..     ..    ..                   " << std::endl;
		std::cout << " 					  ..         .... ....     ..    ..     ..         ..     ..      ..  ..                    " << std::endl;
		std::cout << "					  ......     ..  .  ..     ......       ..         ..     ..        ..                      " << std::endl;    
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ......     ..     ..     ..           ......      .......         ..                      " << "\n\n\n\n";
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 1. Empleados |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 2. Vehiculos |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 3. Ganancias |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 4. Formato   |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 5. Salir     |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << "\n\n\n";
		
		
		//SELECCION DE OPCION Y VALIDACION DE INFORMACION
		do
		{
			std::cout << "					                        Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4 && Elegir_funcion!=5);
		
		
		//CONDICIONAL QUE DIRIGE A LA OPCION SELECCIONADA POR EL USUARIO
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
					std::cout << "Programa terminado" << std::endl;
					break;
			default: std::cout << "Esto nunca debio pasar";
		}
	}
	
void Menu_de_inicio::Menu_Empleados()
	{
		ListaP.Llenar(4);
		
		//MENU DE EMPLEADOS - PRUEBA
		std::cout<< "\x1b[38;5;182m";
		std::cout << "					  ......     ..     ..     ......       ..          .......      ..    ..                   " << std::endl;
		std::cout << "					  ..         ...   ...     ..    ..     ..         ..     ..     ..    ..                   " << std::endl;
		std::cout << " 					  ..         .... ....     ..    ..     ..         ..     ..      ..  ..                    " << std::endl;
		std::cout << "					  ......     ..  .  ..     ......       ..         ..     ..        ..                      " << std::endl;    
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ......     ..     ..     ..           ......      .......         ..                      " << "\n\n\n\n";
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 1. Lista de emplados     |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 2. Añadir empleado       |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 3. Quitar empleado       |					                            " << std::endl;
		std::cout << "					                        --------------------------					                            " << std::endl;
		std::cout << "					                       | 4. Mostrar informacion   |				                                " << std::endl;
		std::cout << "					                        --------------------------			                                    " << std::endl;
		std::cout << "					                       | 5. Modificar informacion |					                            " << std::endl;
		std::cout << "					                        --------------------------					                            " << std::endl;
		std::cout << "					                       | 6. Salir                 |				                                " << std::endl;
		std::cout << "					                        --------------------------			                                    " << "\n\n\n";
		
		//SELECCION DE OPCION Y VALIDACION DE INFORMACION
		do
		{
			std::cout << "					                      Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4 && Elegir_funcion!=5 && Elegir_funcion!=6);
		
		
		//CONDICIONAL QUE DIRIGE A LA OPCION DEL USUARIO
		switch (Elegir_funcion)
		{
			case 1: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					ListaP.Listar_empleados(4);
					break;
			case 2: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					ListaP.Anadir_empleados(Persona5, 4);
					break;
			case 3: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					ListaP.Quitar_empleados(4);
					break;
			case 4: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					ListaP.Mostrar_informacion_empleado(4);
					break;
			case 5: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					ListaP.Modificar_informacion_empleado(4);
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
		//MENU DE VEHICULOS
		std::cout<< "\x1b[38;5;182m";
		std::cout << "					  ......     ..     ..     ......       ..          .......      ..    ..                   " << std::endl;
		std::cout << "					  ..         ...   ...     ..    ..     ..         ..     ..     ..    ..                   " << std::endl;
		std::cout << " 					  ..         .... ....     ..    ..     ..         ..     ..      ..  ..                    " << std::endl;
		std::cout << "					  ......     ..  .  ..     ......       ..         ..     ..        ..                      " << std::endl;    
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ......     ..     ..     ..           ......      .......         ..                      " << "\n\n\n\n";
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 1. Agregar vehiculo    |					                        " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 2. Quitar modelo       |					                        " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 3. Modificar estado	 |			                                " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 4. Mostrar Registro    |					                        " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 5. Salir               |					                        " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << "\n\n\n";
		
		//SELECCION DE OPCION Y VALIDACION DE INFORMACION
		do
		{
			std::cout << "					                      Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4 && Elegir_funcion!=5);
		
		//CONDICIONAL QUE DIRIGE A LA OPCION DEL USUARIO
		switch (Elegir_funcion)
		{
			case 1: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Vehiculo1.agregarVehiculo();
					break;
			case 2: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Vehiculo1.quitarVehiculo();
					break;
			case 3: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Vehiculo1.modificarEstado();
					break;
			case 4: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Vehiculo1.mostrarRegistro();
					break;
			case 5: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					std::cout << "Programa terminado";
					break;
			default: std::cout << "Esto nunca debio pasar";
		}
	}
	
void Menu_de_inicio::Menu_Ganancias()
	{
		ListaG.Llenar(3);
		
		//MENU PRINCIPAL
		std::cout<< "\x1b[38;5;182m";
		std::cout << "					  ......     ..     ..     ......       ..          .......      ..    ..                   " << std::endl;
		std::cout << "					  ..         ...   ...     ..    ..     ..         ..     ..     ..    ..                   " << std::endl;
		std::cout << " 					  ..         .... ....     ..    ..     ..         ..     ..      ..  ..                    " << std::endl;
		std::cout << "					  ......     ..  .  ..     ......       ..         ..     ..        ..                      " << std::endl;    
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ......     ..     ..     ..           ......      .......         ..                      " << "\n\n\n\n";
		std::cout << "					                         ----------------------- 					                        " << std::endl;
		std::cout << "					                        | 1. Sumar utilidad     |					                        " << std::endl;
		std::cout << "					                         ----------------------- 					                        " << std::endl;
		std::cout << "					                        | 2. Modificar utilidad |					                        " << std::endl;
		std::cout << "					                         ----------------------- 					                        " << std::endl;
		std::cout << "					                        | 3. Ver utilidad       |					                        " << std::endl;
		std::cout << "					                         ----------------------- 					                        " << std::endl;
		std::cout << "					                        | 4. Salir              |					                        " << std::endl;
		std::cout << "					                         ----------------------- 					                        " << "\n\n\n";
		
		
		//SELECCION DE OPCION Y VALIDACION DE INFORMACION
		do
		{
			std::cout << "					                        Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4);
		
		
		//CONDICIONAL QUE DIRIGE A LA OPCION SELECCIONADA POR EL USUARIO
		switch (Elegir_funcion)
		{
			case 1: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					ListaG.Sumar_utilidad(Dia4_G, 3);
					break;
			case 2: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					ListaG.Modificar_utilidades(3);
					break;
			case 3: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					ListaG.Mostrar_utilidades(3);
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
		std::cout<< "\x1b[38;5;182m";
		std::cout << "					  ......     ..     ..     ......       ..          .......      ..    ..                   " << std::endl;
		std::cout << "					  ..         ...   ...     ..    ..     ..         ..     ..     ..    ..                   " << std::endl;
		std::cout << " 					  ..         .... ....     ..    ..     ..         ..     ..      ..  ..                    " << std::endl;
		std::cout << "					  ......     ..  .  ..     ......       ..         ..     ..        ..                      " << std::endl;    
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ......     ..     ..     ..           ......      .......         ..                      " << "\n\n\n\n";
		std::cout << "					                          ---------------------- 					                        " << std::endl;
		std::cout << "					                         | 1. Consultar precios |					                        " << std::endl;
		std::cout << "					                          ---------------------- 					                        " << std::endl;
		std::cout << "					                         | 2. Modificar precios |					                        " << std::endl;
		std::cout << "					                          ---------------------- 					                        " << std::endl;
		std::cout << "					                         | 3. Salir             |					                        " << std::endl;
		std::cout << "					                          ---------------------- 					                        " << "\n\n\n";
		
		/*
		do
		{
			std::cout << "					                        Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4);
		
		
		//CONDICIONAL QUE DIRIGE A LA OPCION SELECCIONADA POR EL USUARIO
		switch (Elegir_funcion)
		{
			case 1: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Registro1.editnombre()
					break;
			case 2: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Registro1.editnombre()
					break;
			case 3: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					Registro1.editfecha()
					break;
			case 4: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					std::cout << "Programa terminado";
					break;
			default: std::cout << "Esto nunca debio pasar";
			
		} */
	}