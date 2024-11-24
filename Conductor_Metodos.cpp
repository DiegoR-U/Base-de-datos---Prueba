#include <iostream>
#include "Conductor_Metodos.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif
	
Conductor_Metodos::Conductor_Metodos()
	{
		size = 0;
		Lista_Conductor = nullptr;
		ESCRITURA.open("Conductores_temp.csv", std::ios::app);
		LECTURA.open("Conductores.csv");
	}
	
Conductor_Metodos::~Conductor_Metodos()
	{
		if (Lista_Conductor != nullptr)
		{
			delete [] Lista_Conductor;
		}
		
		ESCRITURA.close();
		LECTURA.close();
		
		std::remove("Conductores.csv");
		std::rename("Conductores_temp.csv", "Conductores.csv");
	}

void Conductor_Metodos::Listar_conductores()
	{
		if (Lista_Conductor[0].Get_telefono() != -1)		//Comprobar si tenemos conductores
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
				if (int(Lista_Conductor[i].Get_nombre()[0]) >= int(MIN_R) && int(Lista_Conductor[i].Get_nombre()[0]) <= int(MAX_R))
				{
					std::cout << "Nombre: ";
					std::cout << Lista_Conductor[i].Get_nombre() << std::endl;
					std::cout << "Telefono: ";
					std::cout << Lista_Conductor[i].Get_telefono() << std::endl;
					std::cout << "DNI: ";
					std::cout << Lista_Conductor[i].Get_dni() << std::endl;
					std::cout << "Email: ";
					std::cout << Lista_Conductor[i].Get_email() << std::endl;
					std::cout << "Direccion: ";
					std::cout << Lista_Conductor[i].Get_direccion() << std::endl;
					std::cout << "Salario: ";
					std::cout << Lista_Conductor[i].Get_salario() << std::endl;
					std::cout << "Contrato: ";
					std::cout << Lista_Conductor[i].Get_Contrato() << std::endl;
					std::cout << "Nacimiento: ";
					std::cout << Lista_Conductor[i].Get_Nacimiento() << std::endl;
					std::cout << "Edad: ";
					std::cout << Lista_Conductor[i].Get_edad() << std::endl;
					std::cout << "Numero de licencia: ";
					std::cout << Lista_Conductor[i].Get_Contrato() << std::endl;
					std::cout << "Nivel: ";
					std::cout << Lista_Conductor[i].Get_Nacimiento() << std::endl;
					std::cout << "Vencimiento de licencia: ";
					std::cout << Lista_Conductor[i].Get_edad() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay ningun empleado para mostrar" << std::endl;
		}
			
	}

