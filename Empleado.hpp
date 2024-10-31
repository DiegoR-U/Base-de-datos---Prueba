#include <iostream>
#include <fstream>

class Empleados{
	public:
	
	explicit Empleados();
	void Listar_empleados();
	void Anadir_empleados();
	void Quitar_empleados();
	void Mostrar_informacion_empleado();
	void Modificar_informacion_empleado();

	private:
	std::ifstream LECTURA;
	std::ofstream ESCRITURA;
	char *nombre;
	char *correo;
	char *temporal_char;
	char *temporal_char2;
	char Confirmacion;
	bool Comprobacion;
	int telefono;
	int ID;
	int ID_tel_Comprobacion;
	int incremento;
	int salida;
	int size;
};