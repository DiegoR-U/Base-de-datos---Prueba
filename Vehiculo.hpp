#include <fstream>
#include <iostream>
class Vehiculo{
public:
	
	explicit Vehiculo();
	
	void agregarVehiculo();
	void quitarVehiculo();
	void asignarVehiculo();
	void modificarDatos();
	void mostrarDatos();
	
private:

	int id;
	char *modelo;
	char *matricula;
	char *estado;
	
};