#ifndef Vehiculo_h
#define Vehiculo_h

#include "Complemento.hpp"

class Vehiculo{
private:
	
	char *marcaAuto;
	char *placa;
	char *color;
	char *estado;

public:
	
	Complemento comprobar;
	
	Vehiculo();
	Vehiculo(Vehiculo &o);
	~Vehiculo();
	 
	void setMarca(Complemento c, char* llenarMarca);
	void setPlaca(Complemento c, char* llenarPlaca);
	void setColor(Complemento c, char* llenarColor);
	void setEstado(Complemento c, char* llenarEstado);

	char* getMarca();
	char* getPlaca();
	char* getColor();
	char* getEstado();
	
};
#endif
