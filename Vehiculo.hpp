#ifndef Vehiculo_h
#define Vehiculo_h

#include "Complemento.hpp"

class Vehiculo{
protected:
	
	char *marcaAuto;
	char *placa;
	char *color;
	char *estado;

public:
	
	Vehiculo();
	~Vehiculo();
	Vehiculo& operator=(Vehiculo& o);
	 
	void setMarca(char* llenarMarca);
	void setPlaca(char* llenarPlaca);
	void setColor(char* llenarColor);
	void setEstado(char* llenarEstado);

	char* getMarca();
	char* getPlaca();
	char* getColor();
	char* getEstado();

};
#endif
