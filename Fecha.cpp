#include "Fecha.hpp"
#include <iostream>

Fecha::Fecha()
	{
		dia = 0;
		mes = 0;
		year = 0;
	}
	
void Fecha::Set_dia(int d)
	{
		dia = d;
	}
	
void Fecha::Set_mes(int m)
	{
		mes = m;
	}
	
void Fecha::Set_year(int y)
	{
		year = y;
	}
	
int Fecha::Get_dia() const
	{
		return dia;
	}
	
int Fecha::Get_mes() const
	{
		return mes;
	}
	
int Fecha::Get_year() const
	{
		return year;
	}

bool Fecha::operator>=(Fecha& F)
	{
		if ((this->dia >= F.Get_dia()) && (this->mes >= F.Get_mes()) && (this->year >= F.Get_year()))
			return 1;
		else if ((this->dia < F.Get_dia()) && (this->mes > F.Get_mes()) && (this->year >= F.Get_year()))
			return 1;
		else if ((this->dia < F.Get_dia()) && (this->mes >= F.Get_mes()) && (this->year > F.Get_year()))
			return 1;
		else if ((this->dia >= F.Get_dia()) && (this->mes < F.Get_mes()) && (this->year > F.Get_year()))
			return 1;
		else if ((this->dia > F.Get_dia()) && (this->mes < F.Get_mes()) && (this->year >= F.Get_year()))
			return 1;
		else if ((this->dia < F.Get_dia()) && (this->mes < F.Get_mes()) && (this->year > F.Get_year()))
			return 1;
		else
			return 0;
	}
	
bool Fecha::operator>(Fecha& F)
	{
		if ((this->dia > F.Get_dia()) && (this->mes > F.Get_mes()) && (this->year > F.Get_year()))
			return 1;
		else if ((this->dia < F.Get_dia()) && (this->mes > F.Get_mes()) && (this->year >= F.Get_year()))
			return 1;
		else if ((this->dia < F.Get_dia()) && (this->mes >= F.Get_mes()) && (this->year > F.Get_year()))
			return 1;
		else if ((this->dia >= F.Get_dia()) && (this->mes < F.Get_mes()) && (this->year > F.Get_year()))
			return 1;
		else if ((this->dia > F.Get_dia()) && (this->mes < F.Get_mes()) && (this->year >= F.Get_year()))
			return 1;
		else if ((this->dia < F.Get_dia()) && (this->mes < F.Get_mes()) && (this->year > F.Get_year()))
			return 1;
		else
			return 0;
	}
	
bool Fecha::operator==(Fecha& F)
	{
		if ((this->dia == F.Get_dia()) && (this->mes == F.Get_mes()) && (this->year == F.Get_year()))
			return 1;
		else
			return 0;
	}
	
Fecha& Fecha::operator=(Fecha& F)
	{
		this->dia = F.Get_dia();
		this->mes = F.Get_mes();
		this->year = F.Get_year();
		
		return *this;
	}

std::istream &operator>>(std::istream& input, Fecha& F)
	{
		std::cout << "Ingrese el dia" << "\n\n";
		input >> F.dia;
		std::cout << "\n\n";
		input.ignore();
		std::cout << "Ingrese el mes" << "\n\n";
		input >> F.mes;
		std::cout << "\n\n";
		input.ignore();
		std::cout << "Ingrese el year" << "\n\n";
		input >> F.year;
		input.ignore();
		
		return input;
	}

std::ostream &operator<<(std::ostream& output, Fecha& F)
	{
		output << F.dia << " / " << F.mes << " / " << F.year;

		return output;
	}
