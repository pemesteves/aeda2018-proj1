#ifndef DATA_H
#define DATA_H

#include <ctime>

class Data {
private:
	unsigned short dia;
	unsigned short mes;
	int ano;

public:
	Data();
	Data(unsigned short d, unsigned short m, unsigned short a);
	unsigned short getDia() const;
	unsigned short getMes() const;
	int getAno() const;
	bool operator>(const Data &data) const;
	bool operator==(const Data &data) const;

};

class Hora {
private:
	unsigned short hora;
	unsigned short minutos;
	unsigned short segundos;

public:
	Hora();
	Hora(unsigned short h, unsigned short m, unsigned short s);
	unsigned short getHora() const;
	unsigned short getMinutos() const;
	unsigned short getSegundos() const;
	bool operator >(const Hora &h) const;
	bool operator ==(const Hora &h) const;
};

#endif