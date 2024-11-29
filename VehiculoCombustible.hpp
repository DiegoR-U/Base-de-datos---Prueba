
#ifndef VehiculoCombustible_h
#define VehiculoCombustible_h

#include "Complemento.hpp"
#include "Vehiculo.hpp"

class vCombustible : public Vehiculo
{
    private:
        int capacidadTanque; 
        int numeroCilindros;       
        char* tipoCombustible;

    public:
        
        vCombustible();
        vCombustible(int capacidadTanque, int numerocilindros, char* tipo, 
                    char* marca, char* placa, char* color, char* estado);
        ~vCombustible();

        vCombustible& operator=(vCombustible& other);
        
        void setcapacidadTanque(int capacidadTanque);
        void setNumeroCilindros(int numeroCilindros);
        void setTipoCombustible(char* combustible);

        int getcapacidadTanque();
        int getNumeroCilindros();
        char* getTipoCombustible();

        void mostrarInformacion() const override;

};

#endif