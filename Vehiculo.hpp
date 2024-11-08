#ifndef Vehiculo_h
#define Vehiculo_h

#include <fstream>
#include "Complemento.hpp"

class Vehiculo{
private:
	
	Complemento realizar;
	char *marcaAuto;
	char placa[8];
	char *color;
	std::ifstream LEER;
	std::ofstream ESCRIBIR;

public:
	
	char *estado;
	char getMarca() {return *marcaAuto;}
	char getColor() {return *color;}
	char getPlaca() {return placa[7];}
	
	Vehiculo();

	void agregarVehiculo();
	void quitarVehiculo();
	void modificarEstado();
	void mostrarRegistro();
	
};
#endif
