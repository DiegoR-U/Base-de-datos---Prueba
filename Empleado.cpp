#include <iostream>
#include "Empleado.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Empleados::Empleados()
	{
		nombre = nullptr;
		correo = nullptr;
		telefono = 0;
		DNI = -1;
	}
	
void Empleados::Listar_empleados()
	{
		LECTURA.open("Empleado.txt");
		
		nombre = new char[50];
		correo = new char[50];
		
		while (!LECTURA.eof())
		{
			LECTURA>>DNI;
			LECTURA>>nombre;
			LECTURA>>correo;
			LECTURA>>telefono;
			
			std::cout << "DNI: " << DNI << "   -   " << "Nombre: " << nombre << "\n\n";
		}
		
		delete [] nombre;
		delete [] correo;
		
		LECTURA.close();
	}
	
void Empleados::Anadir_empleados()
	{
		LECTURA.open("Empleado.txt");
		ESCRITURA.open("Empleado.txt", std::ios::app);
		
		bool Confirmar = 0;
		int DNI_validar = 0;
		char *temp1 = new char[50];
		char *temp2 = new char[50];
		
		if (ESCRITURA.is_open())
		{
			std::cout << "Cual es su DNI?" << "\n\n";
			std::cin >> DNI;
			std::cout << "\n\n";
			
			std::cout << "Que nombre tiene?" << "\n\n";
			comp.Set_Complemento_temp(15);
			comp.Memoria_justa_cadena(nombre, 15);
			comp.Set_Complemento_size(0);
			std::cout << "\n\n";
				
				
			std::cout << "Cual es su correo?" << "\n\n";
			comp.Set_Complemento_temp(50);
			comp.Memoria_justa_cadena(correo, 50);
			comp.Set_Complemento_size(0);
			std::cout << "\n\n";


			std::cout << "Cual es su telefono?" << "\n\n";
			std::cin >> telefono;
				
			ESCRITURA << DNI << "\n\n";
			ESCRITURA << nombre << "\n\n";
			ESCRITURA << correo << "\n\n";
			ESCRITURA << telefono << "\n\n";
		}
		
		delete [] temp1;
		delete [] temp2;
		
		ESCRITURA.close();
		LECTURA.close();
	}
	
void Empleados::Quitar_empleados()
	{
		LECTURA.open("Empleado.txt");
		ESCRITURA.open("Empleado_t.txt", std::ios::app);
		
		int DNI_validar = 0;
		bool Confirmar = 0;
		nombre = new char[50];
		correo = new char[50];
		
		std::cout << "Pon el DNI del usuario que quieres quitar" << "\n\n";
		std::cin >> DNI;
		
		while (!LECTURA.eof())
		{
			LECTURA>>DNI_validar;
			LECTURA>>nombre;
			LECTURA>>correo;
			LECTURA>>telefono;
			
			if (DNI == DNI_validar)
			{
				std::cout << "El usuario con DNI: " << DNI << " y nombre: " << nombre << " fue eliminado." << "\n\n";
				Confirmar = 1;
			}
			else
			{
				ESCRITURA << DNI_validar << "\n\n";
				ESCRITURA << nombre << "\n\n";
				ESCRITURA << correo << "\n\n";
				ESCRITURA << telefono << "\n\n";
			}
		}
		if (Confirmar == 0)
		{
			std::cout << "Ningun usuario fue removido" << "\n\n";
		}
		
		delete [] nombre;
		delete [] correo;
		
		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("Empleado.txt");
		std::rename("Empleado_t.txt", "Empleado.txt");		
	}
	
void Empleados::Mostrar_informacion_empleado()
	{
		LECTURA.open("Empleado.txt");
		
		nombre = new char[50];
		correo = new char[50];
		int DNI_validar = 0;
		bool Confirmar = 0;
		
		std::cout << "Pon el DNI del usuario" << std::endl;
		std::cin >> DNI;
		
		while (!LECTURA.eof() && Confirmar == 0)
		{
			LECTURA>>DNI_validar;
			LECTURA>>nombre;
			LECTURA>>correo;
			LECTURA>>telefono;
			
			if (DNI == DNI_validar)
			{
				Confirmar = 1;
			}
			else {}
		}
		
		if (Confirmar == 1)
		{
			std::cout << "DNI: " << DNI << "\n\n";
			std::cout << "Nombre: " << nombre << "\n\n";
			std::cout << "Correo: " << correo << "\n\n";
			std::cout << "Telefono: " << telefono << "\n\n";
		}
		else
		{
			std::cout << "No se pudo encontrar DNI" << std::endl;
		}
		
		delete [] nombre;
		delete [] correo;
		
		LECTURA.close();
	}
	
void Empleados::Modificar_informacion_empleado()
	{
		LECTURA.open("Empleado.txt");
		ESCRITURA.open("Empleado_t.txt", std::ios::app);
		
		int DNI_validar = 0;
		char Validar;
		bool Confirmar = 0;
		nombre = new char[50];
		correo = new char[50];
		
		std::cout << "Pon el DNI del usuario que quieres modificar" << "\n\n";
		std::cin >> DNI;
		std::cout << "\n\n";
		
		while (!LECTURA.eof())
		{
			LECTURA>>DNI_validar;
			LECTURA>>nombre;
			LECTURA>>correo;
			LECTURA>>telefono;
			
			if (DNI == DNI_validar)
			{			
				std::cout << "Quieres modificar el nombre -> s (si) o n (no)" << "\n\n";
				std::cin >> Validar;
					if (Validar == 's')
					{
						std::cout << "\n\n";
						std::cin >> nombre;
						std::cout << "\n\n";
					}
					
					std::cout << "Quieres modificar el correo -> s (si) o n (no)" << "\n\n";
					std::cin >> Validar;
					if (Validar == 's')
					{
						std::cout << "\n\n";
						std::cin >> correo;
						std::cout << "\n\n";
					}
					
					std::cout << "Quieres modificar el telefono -> s (si) o n (no)" << "\n\n";
					std::cin >> Validar;
					if (Validar == 's')
					{
						std::cout << "\n\n";
						std::cin >> telefono;
						std::cout << "\n\n";
					}
					
					ESCRITURA<<DNI_validar<<"\n\n";
					ESCRITURA<<nombre<<"\n\n";
					ESCRITURA<<correo<<"\n\n";
					ESCRITURA<<telefono<<"\n\n";
					
					Confirmar = 1;
			}
			else
			{
				ESCRITURA << DNI_validar << "\n\n";
				ESCRITURA << nombre << "\n\n";
				ESCRITURA << correo << "\n\n";
				ESCRITURA << telefono << "\n\n";
			}
		}
		if (Confirmar == 0)
		{
			std::cout << "Ningun usuario fue modificado" << "\n\n";
		}
		
		delete [] nombre;
		delete [] correo;
		
		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("Empleado.txt");
		std::rename("Empleado_t.txt", "Empleado.txt");
	}