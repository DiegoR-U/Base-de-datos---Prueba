#ifndef Cliente_Metodos_h
#define Cliente_Metodos_h

#include <fstream>
#include "Cliente.hpp"

class Cliente_Metodos{
	public:
	explicit Cliente_Metodos();
	~Cliente_Metodos();
	void Listar_clientes();
	void Anadir_clientes();
	void Quitar_clientes();
	void Mostrar_informacion_clientes();
	void Modificar_informacion_clientes();
	void Determinar_tamano();
	void Llenar();
	void Guardar();

	private:
	std::ifstream LECTURA;
	std::ofstream ESCRITURA;
	Complemento comp;
	int size;
	Cliente* Lista_Clientes;
};
#endif