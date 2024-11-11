#ifndef Complement_h
#define Complement_h

#include <fstream>
#include "Vehiculo.hpp"

class Complemento{
	public:

	explicit Complemento();
	void Set_Complemento_temp(int c);
	void Set_Complemento_size(int s);
	int Get_Complemento_size();
	void Memoria_justa_cadena(char *&x, int c, char *llenar);
	void Copiar_Puntero(char *&x, char *&b, int c);
	bool Comparar_Punteros(char *&x, char *&b, int c);
	bool Contenido_archivo(std::ifstream &x);
	void Puntero_Cadena(char *&x, int c, char cad[]);
	void Borrar_Puntero(char *&x);
	void Borrar_Puntero(Vehiculo *&x);
	void Borrar_Asignar_ptr(char *&x);
	int Longitud_Puntero(char *&x);


	private:
	char *temporal;
	int size;
};
#endif
