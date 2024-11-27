#ifndef VehiculoCombustible_h
#define VehiculoCombustible_h

#include "Vehiculo.hpp"
#include "Complemento.hpp"

class vCombustible : public Vehiculo
{
    private:
        int capacidadTanque; 
        int numeroCilindros; 
        char* tipoTransmision;      // (manual, automática)  
        char* tipoCombustible;

    public:
        
        vCombustible();
        ~vCombustible();
        
        vCombustible& operator=(vCombustible& other);
        
        void setcapacidadTanque(int capacidadTanque);
        void setNumeroCilindros(int numeroCilindros);
        void setTipoTransmision(char* transmision);
        void setTipoCombustible(char* combustible);

        int getcapacidadTanque();
        int getNumeroCilindros();
        char* getTipoTransmision();
        char* getTipoCombustible();

};

#endif