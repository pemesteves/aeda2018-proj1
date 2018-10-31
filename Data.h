#ifndef DATA_H
#define DATA_H

class Data {
private:
	unsigned short dia;
	unsigned short mes;
	int ano;

public:
	Data();
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
	unsigned short getHora() const;
	unsigned short getMinutos() const;
	unsigned short getSegundos() const;
	bool operator >(const Hora &h) const;
	bool operator ==(const Hora &h) const;
};

#endif
