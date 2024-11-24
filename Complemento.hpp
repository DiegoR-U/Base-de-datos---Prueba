#ifndef Complement_h
#define Complement_h

#include <fstream>

void Copiar_Puntero(char *&x, char *&b, int c);
int Longitud_Puntero(char *&x);
void Memoria_justa_cadena(char *&x, int c, char *llenar);
bool Comparar_Punteros(char *&x, char *&b, int c);
void Borrar_Puntero(char *&x);
void Borrar_Asignar_ptr(char *&x);
bool Contenido_archivo(std::ifstream &x);
void Convertir_mayusculas_minusculas(char &x, bool y);

#endif