void Conductor_Metodos::Anadir_conductores()
	{
		int num_t;
		float float_t;
		
		Conductor* Lista_temp = new Conductor[size+1];
		
		for (int i=0; i<size; i++)
		{
			Lista_temp[i] = Lista_Conductor[i];
		}

		delete [] Lista_Conductor;
		
		std::cout << "Que nombre tiene el conductor?" << "\n\n";
		Lista_temp[size].Set_nombre();
		std::cout << "\n\n";
		
		std::cout << "Que telefono tiene el conductor?" << "\n\n";
		std::cin >> num_t;
		Lista_temp[size].Set_telefono(num_t);
		std::cout << "\n\n";
		
		std::cout << "Que DNI tiene el conductor?" << "\n\n";
		std::cin >> num_t;
		Lista_temp[size].Set_dni(num_t);
		std::cout << "\n\n";
		
		std::cout << "Que email tiene el conductor?" << "\n\n";
		Lista_temp[size].Set_email();
		std::cout << "\n\n";
		
		std::cout << "Que direccion tiene el conductor?" << "\n\n";
		Lista_temp[size].Set_direccion();
		std::cout << "\n\n";
		
		std::cout << "Cuando se contrato al conductor?" << "\n\n";
		Lista_temp[size].Set_Contrato();
		std::cout << "\n\n";
		
		std::cout << "Cuando nacio el conductor?" << "\n\n";
		Lista_temp[size].Set_Nacimiento();
		std::cout << "\n\n";
		
		std::cout << "Que salario tiene el conductor?" << "\n\n";
		std::cin >> float_t;
		Lista_temp[size].Set_salario(float_t);
		std::cout << "\n\n";
		
		std::cout << "Que edad tiene el conductor?" << "\n\n";
		std::cin >> num_t;
		Lista_temp[size].Set_edad(num_t);
		std::cout << "\n\n";
		
		std::cout << "Que licencia tiene el conductor?" << "\n\n";
		Lista_temp[size].Set_licencia();
		std::cout << "\n\n";
		
		std::cout << "Que nivel tiene el conductor?" << "\n\n";
		Lista_temp[size].Set_nivel();
		std::cout << "\n\n";
		
		std::cout << "Cuando vence la licencia del conductor?" << "\n\n";
		Lista_temp[size].Set_vencimiento();
		std::cout << "\n\n";
		
		Lista_Conductor = new Conductor[size+1];
		
		for (int i=0; i<size+1; i++)
		{
			Lista_Conductor[i] = Lista_temp[i];
		}
		
		delete [] Lista_temp;
		
		size++;
		
		std::cout << Lista_Conductor[0].Get_nombre() << std::endl;
		std::cout << Lista_Conductor[0].Get_telefono() << std::endl;
		std::cout << Lista_Conductor[0].Get_dni() << std::endl;
		std::cout << Lista_Conductor[0].Get_email() << std::endl;
		std::cout << Lista_Conductor[0].Get_direccion() << std::endl;
		std::cout << Lista_Conductor[0].Get_Contrato() << std::endl;
		std::cout << Lista_Conductor[0].Get_Nacimiento() << std::endl;
		std::cout << Lista_Conductor[0].Get_salario() << std::endl;
		std::cout << Lista_Conductor[0].Get_edad() << std::endl;
		std::cout << Lista_Conductor[0].Get_licencia() << std::endl;
		std::cout << Lista_Conductor[0].Get_nivel() << std::endl;
		std::cout << Lista_Conductor[0].Get_vencimiento() << std::endl;
		
		int cualquierwea;
		std::cin >> cualquierwea;
		
		//Guardar();
	}
	
void Conductor_Metodos::Quitar_conductores()
	{
		if (Lista_Conductor[0].Get_telefono() != -1)
		{
			int Incrementar = 0;
			int DNI_verificar = 0;
			bool Existe = 0;
			
			std::cout << "Inserte el DNI del conductor" << std::endl;
			std::cin >> DNI_verificar;
			
			
			if (size > 1)
			{
				Conductor* Lista_temp = new Conductor[size-1];
				
				for (int i=0; i<size; i++)
				{
					if (Lista_Conductor[i].Get_dni() == DNI_verificar && Existe == 0)
					{
						Existe = 1;
						continue;
					}

					Lista_temp[Incrementar] = Lista_Conductor[i];
					Incrementar++;
				}
				
				if (Existe == 1)
				{
					delete [] Lista_Conductor;
					
					Lista_Conductor = new Conductor[size-1];
					
					for (int i=0; i<size-1; i++)
					{
						Lista_Conductor[i] = Lista_temp[i];
					}
						
					delete [] Lista_temp;
					
					size--;
				}
			}
			else
			{
				if (Lista_Conductor[0].Get_dni() == DNI_verificar)
				{
					Existe = 1;
				}
				
				if (Existe == 1)
				{
					delete [] Lista_Conductor;
				
					Lista_Conductor = new Conductor[1];
					
					size--;
				}
				
			}
			
			if (Existe == 0)
			{
				std::cout << "No se encuentra el DNI insertado" << std::endl;
			}
			else {}
			
			//Guardar();
		}
		else
		{
			std::cout << "No hay ningun empleado para eliminar" << std::endl;
		}
	}
	
