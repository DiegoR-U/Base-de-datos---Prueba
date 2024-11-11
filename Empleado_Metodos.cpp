#include <iostream>
#include "Empleado_Metodos.hpp"

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
		comp;
		Lista_Empleados = new Empleados[4];
	}
	
Empleados_Metodos::~Empleados_Metodos()
	{
		if (Lista_Empleados != nullptr)
		{
			delete [] Lista_Empleados;
		}
	}

void Empleados_Metodos::Listar_empleados(int N)
	{
		for (int i=0; i<N; i++)
		{
			std::cout << "Nombre :";
			std::cout << Lista_Empleados[i].Get_nombre() << std::endl;
			std::cout << "Correo :";
			std::cout << Lista_Empleados[i].Get_correo() << std::endl;
			std::cout << "Telefono :";
			std::cout << Lista_Empleados[i].Get_telefono() << std::endl;
			std::cout << "DNI :";
			std::cout << Lista_Empleados[i].Get_dni() << "\n\n";
		}
	}

void Empleados_Metodos::Anadir_empleados(Empleados p, int N)
	{
		int telefono, DNI;
		
		std::cout << "Que nombre tiene el empleado?" << "\n\n";
		p.Set_nombre(comp, nullptr);
		std::cout << "\n\n";
		
		std::cout << "Que correo tiene el empleado?" << "\n\n";
		p.Set_correo(comp, nullptr);
		std::cout << "\n\n";
		
		std::cout << "Que telefono tiene el empleado?" << "\n\n";
		std::cin >> telefono;
		p.Set_telefono(telefono);
		std::cout << "\n\n";
		
		std::cout << "Que telefono tiene el empleado?" << "\n\n";
		std::cin >> DNI;
		p.Set_dni(DNI);
		std::cout << "\n\n";
		
		Empleados *Lista_temp = new Empleados[N+1];
		
		for (int i=0; i<N; i++)
		{
			Lista_temp[i] = Lista_Empleados[i];
		}

		delete [] Lista_Empleados;
		Lista_temp[N] = p;
		Lista_Empleados = new Empleados[N+1];
		
		for (int i=0; i<N+1; i++)
		{
			Lista_Empleados[i] = Lista_temp[i];
		}
		
		for (int i=0; i<N+1; i++)
		{
			std::cout << Lista_Empleados[i].Get_nombre() << std::endl;
			std::cout << Lista_Empleados[i].Get_correo() << std::endl;
			std::cout << Lista_Empleados[i].Get_telefono() << std::endl;
			std::cout << Lista_Empleados[i].Get_dni() << "\n\n";
		}
		
		delete [] Lista_temp;
		
		Guardar(N+1);
	}
	
void Empleados_Metodos::Quitar_empleados(int N)
	{
		int Eliminar = 0;
		int DNI_verificar = 0;
		Empleados *Lista_temp = new Empleados[N-1];
		
		std::cout << "Inserte el DNI del empleado" << std::endl;
		std::cin >> DNI_verificar;
		
		for (int i=0; i<N-1; i++)
		{
			if (Lista_Empleados[i].Get_dni() != DNI_verificar)
			{
				Lista_temp[i] = Lista_Empleados[i];
				Eliminar++;
			}
			else
			{
				Eliminar = i;
				break;
			}
		}

		if (Eliminar <= N-2)
		{
			for (int i=Eliminar; i<N-1; i++)
			{
				Lista_temp[i] = Lista_Empleados[i+1];
			}
		}
		
		delete [] Lista_Empleados;
		Lista_Empleados = new Empleados[N-1];
		
		for (int i=0; i<N-1; i++)
		{
			Lista_Empleados[i] = Lista_temp[i];
		}
		
		delete [] Lista_temp;
		
		Guardar(N-1);
	}
	
void Empleados_Metodos::Mostrar_informacion_empleado(int N)
	{
		int DNI_verificar;
		std::cout << "Escribe el DNI del empleado" << std::endl;
		std::cin >> DNI_verificar;
		std::cout << "\n\n";
		
		for (int i=0; i<N; i++)
		{
			if (Lista_Empleados[i].Get_dni() == DNI_verificar)
			{
				std::cout << "Nombre :";
				std::cout << Lista_Empleados[i].Get_nombre() << std::endl;
				std::cout << "Correo :";
				std::cout << Lista_Empleados[i].Get_correo() << std::endl;
				std::cout << "Telefono :";
				std::cout << Lista_Empleados[i].Get_telefono() << std::endl;
				std::cout << "DNI :";
				std::cout << Lista_Empleados[i].Get_dni() << std::endl;
			}
		}
	}
	
void Empleados_Metodos::Modificar_informacion_empleado(int N)
	{
		int DNI_verificar;
		int Confirmar;
		int Cambio;
		std::cout << "Escribe el DNI del empleado" << std::endl;
		std::cin >> DNI_verificar;
		
		for (int i=0; i<N; i++)
		{
			if (Lista_Empleados[i].Get_dni() == DNI_verificar)
			{
				std::cout << "Quieres cambiar el nombre? | Presiona 1 para si y 0 para no" << std::endl;
				std::cin >> Confirmar;
				if (Confirmar == 1)
					Lista_Empleados[i].Set_nombre(comp, nullptr);
				
				std::cout << "Quieres cambiar el correo? | Presiona 1 para si y 0 para no" << std::endl;
				std::cin >> Confirmar;
				if (Confirmar == 1)
					Lista_Empleados[i].Set_correo(comp, nullptr);
				
				std::cout << "Quieres cambiar el telefono? | Presiona 1 para si y 0 para no" << std::endl;
				std::cin >> Confirmar;
				std::cout << "Que numero quieres?" << std::endl;
				std::cin >> Cambio;
				if (Confirmar == 1)
					Lista_Empleados[i].Set_telefono(Cambio);
			}
		}
		
		Guardar(4);
	}
	
void Empleados_Metodos::Llenar(int N)
	{
		LECTURA.open("Empleados.txt");
		
		int telefono_t = 0;
		int dni_t = 0;
		char *nombre_t = new char[15];
		char *correo_t = new char[50];
		
		for (int i=0; i<N; i++)
		{
			LECTURA >> nombre_t;
			LECTURA >> correo_t;
			LECTURA >> telefono_t;
			LECTURA >> dni_t;
			
			Lista_Empleados[i].Set_nombre(comp, nombre_t);	
			Lista_Empleados[i].Set_correo(comp, correo_t);
			Lista_Empleados[i].Set_telefono(telefono_t);
			Lista_Empleados[i].Set_dni(dni_t);
		}

		delete [] nombre_t;
		delete [] correo_t;

		LECTURA.close();
	}
	
void Empleados_Metodos::Guardar(int N)
	{
		LECTURA.open("Empleados.txt");
		ESCRITURA.open("Empleados_temp.txt", std::ios::app);

		for (int i=0; i<N; i++)
		{
			ESCRITURA << Lista_Empleados[i].Get_nombre() << std::endl;
			ESCRITURA << Lista_Empleados[i].Get_correo() << std::endl;
			ESCRITURA << Lista_Empleados[i].Get_telefono() << std::endl;
			ESCRITURA << Lista_Empleados[i].Get_dni() << "\n\n";
		}

		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("Empleados.txt");
		std::rename("Empleados_temp.txt", "Empleados.txt");
	}