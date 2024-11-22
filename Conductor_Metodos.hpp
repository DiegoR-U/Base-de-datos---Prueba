#ifndef Conductor_Metodos_h
#define Conductor_Metodos_h

#include <fstream>
#include "Conductor.hpp"

class Conductor_Metodos{
	public:
	explicit Conductor_Metodos();
	~Conductor_Metodos();
	void Listar_conductores();
	void Anadir_conductores();
	void Quitar_conductores();
	void Mostrar_informacion_conductores();
	void Modificar_informacion_conductores();
	void Determinar_tamano();
	void Llenar();
	void Guardar();

	private:
	std::ifstream LECTURA;
	std::ofstream ESCRITURA;
	Complemento comp;
	int size;
	Conductor* Lista_Conductor;
};
#endif