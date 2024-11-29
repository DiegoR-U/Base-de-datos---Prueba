#ifndef Complement_h
#define Complement_h

#include <fstream>

void Copiar_Puntero(char *&x, char *&b, int c);
int Longitud_Puntero(char *&x);
void Memoria_justa_cadena(char *&x, int capacidad, char *llenar);
bool Comparar_Punteros(const char ptr1, const char ptr2, int longitud);
void Borrar_Puntero(char *&x);
void Borrar_Asignar_ptr(char *&x);
bool Contenido_archivo(std::ifstream &x);
void Convertir_mayusculas_minusculas(char &x, bool y);

#endif