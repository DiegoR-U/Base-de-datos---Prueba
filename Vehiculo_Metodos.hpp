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
    Vehiculo_Metodos(Vehiculo_Metodos &o); 
    ~Vehiculo_Metodos();
    
    void agregarVehiculo();
    void quitarVehiculo();
    void buscarVehiculo();
    void modificarEstado();
    void llenarArchivo();
    void guardarArchivo();
    void longitudLista();
	
};

#endif