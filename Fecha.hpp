#ifndef Fecha_h
#define Fecha_h

#include <fstream>

class Fecha{
	friend std::istream &operator>>(std::istream &input, Fecha& F);
	friend std::ostream &operator<<(std::ostream &output, Fecha& F);
	public:

	explicit Fecha();
	void Set_dia(int d);
	void Set_mes(int m);
	void Set_year(int y);
	int Get_dia() const;
	int Get_mes() const;
	int Get_year() const;
	bool operator>=(Fecha& F);
	bool operator>(Fecha& F);
	bool operator==(Fecha& F);
	Fecha& operator=(Fecha& F);
	
	private:
	int dia;
	int mes;
	int year;
};
#endif