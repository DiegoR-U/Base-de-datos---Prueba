#ifndef VehiculoCombustible_h
#define VehiculoCombustible_h

#include "Vehiculo.hpp"
#include "Complemento.hpp"

class vElectrico : public Vehiculo
{
    private:
        
        int capacidadBateria; 
        float tiempoCarga;
        char* tipoCargador; 

    public:
        
        vElectrico();
        ~vElectrico();
        
        vElectrico& operator=(vElectrico& other);
        
        void setcapacidadBateria(int capacidadBateria);
        void setTiempoCarga(float tiempoCarga);
        void setTipoCargador(char* tipoCargador);

        int getCapacidadBateria();
        float getTiempoCarga();
        char* getTipoCargador();

};

#endif