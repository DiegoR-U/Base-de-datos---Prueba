#include "Vehiculo_Metodos.hpp"
#include <iostream>

//Constructor
Vehiculo_Metodos::Vehiculo_Metodos()
	{
	
		listaVehiculos = nullptr;
		nroVehiculos = 0;

	}

Vehiculo_Metodos::Vehiculo_Metodos(Vehiculo_Metodos &o)
	{
		listaVehiculos = new Vehiculo[nroVehiculos + 1];

		for (int i = 0; i < nroVehiculos; ++i)
		{
			*(listaVehiculos + i) = *(o.listaVehiculos + i);
		}
	}

Vehiculo_Metodos::~Vehiculo_Metodos()
	{

		comprobar.Borrar_Puntero(listaVehiculos);	

	}

void Vehiculo_Metodos::agregarVehiculo(Vehiculo newVehiculo)
	{

		std::cout << "Ingrese la placa: " << "\n\n";
		newVehiculo.setPlaca(comprobar, nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el marca: " << "\n\n";
		newVehiculo.setMarca(comprobar, nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el color: " << "\n\n";
		newVehiculo.setColor(comprobar, nullptr);
		std::cout << "\n\n";

		std::cout << "Ingrese el estado: " << "\n\n";
		newVehiculo.setEstado(comprobar, nullptr);
		std::cout << "\n\n";

		Vehiculo *respaldo_Vehiculos = new Vehiculo[nroVehiculos + 1];

		for(int i = 0; i < nroVehiculos; ++i)
		{
			*(respaldo_Vehiculos + i) = *(listaVehiculos +i);
		}

		respaldo_Vehiculos[nroVehiculos] = newVehiculo;

		delete [] listaVehiculos;

		listaVehiculos = respaldo_Vehiculos;


	}



