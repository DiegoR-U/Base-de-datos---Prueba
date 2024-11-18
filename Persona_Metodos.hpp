#ifndef Persona_Metodos_h
#define Persona_Metodos_h

#include <fstream>
#include "Persona.hpp"

class Persona_Metodos{
	public:
	explicit Persona_Metodos();
	~Persona_Metodos();
	void Listar_personas();
	void Anadir_personas();
	void Quitar_personas();
	void Mostrar_informacion_personas();
	void Modificar_informacion_personas();
	void Determinar_tamano();
	void Llenar();
	void Guardar();

	private:
	std::ifstream LECTURA;
	std::ofstream ESCRITURA;
	Complemento comp;
	int size;
	Persona* Lista_Personas;
};
#endif