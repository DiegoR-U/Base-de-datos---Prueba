#include "Vehiculo_Metodos.hpp"
#include <iostream>

Vehiculo_Metodos::Vehiculo_Metodos()
	{
	
		listaVehiculos = new Vehiculo*[capacidad];
		nroVehiculos = 0;
		capacidad = 1;

	}

Vehiculo_Metodos::~Vehiculo_Metodos()
	{

		for (int i = 0; i < nroVehiculos; ++i) {
            delete listaVehiculos[i];
        }
        delete[] listaVehiculos;
	
	}

void Vehiculo_Metodos::agregarVehiculo()
	{
		if (nroVehiculos == capacidad) {
            capacidad *= 2;
            Vehiculo** newVehiculo = new Vehiculo*[capacidad];
            for (int i = 0; i < nroVehiculos; ++i) {
                newVehiculo[i] = listaVehiculos[i];
            }
            delete[] listaVehiculos;
            listaVehiculos = newVehiculo;
        }
		
		int tipoVehiculo;

		std::cout << "Ingrese el tipo de Vehiculo que desea agregar: \n";
		std::cout << "1. Electrico \n";
		std::cout << "2. Combustible \n";
		std::cin >> tipoVehiculo;

		char *placa, *marca, *color, *estado;

		std::cout << "Ingrese la placa: " << "\n\n";
		Memoria_justa_cadena(placa, 7, nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el marca: " << "\n\n";
		Memoria_justa_cadena(marca, 20, nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el color: " << "\n\n";
		Memoria_justa_cadena(color, 20, nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el estado: " << "\n\n";
		Memoria_justa_cadena(estado, 20, nullptr);
		std::cout << "\n\n";

		if (tipoVehiculo == 1)   								//Electrico
		{	
			int bateria;
			float tiempoCarga;
			char *tipoCargador;
			
			std::cout << "Ingrese la capacidad de bateria: " << "\n\n";
			std::cin >> bateria;
			std::cout << "\n\n";

			std::cout << "Ingrese el timepo de Carga: " << "\n\n";
			std::cin >> tiempoCarga;
			std::cout << "\n\n";

			std::cout << "Ingrese el tipo de cargador: " << "\n\n";
			Memoria_justa_cadena(tipoCargador, 30, nullptr);
			std::cout << "\n\n";

			Vehiculo *tipo = new vElectrico(bateria, tiempoCarga, tipoCargador,
													marca, placa, color, estado);
			listaVehiculos[nroVehiculos++] = tipo;
			
			std::cout << "Vehiculo Electrico agregado correctamente" << "\n\n";
		}
		else if (tipoVehiculo == 2)
		{	
			int nCilidros;
			int cTanque;
			char *tipoCombustible;
			
			std::cout << "Ingrese el numero de cilindros: " << "\n\n";
			std::cin >> nCilidros;
			std::cout << "\n\n";

			std::cout << "Ingrese la capacidad del Tanque: " << "\n\n";
			std::cin >> cTanque;
			std::cout << "\n\n";

			std::cout << "Ingrese el tipo de Combustible: " << "\n\n";
			Memoria_justa_cadena(tipoCombustible, 30, nullptr);
			std::cout << "\n\n";

			Vehiculo *tipo = new vCombustible(cTanque, nCilidros, tipoCombustible,
													marca, placa, color, estado);
			listaVehiculos[nroVehiculos++] = tipo;
			
			std::cout << "Vehiculo Combustible agregado correctamente" << "\n\n";
		}		
		else
		{
				std::cout << "Opcion no valida" << "\n\n";
		}

	}

bool Vehiculo_Metodos::quitarVehiculo(char* placa)
	{
		for (int i = 0; i < nroVehiculos; ++i) 
		{
			
			char* placaVehiculo = listaVehiculos[i]->getPlaca();
			char* placaBuscada = placa;

			bool existen = true;
			while (*placaVehiculo != '\0' && *placaBuscada != '\0') 
			{
				if (*placaVehiculo != *placaBuscada) 
				{
					existen = false;
					break;
				}
				placaVehiculo++;
				placaBuscada++;
			}

			if (existen && *placaVehiculo == *placaBuscada) 
			{
				delete listaVehiculos[i];

				for (int j = i; j < nroVehiculos - 1; ++j)
				{
					listaVehiculos[j] = listaVehiculos[j + 1];
				}

				nroVehiculos--;
				std::cout << "Vehículo con placa: " << placa << " eliminado." << std::endl;
				return true;
			}
		}

    std::cout << "Vehículo no encontrado." << std::endl;
    return false;
}

Vehiculo* Vehiculo_Metodos::buscarVehiculo(char* placa)
	{
		for (int i = 0; i < nroVehiculos; ++i) 
		{
        	char* placaVehiculo = listaVehiculos[i]->getPlaca();
        	char* placaBuscada = placa;

    		bool existe = true;

        	while (*placaVehiculo != '\0' && *placaBuscada != '\0') 
			{
            	if (*placaVehiculo != *placaBuscada) 
				{
                	existe = false;
                	break;
            	}
            	
				placaVehiculo++;
            	placaBuscada++;
        	}

        	if (existe && *placaVehiculo == *placaBuscada) {
            	return listaVehiculos[i];     //Imprimir los datos del vehículo buscado
        	}
    	}

		std::cout << "No encontrado." << std::endl;
		return nullptr;
	}

bool Vehiculo_Metodos::modificarEstado(char* placa, char* nuevoEstado)
	{
		for (int i = 0; i < nroVehiculos; ++i) 
		{
        	char* placaVehiculo = listaVehiculos[i]->getPlaca();
        	char* placaBuscada = placa;

    		bool existe = true;

        	while (*placaVehiculo != '\0' && *placaBuscada != '\0') 
			{
            	if (*placaVehiculo != *placaBuscada) 
				{
                	existe = false;
                	break;
            	}
            	
				placaVehiculo++;
            	placaBuscada++;
        	}

        	if (existe && *placaVehiculo == *placaBuscada) {
            	listaVehiculos[i]->setEstado(nuevoEstado);  
				std::cout << "Estado del vehículo con placa " << placa 
							<< " modificado a " << nuevoEstado << "." << std::endl;
                return true;
        	}
    	}

		std::cout << "No encontrado" << std::endl;
        return false;
	}

void Vehiculo_Metodos::mostrarVehiculos()
	{
		if (nroVehiculos == 0)
		{
			std::cout << "Aun no hay vehiculos registrados" << "\n\n";
			return;
		}
		else
		{
			for (int i = 0; i < nroVehiculos; ++i) 
			{
            	listaVehiculos[i]->mostrarInformacion();
			}
		}
	}