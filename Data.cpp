#include "Data.h"

Data::Data() {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	ano = ltm.tm_year + 1900;
	mes = ltm.tm_mon + 1;
	dia = ltm.tm_mday;
}

Data::Data(unsigned short d, unsigned short m, unsigned short a) {
	dia = d;
	mes = m;
	ano = a;
}

unsigned short Data::getDia() const {
	return dia;
}

unsigned short Data::getMes() const {
	return mes;
}

int Data::getAno() const {
	return ano;
}

bool Data::operator >(const Data& data) const {
	if (ano == data.getAno())
		if (mes == data.getMes())
			return (dia > data.getDia());
		else return (mes > data.getMes());
	else return (ano > data.getAno());
}

bool Data::operator ==(const Data& data) const {
	return (ano == data.getAno() && mes == data.getMes() && dia == data.getDia());
}

Hora::Hora() {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	hora = ltm.tm_hour;
	minutos = ltm.tm_min;
	segundos = ltm.tm_sec;
}

Hora::Hora(unsigned short h, unsigned short m, unsigned short s) {
	hora = h;
	minutos = m;
	segundos = s;
}

unsigned short Hora::getHora() const {
	return hora;
}

unsigned short Hora::getMinutos() const {
	return minutos;
}

unsigned short Hora::getSegundos() const {
	return segundos;
}

bool Hora::operator >(const Hora& h) const {
	if (hora == h.getHora())
		if (minutos == h.getMinutos())
			return (segundos > h.getSegundos());
		else return (minutos > h.getMinutos());
	else return (hora > h.getHora());
}

bool Hora::operator ==(const Hora& h) const {
	return (hora == h.getHora() && minutos == h.getMinutos() && segundos == h.getSegundos());
}