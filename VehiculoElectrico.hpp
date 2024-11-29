#ifndef VehiculoElectrico_h
#define VehiculoElectrico_h

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
        vElectrico(int capacidadBateria, float tiempoCarga, char* tipoC,
                    char* marca, char* placa, char* color, char* estado);
        ~vElectrico();
        
        vElectrico& operator=(vElectrico& other);
        
        void setcapacidadBateria(int capacidadBateria);
        void setTiempoCarga(float tiempoCarga);
        void setTipoCargador(char* tipoC);

        int getCapacidadBateria();
        float getTiempoCarga();
        char* getTipoCargador();

        void mostrarInformacion() const override;

};

#endif