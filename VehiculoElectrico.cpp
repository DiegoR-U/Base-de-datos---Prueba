#include <iostream>
#include "VehiculoElectrico.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

vElectrico::vElectrico() : Vehiculo() 
{
    capacidadBateria = 0;
    tiempoCarga = 0.0;
    tipoCargador = nullptr;
}

vElectrico::~vElectrico()
{
    if ( tipoCargador != nullptr )
    {
        delete [] tipoCargador;
    }
}

vElectrico& vElectrico::operator=(vElectrico& other)
{
    if (this != &other)
    {
        Memoria_justa_cadena(marcaAuto, 20, other.getMarca());
        Memoria_justa_cadena(placa, 7, other.getPlaca());
        Memoria_justa_cadena(color, 20, other.getColor());
        Memoria_justa_cadena(estado, 11, other.getEstado());
		Memoria_justa_cadena(tipoCargador, 30, other.getTipoCargador());

        this -> capacidadBateria = other.getCapacidadBateria();
        this -> tiempoCarga = other.getTiempoCarga();
    }

    return *this;
}

void vElectrico::setcapacidadBateria(int capacidadBateria)
{
    this -> capacidadBateria = capacidadBateria;
}

void vElectrico::setTiempoCarga(float tiempoCarga)
{
    this -> tiempoCarga = tiempoCarga;
}

void vElectrico::setTipoCargador(char* tipoC)
{
    Borrar_Asignar_ptr(tipoCargador);
	Memoria_justa_cadena(tipoCargador, 30, tipoC);
}

int vElectrico::getCapacidadBateria()
{
    return capacidadBateria;
}

float vElectrico::getTiempoCarga()
{
    return tiempoCarga;
}

char* vElectrico::getTipoCargador()
{
    return tipoCargador;
}