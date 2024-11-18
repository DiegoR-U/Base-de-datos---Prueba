#include <iostream>
#include "Empleados_Metodos.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Empleado_Metodos::Empleado_Metodos()
	{
		comp;
		size = 0;
		Lista_Empleados = nullptr;
	}
	
Empleado_Metodos::~Empleado_Metodos()
	{
		if (Lista_Empleados != nullptr)
		{
			delete [] Lista_Empleados;
		}
	}

void Empleado_Metodos::Listar_empleados()
	{
		if (Lista_Empleados[0].Get_telefono() != -1)		//Comprobar si tenemos empleados
		{
			char MIN_R, MAX_R;
			
			std::cout << "Desde que letra quieres listar? | (teclea A si quieres desde el inicio)" << "\n\n";
			do
			{
				std::cin >> MIN_R;
				std::cout << "\n\n";
				comp.Convertir_mayusculas_minusculas(MIN_R, 0);
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
				comp.Convertir_mayusculas_minusculas(MAX_R, 0);
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
					std::cout << "Telefono :";
					std::cout << Lista_Empleados[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Empleados[i].Get_dni() << std::endl;
					std::cout << "Email :";
					std::cout << Lista_Empleados[i].Get_email() << std::endl;
					std::cout << "Direccion :";
					std::cout << Lista_Empleados[i].Get_direccion() << std::endl;
					std::cout << "Salario :";
					std::cout << Lista_Empleados[i].Get_salario() << std::endl;
					std::cout << "Contrato :";
					std::cout << Lista_Empleados[i].Get_Contrato() << std::endl;
					std::cout << "Nacimiento :";
					std::cout << Lista_Empleados[i].Get_Nacimiento() << std::endl;
					std::cout << "Edad :";
					std::cout << Lista_Empleados[i].Get_edad() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay ningun empleado para mostrar" << std::endl;
		}
			
	}

void Empleado_Metodos::Anadir_empleados()
	{
		int num_t;
		float float_t;
		
		Empleado *Lista_temp = new Empleado[size+1];
		
		for (int i=0; i<size; i++)
		{
			Lista_temp[i] = Lista_Empleados[i];
		}

		delete [] Lista_Empleados;
		
		std::cout << "Que nombre tiene el empleado?" << "\n\n";
		Lista_temp[size].Set_nombre(comp);
		std::cout << "\n\n";
		
		std::cout << "Que telefono tiene el empleado?" << "\n\n";
		std::cin >> num_t;
		Lista_temp[size].Set_telefono(num_t);
		std::cout << "\n\n";
		
		std::cout << "Que DNI tiene el empleado?" << "\n\n";
		std::cin >> num_t;
		Lista_temp[size].Set_dni(num_t);
		std::cout << "\n\n";
		
		std::cout << "Que email tiene el empleado?" << "\n\n";
		Lista_temp[size].Set_email(comp);
		std::cout << "\n\n";
		
		std::cout << "Que direccion tiene el empleado?" << "\n\n";
		Lista_temp[size].Set_direccion(comp);
		std::cout << "\n\n";
		
		std::cout << "Cuando se contrato al empleado?" << "\n\n";
		Lista_temp[size].Set_Contrato();
		std::cout << "\n\n";
		
		std::cout << "Cuando nacio el empleado?" << "\n\n";
		Lista_temp[size].Set_Nacimiento();
		std::cout << "\n\n";
		
		std::cout << "Que salario tiene el empleado?" << "\n\n";
		std::cin >> float_t;
		Lista_temp[size].Set_salario(float_t);
		std::cout << "\n\n";
		
		std::cout << "Que edad tiene el empleado?" << "\n\n";
		std::cin >> num_t;
		Lista_temp[size].Set_edad(num_t);
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
	
void Empleado_Metodos::Quitar_empleados()
	{
		if (Lista_Empleados[0].Get_telefono() != -1)
		{
			int Incrementar = 0;
			int DNI_verificar = 0;
			bool Existe = 0;
			
			std::cout << "Inserte el DNI del empleado" << std::endl;
			std::cin >> DNI_verificar;
			
			
			if (size > 1)
			{
				Empleado* Lista_temp = new Empleado[size-1];
				
				for (int i=0; i<size; i++)
				{
					if (Lista_Empleados[i].Get_dni() == DNI_verificar && Existe == 0)
					{
						Existe = 1;
						continue;
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
						
					delete [] Lista_temp;
					
					size--;
				}
			}
			else
			{
				if (Lista_Empleados[0].Get_dni() == DNI_verificar)
				{
					Existe = 1;
				}
				
				if (Existe == 1)
				{
					delete [] Lista_Empleados;
				
					Lista_Empleados = new Empleado[1];
					
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
			std::cout << "No hay ningun empleado para eliminar" << std::endl;
		}
	}
	
void Empleado_Metodos::Mostrar_informacion_empleados()
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
					std::cout << "Telefono :";
					std::cout << Lista_Empleados[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Empleados[i].Get_dni() << std::endl;
					std::cout << "Email :";
					std::cout << Lista_Empleados[i].Get_email() << std::endl;
					std::cout << "Direccion :";
					std::cout << Lista_Empleados[i].Get_direccion() << std::endl;
					std::cout << "Salario :";
					std::cout << Lista_Empleados[i].Get_salario() << std::endl;
					std::cout << "Contrato :";
					std::cout << Lista_Empleados[i].Get_Contrato() << std::endl;
					std::cout << "Nacimiento :";
					std::cout << Lista_Empleados[i].Get_Nacimiento() << std::endl;
					std::cout << "Edad :";
					std::cout << Lista_Empleados[i].Get_edad() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay empleados para mostrar informacion" << std::endl;
		}
	}
	
void Empleado_Metodos::Modificar_informacion_empleados()
	{
		if (Lista_Empleados[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			int Confirmar;
			int Cambio;
			float Cambio_f;
			std::cout << "Escribe el DNI del empleado" << std::endl;
			std::cin >> DNI_verificar;
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Empleados[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Quieres cambiar el nombre? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Empleados[i].Set_nombre(comp);
					
					std::cout << "Quieres cambiar el telefono? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio;
						Lista_Empleados[i].Set_telefono(Cambio);
					}
					
					std::cout << "Quieres cambiar el email? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Empleados[i].Set_email(comp);
					
					std::cout << "Quieres cambiar la direccion? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Empleados[i].Set_direccion(comp);
					
					std::cout << "Quieres cambiar la fecha de coontrato? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Empleados[i].Set_Contrato();
					
					std::cout << "Quieres cambiar el nacimiento? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Empleados[i].Set_Nacimiento();
					
					std::cout << "Quieres cambiar el salario? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio_f;
						Lista_Empleados[i].Set_salario(Cambio_f);
					}
					
					std::cout << "Quieres cambiar la edad? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio;
						Lista_Empleados[i].Set_edad(Cambio);
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
	
void Empleado_Metodos::Determinar_tamano()
	{
		ESCRITURA.open("Empleados.txt", std::ios::app);
		LECTURA.open("Empleados.txt");
		
		if (comp.Contenido_archivo(LECTURA))
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

void Empleado_Metodos::Llenar()
	{
		LECTURA.open("Empleados.txt");
		
		int telefono_t = 0;
		int dni_t = 0;
		int edad_t = 0;
		float salario_t = 0;
		char *general_t = new char[60];
		char *espacio_t = new char[5];
		
		LECTURA >> general_t >> espacio_t >> general_t >> espacio_t >> general_t >> espacio_t >> general_t >> espacio_t >> general_t >> espacio_t >> general_t >> espacio_t >> general_t >> espacio_t >> general_t >> espacio_t >> general_t; 
		
		LECTURA >> size;
		
		for (int i=0; i<size; i++)
		{
			LECTURA.getline(general_t, 60, '|');
					
			Lista_Empleados[i].Set_nombre(comp, general_t);
			
			LECTURA >> telefono_t;
			
			Lista_Empleados[i].Set_telefono(telefono_t);
			
			LECTURA >> espacio_t;
			LECTURA >> dni_t;
					
			Lista_Empleados[i].Set_dni(dni_t);
			
			LECTURA >> espacio_t;
			LECTURA.getline(general_t, 60, '|');
					
			Lista_Empleados[i].Set_email(comp, general_t);
			
			LECTURA.getline(general_t, 60, '|');
					
			Lista_Empleados[i].Set_direccion(comp, general_t);
			
			LECTURA >> dia_t;
			LECTURA >> espacio_t;
			
			LECTURA >> mes_t;
			LECTURA >> espacio_t;
			
			LECTURA >> year_t;
			LECTURA >> espacio_t;
			
			Lista_Empleados[i].Set_Contrato(dia_t, mes_t, year_t);
			
			LECTURA >> dia_t;
			LECTURA >> espacio_t;
			
			LECTURA >> mes_t;
			LECTURA >> espacio_t;
			
			LECTURA >> year_t;
			LECTURA >> espacio_t;
			
			Lista_Empleados[i].Set_Nacimiento(dia_t, mes_t, year_t);
			
			LECTURA >> salario_t;
			
			Lista_Empleados[i].Set_salario(salario_t);
			
			LECTURA >> edad_t;
			
			Lista_Empleados[i].Set_edad(edad_t);
		}

		delete [] general_t;
		delete [] espacio_t;

		LECTURA.close();
	}
	
void Empleado_Metodos::Guardar()
	{
		LECTURA.open("Empleados.txt");
		ESCRITURA.open("Empleados_temp.txt", std::ios::app);
		
		ESCRITURA << "Nombre     ->     Telefono     ->     DNI     ->     Email     ->     Direccion     ->     Contrato     ->     Nacimiento     ->     Salario     ->     Edad" << "\n\n";
		
		ESCRITURA << size << "\n\n";
		
		for (int i=0; i<size; i++)
		{
			ESCRITURA << Lista_Empleados[i].Get_nombre() << " | ";
			ESCRITURA << Lista_Empleados[i].Get_telefono() << " | ";
			ESCRITURA << Lista_Empleados[i].Get_dni() << " | ";
			ESCRITURA << Lista_Empleados[i].Get_email() << " | ";
			ESCRITURA << Lista_Empleados[i].Get_direccion() << " | ";
			ESCRITURA << Lista_Empleados[i].Get_Contrato() << " | ";
			ESCRITURA << Lista_Empleados[i].Get_Nacimiento() << " | ";
			ESCRITURA << Lista_Empleados[i].Get_salario() << " | ";
			ESCRITURA << Lista_Empleados[i].Get_edad() << "\n\n";
		}

		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("Empleados.txt");
		std::rename("Empleados_temp.txt", "Empleados.txt");
	}