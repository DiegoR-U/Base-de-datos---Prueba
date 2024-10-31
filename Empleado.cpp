#include <iostream>
#include <fstream>
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
		temporal_char = nullptr;
		temporal_char2 = nullptr;
		telefono = 0;
		ID = -1;
		ID_tel_Comprobacion = -1;
		incremento = 0;
		Confirmacion = '\0';
		Comprobacion = false;
		salida = 1;
		size = 0;
	}
	
void Empleados::Listar_empleados()
	{
		temporal_char = new char[50];
		temporal_char2 = new char[50];
		
		LECTURA.open("empleado.txt");
		
		while (!LECTURA.eof())
		{
			LECTURA>>ID;
			LECTURA>>temporal_char;
			LECTURA>>temporal_char2;
			LECTURA>>telefono;
			
			std::cout << "ID: " << ID << "   -   " << "Nombre: " << temporal_char << "\n\n";
		}
		
		LECTURA.close();
		
		delete [] temporal_char;
		temporal_char = nullptr;
		delete [] temporal_char2;
		temporal_char2 = nullptr;
	}
	
void Empleados::Anadir_empleados()
	{
		temporal_char = new char[50];
		temporal_char2 = new char[50];
		
		LECTURA.open("empleado.txt");
		ESCRITURA.open("empleado.txt", std::ios::app);
		
		if (ESCRITURA.is_open())
		{
			std::cout << "Que ID tendra?" << "\n\n";
			std::cin >> ID;
			std::cout << "\n\n";
			
			while (!LECTURA.eof() && Comprobacion == false)
			{
				LECTURA>>ID_tel_Comprobacion;
				LECTURA>>temporal_char;
				LECTURA>>temporal_char2;
				LECTURA>>telefono;
				if (ID_tel_Comprobacion == ID)
					Comprobacion = true;
				else {}
			}
			
			if (Comprobacion == false)
			{
				std::cout << "Que nombre tiene?" << "\n\n";
				std::cin >> temporal_char;
				std::cout << "\n\n";
				
				for (int i=0; i<30; i++)
				{
					if (*(temporal_char+i)!='\0')
					{
					size++;
					incremento++;
					}
					else
						break;
				}
			
				nombre = new char[size+1];
				
				for (int i=0; i<size+1; i++)
				{
					*(nombre+i) = *(temporal_char+i); 
				}
				
				size = 0;
				std::cout << "Cual es su correo?" << "\n\n";
				std::cin >> temporal_char;
				std::cout << "\n\n";
				
				while (!LECTURA.eof())
				{
					LECTURA >> temporal_char2;
					if (temporal_char2 == temporal_char)
					{
						std::cout << "Correo ya ocupado, vuelva a ponerlo" << "\n\n";
						std::cin >> temporal_char;
					}
					else {}
				}
				
				for (int i=0; i<30; i++)
				{
					if (*(temporal_char+i)!='\0')
					{
					size++;
					incremento++;
					}
					else
						break;
				}
				
				correo = new char[size];
				
				for (int i=0; i<size+1; i++)
				{
					*(correo+i) = *(temporal_char+i); 
				}
				
				size = 0;
				std::cout << "Cual es su telefono?" << "\n\n";
				std::cin >> telefono;
				
				ESCRITURA << ID << "\n\n";
				ESCRITURA << nombre << "\n\n";
				ESCRITURA << correo << "\n\n";
				ESCRITURA << telefono << "\n\n";
				
				ESCRITURA.close();
				LECTURA.close();

			}
			
			else
			{
				std::cout << "Este ID ya está en uso" << "\n";
			}
		}
		
		else
		{
			std::cout << "Error no se pudo abrir el archivo";
		}
		
		delete [] temporal_char;
		temporal_char = nullptr;
		delete [] temporal_char2;
		temporal_char2 = nullptr;
	}
	
