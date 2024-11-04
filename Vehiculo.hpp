class Vehiculo{
public:

	int id;
	char *modelo;
	char *matricula;
	char *estado;
	
	Vehiculo();

	void agregarIDVehiculo();
	void agregarModelo();
	void agregarMatricula();
	void estadoVehiculo();
	void mostrarDatos();

};