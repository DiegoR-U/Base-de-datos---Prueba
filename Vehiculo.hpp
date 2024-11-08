class Vehiculo{
private:
	
	char *marcaAuto;
	char placa[8];
	char *color;

public:
	
	char *estado;
	char getMarca() {return *marcaAuto;}
	char getColor() {return *color;}
	char getPlaca() {return placa[7];}
	Vehiculo();

};
class ListaVehiculos{
public:
	Vehiculo *misVehiculos;
	int nro_Vehiculos;
	
	void agregarVehiculo();
	void quitarVehiculo();
	void modificarEstado();
	void mostrarRegistro();
}