void Conductor_Metodos::Mostrar_informacion_conductores()
	{
		if (Lista_Conductor[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			std::cout << "Escribe el DNI del conductor" << std::endl;
			std::cin >> DNI_verificar;
			std::cout << "\n\n";
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Conductor[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Nombre :";
					std::cout << Lista_Conductor[i].Get_nombre() << std::endl;
					std::cout << "Telefono :";
					std::cout << Lista_Conductor[i].Get_telefono() << std::endl;
					std::cout << "DNI :";
					std::cout << Lista_Conductor[i].Get_dni() << std::endl;
					std::cout << "Email :";
					std::cout << Lista_Conductor[i].Get_email() << std::endl;
					std::cout << "Direccion :";
					std::cout << Lista_Conductor[i].Get_direccion() << std::endl;
					std::cout << "Salario :";
					std::cout << Lista_Conductor[i].Get_salario() << std::endl;
					std::cout << "Contrato :";
					std::cout << Lista_Conductor[i].Get_Contrato() << std::endl;
					std::cout << "Nacimiento :";
					std::cout << Lista_Conductor[i].Get_Nacimiento() << std::endl;
					std::cout << "Edad :";
					std::cout << Lista_Conductor[i].Get_edad() << "\n\n";
				}
			}
		}
		else
		{
			std::cout << "No hay conductores para mostrar informacion" << std::endl;
		}
	}
	
void Conductor_Metodos::Modificar_informacion_conductores()
	{
		if (Lista_Conductor[0].Get_telefono() != -1)
		{
			int DNI_verificar;
			int Confirmar;
			int Cambio;
			float Cambio_f;
			std::cout << "Escribe el DNI del conductor" << std::endl;
			std::cin >> DNI_verificar;
			
			for (int i=0; i<size; i++)
			{
				if (Lista_Conductor[i].Get_dni() == DNI_verificar)
				{
					std::cout << "Quieres cambiar el nombre? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Conductor[i].Set_nombre();
					
					std::cout << "Quieres cambiar el telefono? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio;
						Lista_Conductor[i].Set_telefono(Cambio);
					}
					
					std::cout << "Quieres cambiar el email? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Conductor[i].Set_email();
					
					std::cout << "Quieres cambiar la direccion? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Conductor[i].Set_direccion();
					
					std::cout << "Quieres cambiar la fecha de coontrato? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Conductor[i].Set_Contrato();
					
					std::cout << "Quieres cambiar el nacimiento? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Conductor[i].Set_Nacimiento();
					
					std::cout << "Quieres cambiar el salario? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio_f;
						Lista_Conductor[i].Set_salario(Cambio_f);
					}
					
					std::cout << "Quieres cambiar la edad? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
					{
						std::cout << "Que numero quieres?" << std::endl;
						std::cin >> Cambio;
						Lista_Conductor[i].Set_edad(Cambio);
					}
					
					std::cout << "Quieres cambiar la licencia? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Conductor[i].Set_licencia();
					
					std::cout << "Quieres cambiar el nivel? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Conductor[i].Set_nivel();
					
					std::cout << "Quieres cambiar el vencimiento? | Presiona 1 para si y 0 para no" << std::endl;
					std::cin >> Confirmar;
					if (Confirmar == 1)
						Lista_Conductor[i].Set_vencimiento();
				}
			}
			
			//Guardar();
		}
		else
		{
			std::cout << "No hay conductores para modificar" << std::endl;
		}
	}
	
void Conductor_Metodos::Determinar_tamano()
	{
		if (Contenido_archivo(LECTURA))
		{
			LECTURA >> size;
			Lista_Conductor = new Conductor[size];
			Llenar();
		}
		else
		{
			size = 0;
			Lista_Conductor = new Conductor[1];
		}
	}

