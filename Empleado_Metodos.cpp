#include <iostream>
#include "Empleado_Metodos.hpp"
#include "Complemento.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Empleados_Metodos::Empleados_Metodos()
	{
		size = 0;
		Lista_Empleados = nullptr;
	}
	
Empleados_Metodos::~Empleados_Metodos()
	{
		if (Lista_Empleados != nullptr)
		{
			delete [] Lista_Empleados;
		}
	}

void Empleados_Metodos::Listar_empleados()
	{
		if (Lista_Empleados[0].Get_telefono() != -1)		//Comprobar si tenemos empleados
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
				if (int(Lista_Empleados[i].Get_nombre()[0]) >= int(MIN_R) && int(Lista_Empleados[i].Get_nombre()[0]) <= int(MAX_R))
				{
					std::cout << "Nombre :";
					std::cout << Lista_Empleados[i].Get_nombre() << std::endl;
					std::cout << "Correo :";
					std::cout << Lista_Empleados[i].Get_email() << std::endl;
					std::cout << "Telefono :";
					std::cout << Lista_Empleados[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Empleados[i].Get_dni() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay ningun empleado para mostrar" << std::endl;
		}
			
	}

void Empleados_Metodos::Anadir_empleados()
	{
		int telefono, DNI;
		
		Empleado *Lista_temp = new Empleado[size+1];
		
		for (int i=0; i<size; i++)
		{
			Lista_temp[i] = Lista_Empleados[i];
		}

		delete [] Lista_Empleados;
		
		std::cout << "Que nombre tiene el empleado?" << "\n\n";
		Lista_temp[size].Set_nombre();
		std::cout << "\n\n";
		
		std::cout << "Que correo tiene el empleado?" << "\n\n";
		Lista_temp[size].Set_email();
		std::cout << "\n\n";
		
		std::cout << "Que telefono tiene el empleado?" << "\n\n";
		std::cin >> telefono;
		Lista_temp[size].Set_telefono(telefono);
		std::cout << "\n\n";
		
		std::cout << "Que DNI tiene el empleado?" << "\n\n";
		std::cin >> DNI;
		Lista_temp[size].Set_dni(DNI);
		std::cout << "\n\n";
		
		Lista_Empleados = new Empleado[size+1];
		
		for (int i=0; i<size+1; i++)
		{
			Lista_Empleados[i] = Lista_temp[i];
		}
		
		delete [] Lista_temp;
		
		size++;
		
		Guardar();
	}
	
void Empleados_Metodos::Quitar_empleados()
	{
		if (Lista_Empleados[0].Get_telefono() != -1)
		{
			int Incrementar = 0;
			int DNI_verificar = 0;
			bool Existe = 0;
			Empleado *Lista_temp = new Empleado[size-1];
			
			std::cout << "Inserte el DNI del empleado" << std::endl;
			std::cin >> DNI_verificar;
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Empleados[i].Get_dni() == DNI_verificar && Existe == 0)
				{
					Existe = 1;
					continue;
				}
				if (Existe == 0 && i==size-1)
				{
					std::cout << "No se encuentra el DNI insertado" << std::endl;
					break;
				}
				
				Lista_temp[Incrementar] = Lista_Empleados[i];
				Incrementar++;
			}
			
			if (Existe == 1)
			{
				delete [] Lista_Empleados;
				Lista_Empleados = new Empleado[size-1];
				
				for (int i=0; i<size-1; i++)
				{
					Lista_Empleados[i] = Lista_temp[i];
				}
				
				size--;
			}
			
			delete [] Lista_temp;
			
			Guardar();
		}
		else
		{
			std::cout << "No hay ningun empleado para eliminar" << std::endl;
		}
	}
	
void Empleados_Metodos::Mostrar_informacion_empleado()
	{
		if (Lista_Empleados[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			std::cout << "Escribe el DNI del empleado" << std::endl;
			std::cin >> DNI_verificar;
			std::cout << "\n\n";
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Empleados[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Nombre :";
					std::cout << Lista_Empleados[i].Get_nombre() << std::endl;
					std::cout << "Correo :";
					std::cout << Lista_Empleados[i].Get_email() << std::endl;
					std::cout << "Telefono :";
					std::cout << Lista_Empleados[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Empleados[i].Get_dni() << std::endl;
				}
			}
		}
		else
		{
			std::cout << "No hay empleados para mostrar informacion" << std::endl;
		}
	}
	
void Empleados_Metodos::Modificar_informacion_empleado()
	{
		if (Lista_Empleados[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			int Confirmar;
			int Cambio;
			std::cout << "Escribe el DNI del empleado" << std::endl;
			std::cin >> DNI_verificar;
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Empleados[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Quieres cambiar el nombre? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Empleados[i].Set_nombre();
					
					std::cout << "Quieres cambiar el correo? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Empleados[i].Set_email();
					
					std::cout << "Quieres cambiar el telefono? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio;
						Lista_Empleados[i].Set_telefono(Cambio);
					}
				}
			}
			
			Guardar();
		}
		else
		{
			std::cout << "No hay empleados para modificar" << std::endl;
		}
	}
	
void Empleados_Metodos::Determinar_tamano()
	{
		ESCRITURA.open("Empleados.txt", std::ios::app);
		LECTURA.open("Empleados.txt");
		
		if (Contenido_archivo(LECTURA))
		{
			LECTURA >> size;
			Lista_Empleados = new Empleado[size];
			ESCRITURA.close();
			LECTURA.close();
			Llenar();
		}
		else
		{
			size = 0;
			Lista_Empleados = new Empleado[1];
			ESCRITURA.close();
			LECTURA.close();
		}
	}

void Empleados_Metodos::Llenar()
	{
		LECTURA.open("Empleados.txt");
		
		int size;
		int telefono_t = 0;
		int dni_t = 0;
		char *nombre_t = new char[15];
		char *correo_t = new char[50];
			
		LECTURA >> size;
		
		for (int i=0; i<size; i++)
		{
			LECTURA >> nombre_t;
			LECTURA >> correo_t;
			LECTURA >> telefono_t;
			LECTURA >> dni_t;
					
			Lista_Empleados[i].Set_nombre(nombre_t);	
			Lista_Empleados[i].Set_email(correo_t);
			Lista_Empleados[i].Set_telefono(telefono_t);
			Lista_Empleados[i].Set_dni(dni_t);
		}

		delete [] nombre_t;
		delete [] correo_t;

		LECTURA.close();
	}
	
void Empleados_Metodos::Guardar()
	{
		LECTURA.open("Empleados.txt");
		ESCRITURA.open("Empleados_temp.txt", std::ios::app);

		ESCRITURA << size << "\n\n";
		
		for (int i=0; i<size; i++)
		{
			ESCRITURA << Lista_Empleados[i].Get_nombre() << std::endl;
			ESCRITURA << Lista_Empleados[i].Get_email() << std::endl;
			ESCRITURA << Lista_Empleados[i].Get_telefono() << std::endl;
			ESCRITURA << Lista_Empleados[i].Get_dni() << "\n\n";
		}

		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("Empleados.txt");
		std::rename("Empleados_temp.txt", "Empleados.txt");
	}