void Empleados::Quitar_empleados()
	{
		temporal_char = new char[50];
		temporal_char2 = new char[50];
		
		LECTURA.open("empleado.txt");
		ESCRITURA.open("temp.txt", std::ios::app);
		
		std::cout << "Pon el ID del usuario que quieres quitar" << "\n\n";
		std::cin >> ID;
		
		while (!LECTURA.eof())
		{
			int tempr = ID_tel_Comprobacion;
			LECTURA>>ID_tel_Comprobacion;
			LECTURA>>temporal_char;
			LECTURA>>temporal_char2;
			LECTURA>>telefono;
			
			if (ID == ID_tel_Comprobacion)
			{
				std::cout << "El usuario con ID: " << ID << " y nombre: " << temporal_char << " fue eliminado." << "\n\n";
				incremento++;
			}
			else
			{
				if (tempr != ID_tel_Comprobacion)
				{
					ESCRITURA << ID_tel_Comprobacion << "\n\n";
					ESCRITURA << temporal_char << "\n\n";
					ESCRITURA << temporal_char2 << "\n\n";
					ESCRITURA << telefono << "\n\n";
				}
				else {}
			}
		}
		if (incremento == 0)
		{
			std::cout << "Ningun usuario fue removido" << "\n\n";
		}
		
		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("empleado.txt");
		std::rename("temp.txt", "empleado.txt");
		
		delete [] temporal_char;
		temporal_char = nullptr;
		delete [] temporal_char2;
		temporal_char2 = nullptr;
		
	}
	
void Empleados::Mostrar_informacion_empleado()
	{
		temporal_char = new char[50];
		temporal_char2 = new char[50];
		
		LECTURA.open("empleado.txt");
		
		std::cout << "Pon el ID del usuario" << std::endl;
		std::cin >> ID;
		
		while (!LECTURA.eof() && Comprobacion == false)
		{
			LECTURA>>ID_tel_Comprobacion;
			LECTURA>>temporal_char;
			LECTURA>>temporal_char2;
			LECTURA>>telefono;
			
			if (ID == ID_tel_Comprobacion)
			{
				Comprobacion = true;
			}
			else {}
		}
		
		if (Comprobacion == true)
		{
			std::cout << "ID: " << ID << "\n\n";
			std::cout << "Nombre: " << temporal_char << "\n\n";
			std::cout << "Correo: " << temporal_char2 << "\n\n";
			std::cout << "Telefono: " << telefono << "\n\n";
		}
		else
		{
			std::cout << "No se pudo encontrar ID" << std::endl;
		}
		
		LECTURA.close();
		
		delete [] temporal_char;
		temporal_char = nullptr;
		delete [] temporal_char2;
		temporal_char2 = nullptr;
	}
	
void Empleados::Modificar_informacion_empleado()
	{
		temporal_char = new char[50];
		temporal_char2 = new char[50];
		
		LECTURA.open("empleado.txt");
		ESCRITURA.open("temp.txt", std::ios::app);
		
		std::cout << "Pon el ID del usuario que quieres modificar" << "\n\n";
		std::cin >> ID;
		std::cout << "\n\n";
		
		while (!LECTURA.eof())
		{
			int tempr = ID_tel_Comprobacion;
			LECTURA>>ID_tel_Comprobacion;
			LECTURA>>temporal_char;
			LECTURA>>temporal_char2;
			LECTURA>>telefono;
			
			if (ID == ID_tel_Comprobacion)
			{
				std::cout << "Quieres modificar el nombre -> s (si) o n (no)" << "\n\n";
				std::cin >> Confirmacion;
				if (Confirmacion == 's')
				{
					std::cout << "\n\n";
					std::cin >> temporal_char;
					std::cout << "\n\n";
				}
				
				std::cout << "Quieres modificar el correo -> s (si) o n (no)" << "\n\n";
				std::cin >> Confirmacion;
				if (Confirmacion == 's')
				{
					std::cout << "\n\n";
					std::cin >> temporal_char2;
					std::cout << "\n\n";
				}
				
				std::cout << "Quieres modificar el telefono -> s (si) o n (no)" << "\n\n";
				std::cin >> Confirmacion;
				if (Confirmacion == 's')
				{
					std::cout << "\n\n";
					std::cin >> telefono;
					std::cout << "\n\n";
				}
				
				ESCRITURA<<ID_tel_Comprobacion<<"\n\n";
				ESCRITURA<<temporal_char<<"\n\n";
				ESCRITURA<<temporal_char2<<"\n\n";
				ESCRITURA<<telefono<<"\n\n";
				
				incremento++;
			}
			else
			{
				if (tempr != ID_tel_Comprobacion)
				{
				ESCRITURA << ID_tel_Comprobacion << "\n\n";
				ESCRITURA << temporal_char << "\n\n";
				ESCRITURA << temporal_char2 << "\n\n";
				ESCRITURA << telefono << "\n\n";
				}
			}
		}
		if (incremento == 0)
		{
			std::cout << "Ningun usuario fue modificado" << "\n\n";
		}
		
		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("empleado.txt");
		std::rename("temp.txt", "empleado.txt");
		
		delete [] temporal_char;
		temporal_char = nullptr;
		delete [] temporal_char2;
		temporal_char2 = nullptr;
	}