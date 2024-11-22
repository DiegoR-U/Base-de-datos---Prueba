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
		ListaP.Determinar_tamano();
		ListaG.Determinar_tamano();
		Vehiculo1;
		/* prueba = "prueba";
		Registro1(prueba, 11, 12, 2024) */
	}

void Menu_de_inicio::Mostrar_menu()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
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
		std::cout << "					                             | 1. Personas  |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 2. Clientes  |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 3. Vehiculos |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 4. Ganancias |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 5. Formato   |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << std::endl;
		std::cout << "					                             | 6. Salir     |					                            " << std::endl;
		std::cout << "					                              -------------- 					                            " << "\n\n\n";
		
		
		//SELECCION DE OPCION Y VALIDACION DE INFORMACION
		do
		{
			std::cout << "					                        Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4 && Elegir_funcion!=5 && Elegir_funcion!=6);
		
		
		//CONDICIONAL QUE DIRIGE A LA OPCION SELECCIONADA POR EL USUARIO
		switch (Elegir_funcion)
		{
			case 1: Menu_Empleados();
					break;
			case 2: Menu_Clientes();
					break;
			case 3: Menu_Vehiculos();
					break;
			case 4: Menu_Ganancias();
					break;
			case 5: Menu_Registro();
					break;
			case 6: Salir();
					break;
			default: std::cout << "Esto nunca debio pasar";
		}
		if (Elegir_funcion == 1 || Elegir_funcion == 2 || Elegir_funcion == 3 || Elegir_funcion == 4 || Elegir_funcion == 5)
			Mostrar_menu();
	}
	
void Menu_de_inicio::Menu_Empleados()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
		//MENU DE EMPLEADOS - PRUEBA
		std::cout<< "\x1b[38;5;182m";
		std::cout << "					  ......     ..     ..     ......       ..          .......      ..    ..                   " << std::endl;
		std::cout << "					  ..         ...   ...     ..    ..     ..         ..     ..     ..    ..                   " << std::endl;
		std::cout << " 					  ..         .... ....     ..    ..     ..         ..     ..      ..  ..                    " << std::endl;
		std::cout << "					  ......     ..  .  ..     ......       ..         ..     ..        ..                      " << std::endl;    
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ......     ..     ..     ..           ......      .......         ..                      " << "\n\n\n\n";
		std::cout << "					                             -----------------				                                " << std::endl;
		std::cout << "					                            | 1. Conductores  |					                            " << std::endl;
		std::cout << "					                             -----------------				                                " << std::endl;
		std::cout << "					                            | 2. Tecnicos     |					                            " << std::endl;
		std::cout << "					                             ----------------- 					                            " << std::endl;
		std::cout << "					                            | 3. Supervisores |					                            " << std::endl;
		std::cout << "					                             ----------------- 					                            " << std::endl;
		std::cout << "					                            | 4. Salir        |				                                " << std::endl;
		std::cout << "					                             -----------------			                                    " << "\n\n\n";
		
		//SELECCION DE OPCION Y VALIDACION DE INFORMACION
		do
		{
			std::cout << "					                      Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4);
		
		
		//CONDICIONAL QUE DIRIGE A LA OPCION DEL USUARIO
		switch (Elegir_funcion)
		{
			case 1: Menu_Conductores();
					break;
			case 2: Menu_Tecnicos();
					break;
			case 3: Menu_Supervisores();
					break;
			case 4: Mostrar_menu();
					break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		if (Elegir_funcion == 1 || Elegir_funcion == 2 || Elegir_funcion == 3)
			Menu_Empleados();
	}

void Menu_de_inicio::Menu_Clientes()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
		//MENU DE EMPLEADOS - PRUEBA
		std::cout<< "\x1b[38;5;182m";
		std::cout << "					  ......     ..     ..     ......       ..          .......      ..    ..                   " << std::endl;
		std::cout << "					  ..         ...   ...     ..    ..     ..         ..     ..     ..    ..                   " << std::endl;
		std::cout << " 					  ..         .... ....     ..    ..     ..         ..     ..      ..  ..                    " << std::endl;
		std::cout << "					  ......     ..  .  ..     ......       ..         ..     ..        ..                      " << std::endl;    
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ..         ..     ..     ..           ..         ..     ..        ..                      " << std::endl;
		std::cout << "					  ......     ..     ..     ..           ......      .......         ..                      " << "\n\n\n\n";
		std::cout << "					                      ------------------------				                                " << std::endl;
		std::cout << "					                     | 1. Clientes habituales |					                            " << std::endl;
		std::cout << "					                      ------------------------				                                " << std::endl;
		std::cout << "					                     | 2. Clientes de empresa |					                            " << std::endl;
		std::cout << "					                      ------------------------				                                " << std::endl;
		std::cout << "					                     | 3. Salir               |				                                " << std::endl;
		std::cout << "					                      ------------------------				                                " << std::endl;
		
		//SELECCION DE OPCION Y VALIDACION DE INFORMACION
		do
		{
			std::cout << "					                      Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4);
		
		
		//CONDICIONAL QUE DIRIGE A LA OPCION DEL USUARIO
		switch (Elegir_funcion)
		{
			case 1: Menu_Cliente_Habitual();
					break;
			case 2: Menu_Cliente_Empresarial();
					break;
			case 3: break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		Menu_Clientes();
	}

void Menu_de_inicio::Menu_Vehiculos()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
					
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
		/*
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
			case 1: Vehiculo1.agregarVehiculo();
					break;
			case 2: Vehiculo1.quitarVehiculo();
					break;
			case 3: Vehiculo1.modificarEstado();
					break;
			case 4: Vehiculo1.mostrarRegistro();
					break;
			case 5: break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		Menu_Vehiculos(); */
	}
	
void Menu_de_inicio::Menu_Ganancias()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
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
			case 1: ListaG.Sumar_utilidad();
					break;
			case 2: ListaG.Modificar_utilidades();
					break;
			case 3: ListaG.Mostrar_utilidades();
					break;
			case 4: break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		Menu_Ganancias();
	}
	
