#ifndef Complement_h
#define Complement_h

#include <fstream>

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
	
	private:
	char *temporal;
	int size;
};
#endif