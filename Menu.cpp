#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

#include "Menu.hpp"

Menu_de_inicio::Menu_de_inicio()
	{
		Elegir_funcion = 0;
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
		std::cout << "					                        | 1. Agregar Vehiculo    |					                        " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 2. Quitar Vehiculo     |					                        " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 3. Modificar Estado    |					                        " << std::endl;			                      				
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 4. Mostrar Datos       |					                        " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << std::endl;
		std::cout << "					                        | 5. Salir               |					                        " << std::endl;
		std::cout << "					                         ------------------------ 					                        " << "\n\n\n";
		
		//SELECCION DE OPCION Y VALIDACION DE INFORMACION
		do
		{
			std::cout << "					                        Elige la opcion a tomar: ";
			std::cin >> Elegir_funcion;
			std::cout<< "\x1b[0m";
			
		} while(Elegir_funcion!=1 && Elegir_funcion!=2 && Elegir_funcion!=3 && Elegir_funcion!=4 && Elegir_funcion!=5 );
		
		
		//CONDICIONAL QUE DIRIGE A LA OPCION SELECCIONADA POR EL USUARIO
		switch (Elegir_funcion)
		{
			case 1: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					agregarVehiculo();
					break;
			case 2: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					quitarVehiculo();
					break;
			case 3: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					modificarEstado();
					break;
			case 4: std::system(CLEAR_COMMAND);
					std::cout << "\x1B[H";
					mostrarRegistro();
					std::cout << "Programa terminado";
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

	}