void Menu_de_inicio::Menu_Registro()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
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
			case 1: Registro1.editnombre()
					break;
			case 2: Registro1.editnombre()
					break;
			case 3: Registro1.editfecha()
					break;
			case 4: break;
			default: std::cout << "Esto nunca debio pasar";
			
		} 
		
		Menu_Registro(); */
	}
	
void Menu_de_inicio::Menu_Conductores()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
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
		std::cout << "					                       | 1. Lista de conductores  |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 2. Añadir conductores    |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 3. Quitar conductores    |					                            " << std::endl;
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
			case 1: ListaP.Listar_conductores();
					break;
			case 2: ListaP.Anadir_conductores();
					break;
			case 3: ListaP.Quitar_conductores();
					break;
			case 4: ListaP.Mostrar_informacion_conductores();
					break;
			case 5: ListaP.Modificar_informacion_conductores();
					break;
			case 6: Mostrar_menu();
					break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		if (Elegir_funcion == 1 || Elegir_funcion == 2 || Elegir_funcion == 3 || Elegir_funcion == 4 || Elegir_funcion == 5)
			Menu_Conductores();
	}
	
void Menu_de_inicio::Menu_Tecnicos()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
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
		std::cout << "					                       | 1. Lista de tecnicos     |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 2. Añadir tecnicos       |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 3. Quitar tecnicos       |					                            " << std::endl;
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
			case 1: ListaP.Listar_conductores();
					break;
			case 2: ListaP.Anadir_conductores();
					break;
			case 3: ListaP.Quitar_conductores();
					break;
			case 4: ListaP.Mostrar_informacion_conductores();
					break;
			case 5: ListaP.Modificar_informacion_conductores();
					break;
			case 6: break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		Menu_Tecnicos();
	}
	
void Menu_de_inicio::Menu_Supervisores()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
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
		std::cout << "					                       | 1. Lista de supervisores |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 2. Añadir supervisores   |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 3. Quitar supervisores   |					                            " << std::endl;
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
			case 1: ListaP.Listar_conductores();
					break;
			case 2: ListaP.Anadir_conductores();
					break;
			case 3: ListaP.Quitar_conductores();
					break;
			case 4: ListaP.Mostrar_informacion_conductores();
					break;
			case 5: ListaP.Modificar_informacion_conductores();
					break;
			case 6: break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		Menu_Supervisores();
	}
	
void Menu_de_inicio::Menu_Cliente_Habitual()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
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
		std::cout << "					                       | 1. Lista de clientes     |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 2. Añadir clientes       |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 3. Quitar clientes       |					                            " << std::endl;
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
			case 1: ListaP.Listar_conductores();
					break;
			case 2: ListaP.Anadir_conductores();
					break;
			case 3: ListaP.Quitar_conductores();
					break;
			case 4: ListaP.Mostrar_informacion_conductores();
					break;
			case 5: ListaP.Modificar_informacion_conductores();
					break;
			case 6: break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		Menu_Cliente_Habitual();
	}
	
void Menu_de_inicio::Menu_Cliente_Empresarial()
	{
		std::system(CLEAR_COMMAND);
		std::cout << "\x1B[H";
		
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
		std::cout << "					                       | 1. Lista de empresarios  |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 2. Añadir empresarios    |					                            " << std::endl;
		std::cout << "					                        -------------------------- 					                            " << std::endl;
		std::cout << "					                       | 3. Quitar empresarios    |					                            " << std::endl;
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
			case 1: ListaP.Listar_conductores();
					break;
			case 2: ListaP.Anadir_conductores();
					break;
			case 3: ListaP.Quitar_conductores();
					break;
			case 4: ListaP.Mostrar_informacion_conductores();
					break;
			case 5: ListaP.Modificar_informacion_conductores();
					break;
			case 6: break;
			default: std::cout << "Esto nunca debio pasar";
		}
		
		Menu_Cliente_Empresarial();
	}

void Menu_de_inicio::Salir()
	{
		std::cout << "Programa terminado" << std::endl;
		ListaP.Guardar();
	}