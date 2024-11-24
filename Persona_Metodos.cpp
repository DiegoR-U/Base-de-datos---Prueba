#include <iostream>
#include "Persona_Metodos.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Persona_Metodos::Persona_Metodos()
	{
		size = 0;
		Lista_Personas = nullptr;
	}
	
Persona_Metodos::~Persona_Metodos()
	{
		if (Lista_Personas != nullptr)
		{
			delete [] Lista_Personas;
		}
	}

void Persona_Metodos::Listar_personas()
	{
		if (Lista_Personas[0].Get_telefono() != -1)		//Comprobar si tenemos personas
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
				if (int(Lista_Personas[i].Get_nombre()[0]) >= int(MIN_R) && int(Lista_Personas[i].Get_nombre()[0]) <= int(MAX_R))
				{
					std::cout << "Nombre :";
					std::cout << Lista_Personas[i].Get_nombre() << std::endl;
					std::cout << "Telefono :";
					std::cout << Lista_Personas[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Personas[i].Get_dni() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay ninguna persona para mostrar" << std::endl;
		}
			
	}

void Persona_Metodos::Anadir_personas()
	{
		int telefono, DNI;
		
		Persona *Lista_temp = new Persona[size+1];
		
		for (int i=0; i<size; i++)
		{
			Lista_temp[i] = Lista_Personas[i];
		}

		delete [] Lista_Personas;
		
		std::cout << "Que nombre tiene la persona?" << "\n\n";
		Lista_temp[size].Set_nombre();
		std::cout << "\n\n";
		
		std::cout << "Que telefono tiene la persona?" << "\n\n";
		std::cin >> telefono;
		Lista_temp[size].Set_telefono(telefono);
		std::cout << "\n\n";
		
		std::cout << "Que DNI tiene la persona?" << "\n\n";
		std::cin >> DNI;
		Lista_temp[size].Set_dni(DNI);
		std::cout << "\n\n";
		
		Lista_Personas = new Persona[size+1];
		
		for (int i=0; i<size+1; i++)
		{
			Lista_Personas[i] = Lista_temp[i];
		}
		
		delete [] Lista_temp;
		
		size++;
		
		Guardar();
	}
	
void Persona_Metodos::Quitar_personas()
	{
		if (Lista_Personas[0].Get_telefono() != -1)
		{
			int Incrementar = 0;
			int DNI_verificar = 0;
			bool Existe = 0;
			
			std::cout << "Inserte el DNI de la persona" << std::endl;
			std::cin >> DNI_verificar;
			
			
			if (size > 1)
			{
				Persona* Lista_temp = new Persona[size-1];
				
				for (int i=0; i<size; i++)
				{
					if (Lista_Personas[i].Get_dni() == DNI_verificar && Existe == 0)
					{
						Existe = 1;
						continue;
					}

					Lista_temp[Incrementar] = Lista_Personas[i];
					Incrementar++;
				}
				
				if (Existe == 1)
				{
					delete [] Lista_Personas;
					
					Lista_Personas = new Persona[size-1];
					
					for (int i=0; i<size-1; i++)
					{
						Lista_Personas[i] = Lista_temp[i];
					}
						
					delete [] Lista_temp;
					
					size--;
				}
			}
			else
			{
				if (Lista_Personas[0].Get_dni() == DNI_verificar)
				{
					Existe = 1;
				}
				
				if (Existe == 1)
				{
					delete [] Lista_Personas;
				
					Lista_Personas = new Persona[1];
					
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
			std::cout << "No hay ninguna persona para eliminar" << std::endl;
		}
	}
	
void Persona_Metodos::Mostrar_informacion_personas()
	{
		if (Lista_Personas[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			std::cout << "Escribe el DNI de la persona" << std::endl;
			std::cin >> DNI_verificar;
			std::cout << "\n\n";
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Personas[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Nombre :";
					std::cout << Lista_Personas[i].Get_nombre() << std::endl;
					std::cout << "Telefono :";
					std::cout << Lista_Personas[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Personas[i].Get_dni() << std::endl;
				}
			}
		}
		else
		{
			std::cout << "No hay personas para mostrar informacion" << std::endl;
		}
	}
	
void Persona_Metodos::Modificar_informacion_personas()
	{
		if (Lista_Personas[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			int Confirmar;
			int Cambio;
			std::cout << "Escribe el DNI de la persona" << std::endl;
			std::cin >> DNI_verificar;
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Personas[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Quieres cambiar el nombre? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Personas[i].Set_nombre();
					
					std::cout << "Quieres cambiar el telefono? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio;
						Lista_Personas[i].Set_telefono(Cambio);
					}
				}
			}
			
			Guardar();
		}
		else
		{
			std::cout << "No hay Persona para modificar" << std::endl;
		}
	}
	
void Persona_Metodos::Determinar_tamano()
	{
		ESCRITURA.open("Personas.txt", std::ios::app);
		LECTURA.open("Personas.txt");
		
		if (Contenido_archivo(LECTURA))
		{
			LECTURA >> size;
			Lista_Personas = new Persona[size];
			ESCRITURA.close();
			LECTURA.close();
			Llenar();
		}
		else
		{
			size = 0;
			Lista_Personas = new Persona[1];
			ESCRITURA.close();
			LECTURA.close();
		}
	}

void Persona_Metodos::Llenar()
	{
		LECTURA.open("Personas.txt");
		
		int telefono_t = 0;
		int dni_t = 0;
		char *nombre_t = new char[60];
		char *espacio_t = new char[5];
		
		LECTURA >> nombre_t >> espacio_t >> nombre_t >> espacio_t >> nombre_t;
		
		LECTURA >> size;
		
		for (int i=0; i<size; i++)
		{
			LECTURA.getline(nombre_t, 60, '|');
					
			Lista_Personas[i].Set_nombre(nombre_t);
			
			LECTURA >> telefono_t;
			
			Lista_Personas[i].Set_telefono(telefono_t);
			
			LECTURA >> espacio_t;
			LECTURA >> dni_t;
					
			Lista_Personas[i].Set_dni(dni_t);
		} 

		delete [] nombre_t;
		delete [] espacio_t;

		LECTURA.close();
	}
	
void Persona_Metodos::Guardar()
	{
		LECTURA.open("Personas.txt");
		ESCRITURA.open("Personas_temp.txt", std::ios::app);
		
		ESCRITURA << "Nombre     ->     Telefono     ->     DNI" << "\n\n";
		
		ESCRITURA << size << "\n\n";
		
		for (int i=0; i<size; i++)
		{
			ESCRITURA << Lista_Personas[i].Get_nombre() << " | ";
			ESCRITURA << Lista_Personas[i].Get_telefono() << " | ";
			ESCRITURA << Lista_Personas[i].Get_dni() << "\n\n";
		}

		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("Personas.txt");
		std::rename("Personas_temp.txt", "Personas.txt");
	}