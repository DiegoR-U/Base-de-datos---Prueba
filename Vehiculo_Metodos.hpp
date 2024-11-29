#ifndef Vehiculo_Metodos_h
#define Vehiculo_Metodos_h

#include "Vehiculo.hpp"
#include "VehiculoElectrico.hpp"
#include "VehiculoCombustible.hpp"
#include "Complemento.hpp"

class Vehiculo_Metodos{	
private:

    Vehiculo **listaVehiculos;
    int nroVehiculos;
    int capacidad;

public:
   
    Vehiculo_Metodos();
    ~Vehiculo_Metodos();
    
    void agregarVehiculo();
    void mostrarVehiculos();
    bool quitarVehiculo(char* placa);
    Vehiculo* buscarVehiculo(char* placa);
    bool modificarEstado(char* placa, char* nuevoEstado);
	
};

#endif