#ifndef Vehiculo_Metodos_h
#define Vehiculo_Metodos_h

#include <fstream>
#include "Vehiculo.hpp"
#include "Complemento.hpp"

class Vehiculo_Metodos{	
private:
    
    std::ifstream LEER;
    std::ofstream ESCRIBIR;

    Vehiculo *listaVehiculos;
    int nroVehiculos;

public:
   
    Complemento comprobar;

    Vehiculo_Metodos();
    Vehiculo_Metodos(Vehiculo_Metodos &o); //constructor de copia
    ~Vehiculo_Metodos();
    
    void agregarVehiculo(Vehiculo newVehiculo);
    void quitarVehiculo();
    void modificarEstado();
    void mostrarRegistro();
	
};

#endif