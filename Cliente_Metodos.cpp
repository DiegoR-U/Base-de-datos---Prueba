#include <iostream>
#include "Cliente_Metodos.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Cliente_Metodos::Cliente_Metodos()
	{
		size = 0;
		Lista_Clientes = nullptr;
	}
	
Cliente_Metodos::~Cliente_Metodos()
	{
		if (Lista_Clientes != nullptr)
		{
			delete [] Lista_Clientes;
		}
	}

void Cliente_Metodos::Listar_clientes()
	{
		if (Lista_Clientes[0].Get_telefono() != -1)		//Comprobar si tenemos clientes
		{
			char MIN_R, MAX_R;
			
			std::cout << "Desde que letra quieres listar? | (teclea A si quieres desde el inicio)" << "\n\n";
			do
			{
				std::cin >> MIN_R;
				std::cout << "\n\n";
				Convertir_mayusculas_minusculas(MIN_R, 0);
				if ((int(MIN_R) > 90 && int(MIN_R) < 97) || (int(MIN_R) > 122) || (int(MIN_R) < 65))
				{
					std::cout << "Ingrese una letra valida" << "\n\n";
				}
			} while ((int(MIN_R) > 90 && int(MIN_R) < 97) || (int(MIN_R) > 122) || (int(MIN_R) < 65));
			
			
			std::cout << "Hasta que letra quieres listar? | (teclea Z si quieres hasta el final)" << "\n\n";
			do
			{
				std::cin >> MAX_R;
				std::cout << "\n\n";
				Convertir_mayusculas_minusculas(MAX_R, 0);
				if ((int(MAX_R) > 90 && int(MAX_R) < 97) || (int(MAX_R) > 122) || (int(MAX_R) < 65))
				{
					std::cout << "Ingrese una letra valida" << "\n\n";
				}
			} while ((int(MAX_R) < int(MIN_R)) || (int(MAX_R) > 90 && int(MAX_R) < 97) || (int(MAX_R) > 122) || (int(MAX_R) < 65));
			
			for (int i=0; i<size; i++)
			{
				if (int(Lista_Clientes[i].Get_nombre()[0]) >= int(MIN_R) && int(Lista_Clientes[i].Get_nombre()[0]) <= int(MAX_R))
				{
					std::cout << "Nombre :";
					std::cout << Lista_Clientes[i].Get_nombre() << std::endl;
					std::cout << "Telefono :";
					std::cout << Lista_Clientes[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Clientes[i].Get_dni() << std::endl;
					std::cout << "Fecha de nscripcion :";
					std::cout << Lista_Clientes[i].Get_inscripcion() << std::endl;
					std::cout << "Puntos :";
					std::cout << Lista_Clientes[i].Get_puntos() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay ningun cliente para mostrar" << std::endl;
		}
			
	}

void Cliente_Metodos::Anadir_clientes()
	{
		int telefono, DNI;
		
		Cliente *Lista_temp = new Cliente[size+1];
		
		for (int i=0; i<size; i++)
		{
			Lista_temp[i] = Lista_Clientes[i];
		}

		delete [] Lista_Clientes;
		
		std::cout << "Que nombre tiene el cliente?" << "\n\n";
		Lista_temp[size].Set_nombre();
		std::cout << "\n\n";
		
		std::cout << "Que telefono tiene el cliente?" << "\n\n";
		std::cin >> telefono;
		Lista_temp[size].Set_telefono(telefono);
		std::cout << "\n\n";
		
		std::cout << "Que DNI tiene el cliente?" << "\n\n";
		std::cin >> DNI;
		Lista_temp[size].Set_dni(DNI);
		std::cout << "\n\n";
		
		Lista_Clientes = new Cliente[size+1];
		
		for (int i=0; i<size+1; i++)
		{
			Lista_Clientes[i] = Lista_temp[i];
		}
		
		delete [] Lista_temp;
		
		size++;
		
		Guardar();
	}
	
void Cliente_Metodos::Quitar_clientes()
	{
		if (Lista_Clientes[0].Get_telefono() != -1)
		{
			int Incrementar = 0;
			int DNI_verificar = 0;
			bool Existe = 0;
			
			std::cout << "Inserte el DNI del cliente" << std::endl;
			std::cin >> DNI_verificar;
			
			
			if (size > 1)
			{
				Cliente* Lista_temp = new Cliente[size-1];
				
				for (int i=0; i<size; i++)
				{
					if (Lista_Clientes[i].Get_dni() == DNI_verificar && Existe == 0)
					{
						Existe = 1;
						continue;
					}

					Lista_temp[Incrementar] = Lista_Clientes[i];
					Incrementar++;
				}
				
				if (Existe == 1)
				{
					delete [] Lista_Clientes;
					
					Lista_Clientes = new Cliente[size-1];
					
					for (int i=0; i<size-1; i++)
					{
						Lista_Clientes[i] = Lista_temp[i];
					}
						
					delete [] Lista_temp;
					
					size--;
				}
			}
			else
			{
				if (Lista_Clientes[0].Get_dni() == DNI_verificar)
				{
					Existe = 1;
				}
				
				if (Existe == 1)
				{
					delete [] Lista_Clientes;
				
					Lista_Clientes = new Cliente[1];
					
					size--;
				}
				
			}
			
			if (Existe == 0)
			{
				std::cout << "No se encuentra el DNI insertado" << std::endl;
			}
			else {}
			
			Guardar();
		}
		else
		{
			std::cout << "No hay ningun cliente para eliminar" << std::endl;
		}
	}
	
void Cliente_Metodos::Mostrar_informacion_clientes()
	{
		if (Lista_Clientes[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			std::cout << "Escribe el DNI del cliente" << std::endl;
			std::cin >> DNI_verificar;
			std::cout << "\n\n";
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Clientes[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Nombre :";
					std::cout << Lista_Clientes[i].Get_nombre() << std::endl;
					std::cout << "Telefono :";
					std::cout << Lista_Clientes[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Clientes[i].Get_dni() << std::endl;
					std::cout << "Fecha de nscripcion :";
					std::cout << Lista_Clientes[i].Get_inscripcion() << std::endl;
					std::cout << "Puntos :";
					std::cout << Lista_Clientes[i].Get_puntos() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay clientes para mostrar informacion" << std::endl;
		}
	}
	
void Cliente_Metodos::Modificar_informacion_clientes()
	{
		if (Lista_Clientes[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			int Confirmar;
			int Cambio;
			std::cout << "Escribe el DNI de la persona" << std::endl;
			std::cin >> DNI_verificar;
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Clientes[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Quieres cambiar el nombre? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Clientes[i].Set_nombre();
					
					std::cout << "Quieres cambiar el telefono? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio;
						Lista_Clientes[i].Set_telefono(Cambio);
					}
					
					std::cout << "Quieres cambiar la fecha de inscripcion? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Clientes[i].Set_inscripcion();
					
					std::cout << "Quieres cambiar los puntos? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio;
						Lista_Clientes[i].Set_puntos(Cambio);
					}
				}
			}
			
			Guardar();
		}
		else
		{
			std::cout << "No hay clientes para modificar" << std::endl;
		}
	}
	
void Cliente_Metodos::Determinar_tamano()
	{
		ESCRITURA.open("Clientes.txt", std::ios::app);
		LECTURA.open("Clientes.txt");
		
		if (Contenido_archivo(LECTURA))
		{
			LECTURA >> size;
			Lista_Clientes = new Cliente[size];
			ESCRITURA.close();
			LECTURA.close();
			Llenar();
		}
		else
		{
			size = 0;
			Lista_Clientes = new Cliente[1];
			ESCRITURA.close();
			LECTURA.close();
		}
	}

void Cliente_Metodos::Llenar()
	{
		LECTURA.open("Clientes.txt");
		
		int num_t;
		int dia_t, mes_t, year_t;
		char *nombre_t = new char[60];
		char *espacio_t = new char[5];
		
		LECTURA >> nombre_t >> espacio_t >> nombre_t >> espacio_t >> nombre_t;
		
		LECTURA >> size;
		
		for (int i=0; i<size; i++)
		{
			LECTURA.getline(nombre_t, 60, '|');
					
			Lista_Clientes[i].Set_nombre(nombre_t);
			
			LECTURA >> num_t;
			
			Lista_Clientes[i].Set_telefono(num_t);
			
			LECTURA >> espacio_t;
			LECTURA >> num_t;
					
			Lista_Clientes[i].Set_dni(num_t);
			
			LECTURA >> espacio_t;
			LECTURA >> dia_t;
			
			LECTURA >> espacio_t;
			LECTURA >> mes_t;
			
			LECTURA >> espacio_t;
			LECTURA >> year_t;
			
			Lista_Clientes[i].Set_inscripcion(dia_t, mes_t, year_t);
			
			LECTURA >> espacio_t;
			LECTURA >> num_t;

			Lista_Clientes[i].Set_puntos(num_t);
		} 

		delete [] nombre_t;
		delete [] espacio_t;

		LECTURA.close();
	}
	
void Cliente_Metodos::Guardar()
	{
		LECTURA.open("Clientes.txt");
		ESCRITURA.open("Clientes_temp.txt", std::ios::app);
		
		ESCRITURA << "Nombre     ->     Telefono     ->     DNI     ->     Inscripcion     ->     Puntos" << "\n\n";
		
		ESCRITURA << size << "\n\n";
		
		for (int i=0; i<size; i++)
		{
			ESCRITURA << Lista_Clientes[i].Get_nombre() << " | ";
			ESCRITURA << Lista_Clientes[i].Get_telefono() << " | ";
			ESCRITURA << Lista_Clientes[i].Get_dni() << " | ";
			ESCRITURA << Lista_Clientes[i].Get_inscripcion() << " | ";
			ESCRITURA << Lista_Clientes[i].Get_puntos() << "\n\n";
		}

		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("Clientes.txt");
		std::rename("Clientes_temp.txt", "Clientes.txt");
	}