void Conductor_Metodos::Llenar()
	{
		char* temp = new char[60];
		int dia_t, mes_t, year_t;
		int num;
		float salario_t;
		
		for (int i=0; i<23; i++){
			LECTURA >> temp;
			std::cout << temp << std::endl;
		}
		std::cin >> mes_t;
		
		for (int i=0; i<size; i++)
		{
			LECTURA.getline(temp, '\n');
			
			LECTURA.getline(temp, ';');
			Lista_Conductor[i].Set_nombre(temp);
			
			LECTURA >> num;
			Lista_Conductor[i].Set_telefono(num);
			
			LECTURA.getline(temp, ';');
			
			LECTURA >> num;
			Lista_Conductor[i].Set_dni(num);
			
			LECTURA.getline(temp, ';');
			
			LECTURA.getline(temp, ';');
			Lista_Conductor[i].Set_email(temp);
			
			LECTURA.getline(temp, ';');
			Lista_Conductor[i].Set_direccion(temp);

			
			LECTURA >> dia_t;
			LECTURA >> temp;
			LECTURA >> mes_t;
			LECTURA >> temp;
			LECTURA >> year_t;
			Lista_Conductor[i].Set_Contrato(dia_t, mes_t, year_t);
			
			LECTURA.getline(temp, ';');
			
			LECTURA >> dia_t;
			LECTURA >> temp;
			LECTURA >> mes_t;
			LECTURA >> temp;
			LECTURA >> year_t;
			Lista_Conductor[i].Set_Nacimiento(dia_t, mes_t, year_t);
			
			LECTURA.getline(temp, ';');
			
			LECTURA >> salario_t;
			Lista_Conductor[i].Set_salario(salario_t);
			
			LECTURA.getline(temp, ';');
			
			LECTURA >> num;
			Lista_Conductor[i].Set_edad(num);
			
			LECTURA.getline(temp, ';');
			
			LECTURA.getline(temp, ';');
			Lista_Conductor[i].Set_licencia(temp);
			
			LECTURA.getline(temp, ';');
			Lista_Conductor[i].Set_nivel(temp);
			
			LECTURA.getline(temp, ';');
			
			LECTURA >> dia_t;
			LECTURA >> temp;
			LECTURA >> mes_t;
			LECTURA >> temp;
			LECTURA >> year_t;
			Lista_Conductor[i].Set_vencimiento(dia_t, mes_t, year_t);
		}
		std::cout << Lista_Conductor[0].Get_nombre() << ";";
		std::cout << Lista_Conductor[0].Get_telefono() << " ;";
		std::cout << Lista_Conductor[0].Get_dni() << " ;";
		std::cout << Lista_Conductor[0].Get_email() << ";";
		std::cout << Lista_Conductor[0].Get_direccion() << "; ";
		std::cout << Lista_Conductor[0].Get_Contrato() << " ; ";
		std::cout << Lista_Conductor[0].Get_Nacimiento() << " ; ";
		std::cout << Lista_Conductor[0].Get_salario() << " ; ";
		std::cout << Lista_Conductor[0].Get_edad() << " ;";
		std::cout << Lista_Conductor[0].Get_licencia() << ";";
		std::cout << Lista_Conductor[0].Get_nivel() << ";";
		std::cout << Lista_Conductor[0].Get_vencimiento() << std::endl;
		int confirmar;
		std::cout << "Si llega222";
		std::cin >> confirmar;
		delete [] temp;
	}
	
void Conductor_Metodos::Guardar()
	{	
		ESCRITURA << size << std::endl;
		
		ESCRITURA << "Nombre" << " ; " << "Telefono" << " ; " << "DNI" << " ; " << "Email" << " ; " << "Direccion" << " ; " << "Contrato" << " ; " << "Nacimiento" << " ; " << "Salario" << " ; " << "Edad" << " ; " << "Licencia" << " ; " << "Nivel" << " ; " << "Vencimiento" << std::endl;
		
		for (int i=0; i<size; i++)
		{
			ESCRITURA << Lista_Conductor[i].Get_nombre() << ";";
			ESCRITURA << Lista_Conductor[i].Get_telefono() << " ;";
			ESCRITURA << Lista_Conductor[i].Get_dni() << " ;";
			ESCRITURA << Lista_Conductor[i].Get_email() << ";";
			ESCRITURA << Lista_Conductor[i].Get_direccion() << ";";
			ESCRITURA << Lista_Conductor[i].Get_Contrato() << " ; ";
			ESCRITURA << Lista_Conductor[i].Get_Nacimiento() << " ; ";
			ESCRITURA << Lista_Conductor[i].Get_salario() << " ; ";
			ESCRITURA << Lista_Conductor[i].Get_edad() << " ;";
			ESCRITURA << Lista_Conductor[i].Get_licencia() << ";";
			ESCRITURA << Lista_Conductor[i].Get_nivel() << "; ";
			ESCRITURA << Lista_Conductor[i].Get_vencimiento() << std::endl;
		}
	}