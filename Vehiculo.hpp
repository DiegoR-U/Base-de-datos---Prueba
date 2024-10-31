#ifndef Vehiculo_HPP
#define Vehiculo_HPP

class Vehiculo{
public:
	//Atributos
	int id;
	char *modelo, *matricula, *estado;
	
	//constructor
	Vehiculo();
	
	//Funciones
	void agregarIDVehiculo();
	void agregarModelo();
	void agregarMatricula();
	void estadoVehiculo();
	void mostrarDatos();
};
#endif //ClaseVehiculo_HPP