#include "Data.h"
#include <ctime>

using namespace std;

Data::Data() {
	time_t now;
	struct tm * timeinfo;
	time(&now);
	timeinfo = localtime(&now);

	dia = timeinfo->tm_mday;
	mes = timeinfo->tm_mon+1;
	ano = timeinfo->tm_year+1900;
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
	time_t now;
	struct tm * timeinfo;
	time(&now);
	timeinfo = localtime(&now);

	hora = timeinfo->tm_hour;
	minutos = timeinfo->tm_min;
	segundos = timeinfo->tm_sec;
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
