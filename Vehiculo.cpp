#include "Vehiculo.hpp"
#include <iostream>

//Constructor
Vehiculo::Vehiculo(){
	marcaAuto = nullptr;
	color = nullptr;
	estado = nullptr;
	for(int i = 0; i < 8; i++)
	{
		placa[i] = ' ';
	}
}
void Vehiculo::agregarVehiculo(){

	ESCRIBIR.open("Autos.txt", std::ios::app);

	if (ESCRIBIR.is_open())
	{
		std::cout << "Ingrese la placa del auto que desea agregar: ";
		std::cin >> placa;
		std::cout << "\n\n";

		std::cout << "Ingrese la marca: ";
		realizar.Set_Complemento_temp(20);
		realizar.Memoria_justa_cadena(marcaAuto, 20);
		std::cout << "\n\n";

		std::cout << "Ingrese el color de auto: ";
		realizar.Set_Complemento_temp(10);
		realizar.Memoria_justa_cadena(color, 10);
		std::cout << "\n\n";
		
		std::cout << "Ingrese el estado (disponible/ocupado): ";
		realizar.Set_Complemento_temp(20);
		realizar.Memoria_justa_cadena(estado, 20);
		std::cout << "\n\n";

		ESCRIBIR << placa << "\n\n";
		ESCRIBIR << marcaAuto << "\n\n";
		ESCRIBIR << color << "\n\n";
		ESCRIBIR << estado << "\n\n";
	}
	else
	{
		std::cout << "No se pudo abrir el archivo"<<std::endl;
	}

	ESCRIBIR.close();

}
void Vehiculo::quitarVehiculo(){

	LEER.open("Autos.txt");
	ESCRIBIR.open("rAutos.txt", std::ios::app);

	char placa_buscada[8];
	bool encontrado{false};

	std::cout << "Introduzca la placa del auto que quiere retirar: ";
	std::cin >> placa_buscada; 
	std::cout<<std::endl;

	while(!LEER.eof())
	{

		LEER>>placa;
		LEER>>marcaAuto;
		LEER>>color;
		LEER>>estado;

		if(placa_buscada != placa)
		{
			ESCRIBIR << placa << "\n\n";
			ESCRIBIR << marcaAuto << "\n\n";
			ESCRIBIR << color << "\n\n";
			ESCRIBIR << estado << "\n\n";

		}
		else
		{
			std::cout << "El auto de placa " << placa << " de marca " << marcaAuto << " con color " << color 
					<< " fue removido exitosamente";
					encontrado = true;
		}
	}

	if(!encontrado)
	{
		std::cout << "No se encontro un vehiculo con la placa " << placa_buscada << std::endl;
	}	

	ESCRIBIR.close();
	LEER.close();
		
	
	std::remove("Autos.txt");
	std::rename("rAutos.txt", "Autos.txt");
	
	delete[] marcaAuto;
	delete[] color;
	delete[] estado;

}
void Vehiculo::modificarEstado(){
	
	LEER.open("Autos.txt");
	ESCRIBIR.open("rAutos.txt", std::ios::app);

	char placa_buscada[8];
	bool encontrado{false};

	std::cout << "Ingresa la placa del auto que quieres ocupar o desocupar: ";
	std::cin >> placa_buscada;
	std::cout << "\n\n";

	while(!LEER.eof())
	{

		LEER>>placa;
		LEER>>marcaAuto;
		LEER>>color;
		LEER>>estado;

		if(placa_buscada != placa)
		{
			ESCRIBIR << placa << "\n\n";
			ESCRIBIR << marcaAuto << "\n\n";
			ESCRIBIR << color << "\n\n";
			ESCRIBIR << estado << "\n\n";

			std::cout << "Usuario no encontrado"<<std::endl;

		}
		else
		{
			char opcion1[11] = "Disponible"; 
			char opcion2[8] = "Ocupado";
			int opcion{0};
			std::cout << "Ingrese el nuevo estado de disponibilidad: "<<std::endl;
			std::cout << "1) " << opcion1 ;
			std::cout << "2) " << opcion2 ;
			std::cin >> opcion;

			switch (opcion)
			{
				case 1: 
					realizar.Puntero_Cadena(estado,11,opcion1);
					break;
				case 2:
					realizar.Puntero_Cadena(estado,8,opcion2);
					break;
				default:
					std::cout << "No valido "<<std::endl;
					break;
			}

			ESCRIBIR << placa_buscada << "\n\n";
			ESCRIBIR << marcaAuto << "\n\n";
			ESCRIBIR << color << "\n\n";
			ESCRIBIR << estado << "\n\n";

			encontrado = true;

		}

	}

	ESCRIBIR.close();
	LEER.close();
		
	std::remove("Autos.txt");
	std::rename("rAutos.txt", "Autos.txt");
	
	delete[] marcaAuto;
	delete[] color;
	delete[] estado;
}
void Vehiculo::mostrarRegistro(){

	LEER.open("Autos.txt");

	char placa_buscada[8];
	bool encontrado{false};
	
	std::cout << "Ingresa la placa del auto que quieres ocupar o desocupar: ";
	std::cin >> placa_buscada;
	std::cout << "\n\n";

	while(!LEER.eof())
	{

		LEER>>placa_buscada;
		LEER>>marcaAuto;
		LEER>>color;
		LEER>>estado;

		if(placa_buscada == placa)
		{
			encontrado = true;
		}
	}
	
	if(encontrado)
	{
		
		std::cout << "Placa: " << placa << "\n\n";
		std::cout << "Marca: " << marcaAuto << "\n\n";
		std::cout << "Color: " << color << "\n\n";
		std::cout << "Estado: " << estado << "\n\n";
	
	}
	else
	{
		std::cout << "Usuario no encontrado"<<std::endl;
	}

	LEER.close();
	delete[] marcaAuto;
	delete[] color;
	delete[] estado;

}