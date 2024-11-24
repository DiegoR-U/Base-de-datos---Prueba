#include "Vehiculo_Metodos.hpp"
#include <iostream>

Vehiculo_Metodos::Vehiculo_Metodos()
	{
	
		listaVehiculos = nullptr;
		nroVehiculos = 0;

	}

Vehiculo_Metodos::Vehiculo_Metodos(Vehiculo_Metodos &o)
	{
		nroVehiculos = o.nroVehiculos;

		listaVehiculos = new Vehiculo[nroVehiculos + 1];

		for (int i = 0; i < nroVehiculos; ++i)
		{
			*(listaVehiculos + i) = *(o.listaVehiculos + i);
		}
	}

Vehiculo_Metodos::~Vehiculo_Metodos()
	{

		if (listaVehiculos != nullptr)
		{
			delete [] listaVehiculos;
		}	
	

	}

void Vehiculo_Metodos::agregarVehiculo()
	{

		Vehiculo *newVehiculo = new Vehiculo[nroVehiculos + 1];
		for (int i = 0; i < nroVehiculos; i++)
		{
			newVehiculo[i] = listaVehiculos[i];
		}

		std::cout << "Ingrese la placa: " << "\n\n";
		newVehiculo[nroVehiculos].setPlaca(nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el marca: " << "\n\n";
		newVehiculo[nroVehiculos].setMarca(nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el color: " << "\n\n";
		newVehiculo[nroVehiculos].setColor(nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el estado: " << "\n\n";
		newVehiculo[nroVehiculos].setEstado(nullptr);
		std::cout << "\n\n";

		delete [] listaVehiculos;

		listaVehiculos = newVehiculo;

		++nroVehiculos;

	}

void Vehiculo_Metodos::quitarVehiculo()
	{
		if (listaVehiculos != nullptr)
		{
			char* placa_ingresada{nullptr};
			bool confirmar = false;
			int indice = 0;

			Vehiculo *listaTemporal = new Vehiculo[nroVehiculos - 1];
			
			std::cout << "Ingrese la placa del vehiculo: " << "\n\n";
			Memoria_justa_cadena(placa_ingresada, 8, nullptr);

			for (int i = 0; i < nroVehiculos; i++)
			{
				if (listaVehiculos[i].getPlaca() == placa_ingresada && !confirmar)
				{
					confirmar = true;
					continue;
				}
				
				listaTemporal[indice] = listaVehiculos[i];
				indice ++; 
			}

			if (confirmar)
			{
				delete [] listaVehiculos;
				listaVehiculos = listaTemporal;
				nroVehiculos --;
				std::cout << "Vehiculo eliminado" << std::endl;
			}
			else
			{
				std::cout << "Vehiculo NO encontrado" << std::endl;
				delete [] listaTemporal;
			}

		}
		else
		{
			std::cout << "No hay vehiculos por eliminar" << std::endl;
		}

	}

void Vehiculo_Metodos::buscarVehiculo()
	{
		if (listaVehiculos != nullptr)
		{
			char* placa_ingresada{nullptr};
			bool confirmar = false;
			
			std::cout << "Ingrese la placa del vehiculo: " << "\n\n";
			Memoria_justa_cadena(placa_ingresada, 8, nullptr);

			for (int i = 0; i < nroVehiculos; i++)
			{
				if (listaVehiculos[i].getPlaca() == placa_ingresada && !confirmar)
				{
					confirmar = true;
					std::cout << "Vehiculo encontrado:" << std::endl;
					std::cout << "Marca: " << listaVehiculos[i].getMarca() << std::endl;
					std::cout << "Color: " << listaVehiculos[i].getColor() << std::endl;
					std::cout << "Placa: " << listaVehiculos[i].getPlaca() << std::endl;
					std::cout << "Estado: " << listaVehiculos[i].getEstado() << std::endl;
					break;
				}
			}

			if (!confirmar)
			{
				std::cout << "Vehiculo NO encontrado" << std::endl;
			}
				
		}
		else
		{
			std::cout << "No hay vehiculos por buscar" << std::endl;
		}
	}

void Vehiculo_Metodos::modificarEstado()
	{
		if (listaVehiculos != nullptr)
		{
			char* placa_ingresada{nullptr};
			bool confirmar = false;
				
			std::cout << "Ingrese la placa del vehiculo: " << "\n\n";
			Memoria_justa_cadena(placa_ingresada, 8, nullptr);

			for (int i = 0; i < nroVehiculos; i++)
			{
				if (listaVehiculos[i].getPlaca() == placa_ingresada && !confirmar)
				{
					confirmar = true;

					std::cout << "Ingrese el nuevo estado del vehículo" << std::endl;
					listaVehiculos[i].setEstado(nullptr);
					
					break;
				}
			}

			if (!confirmar)
			{
				std::cout << "Vehiculo NO encontrado" << std::endl;
			}
				
		}
		else
		{
			std::cout << "No hay vehiculos por buscar" << std::endl;
		}
	}

void Vehiculo_Metodos::llenarArchivo()
	{
		LEER.open("Vehiculos.txt");
		
		int size;
		
		char *marca_t = new char[15];
		char *estado_t =  new char[11];
		char *placa_t = new char[8];
		char *color_t = new char[20];
			
		LEER >> size;
		
		for (int i=0; i<size; i++)
		{
			LEER >> marca_t;
			LEER >> color_t;
			LEER >> placa_t;
			LEER >> estado_t;
					
			listaVehiculos[i].setMarca(marca_t);	
			listaVehiculos[i].setColor(color_t);
			listaVehiculos[i].setPlaca(placa_t);
			listaVehiculos[i].setEstado(estado_t);
		}

		delete [] marca_t;
		delete [] color_t;
		delete [] placa_t;
		delete [] estado_t;

		LEER.close();
	}

void Vehiculo_Metodos::guardarArchivo()
	{
		LEER.open("Vehiculos.txt");
		ESCRIBIR.open("Vehiculos_temp.txt", std::ios::app);

		ESCRIBIR << nroVehiculos << "\n\n";
		
		for (int i=0; i < nroVehiculos; i++)
		{
			ESCRIBIR << listaVehiculos[i].getMarca() << std::endl;
			ESCRIBIR << listaVehiculos[i].getColor() << std::endl;
			ESCRIBIR << listaVehiculos[i].getPlaca() << std::endl;
			ESCRIBIR << listaVehiculos[i].getEstado() << "\n\n";
		}

		ESCRIBIR.close();
		LEER.close();
		
		std::remove("Vehiculos.txt");
		std::rename("Vehiculos_temp.txt", "Vehiculos.txt");		
	}

void Vehiculo_Metodos::longitudLista()
	{
    	LEER.open("Vehiculos.txt", std::ios::in);

		if (!LEER) {
			std::cout << "Error al abrir el archivo de vehículos para lectura." << std::endl;
			return; 
		}

		if (Contenido_archivo(LEER))
		{
			LEER >> nroVehiculos;

			if (nroVehiculos > 0)
			{
				listaVehiculos = new Vehiculo[nroVehiculos];
				llenarArchivo(); 
			}
			else
			{
				std::cout << "El archivo no contiene vehículos o el tamaño es inválido." << std::endl;
				nroVehiculos = 0;  
				listaVehiculos = nullptr; 
			}
		}
		else
		{
			nroVehiculos = 0;
			listaVehiculos = nullptr;
			std::cout << "No hay vehículos en el archivo." << std::endl;
		}

		LEER.close();
	}
