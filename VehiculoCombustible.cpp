#include <iostream>
#include "VehiculoCombustible.hpp"

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

vCombustible::vCombustible() : Vehiculo() 
{
    capacidadTanque = 0;
    numeroCilindros = 0;
    tipoCombustible = nullptr;
}

vCombustible::vCombustible(int capacidadTanque, int numeroCilindros,char* tipo,
                       char* marca, char* placa, char* color, char* estado)
    :Vehiculo(), 
    capacidadTanque(capacidadTanque), numeroCilindros(numeroCilindros), tipoCombustible(nullptr)
{
    if (tipo != nullptr) 
    {
        tipoCombustible = new char[Longitud_Puntero(tipo) + 1];
        Copiar_Puntero(tipo, tipoCombustible, Longitud_Puntero(tipoCombustible));
    }

    setMarca(marca);
    setPlaca(placa);
    setColor(color);
    setEstado(estado);
}

vCombustible::~vCombustible()
{
    if (tipoCombustible != nullptr)
    {
        delete [] tipoCombustible;
    }
}

vCombustible& vCombustible:: operator=(vCombustible& other)
{
    if (this != &other) 
    {
        Memoria_justa_cadena(marcaAuto, 20, other.getMarca());
        Memoria_justa_cadena(placa, 7, other.getPlaca());
        Memoria_justa_cadena(color, 20, other.getColor());
        Memoria_justa_cadena(estado, 11, other.getEstado());
		Memoria_justa_cadena(tipoCombustible, 30, other.getTipoCombustible());
		
		this->numeroCilindros = other.getNumeroCilindros();
		
		this->capacidadTanque = other.getcapacidadTanque();
		
    }
		
	return *this;
}

void vCombustible::setcapacidadTanque(int capacidadTanque) 
{
    this -> capacidadTanque = capacidadTanque;
}

void vCombustible::setNumeroCilindros(int numeroCilindros)
{
    this -> numeroCilindros = numeroCilindros;
}

void vCombustible::setTipoCombustible(char* combustible)
{
    Borrar_Asignar_ptr(tipoCombustible);
	Memoria_justa_cadena(tipoCombustible, 20, combustible);
}

char* vCombustible::getTipoCombustible()
{
    return tipoCombustible;
}

int vCombustible::getcapacidadTanque()
{
    return capacidadTanque;
}

int vCombustible::getNumeroCilindros()
{
    return numeroCilindros;
}

void vCombustible::mostrarInformacion() const
{
    std::cout << "Vehículo de Combustible";
    Vehiculo::mostrarInformacion(); 
    std::cout << "Capacidad del tanque: " << capacidadTanque 
              << " litros, Tipo de combustible: " << tipoCombustible 
              << " Numero de cilindros: " << numeroCilindros << std::endl;
}