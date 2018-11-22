#include "Data.h"

Data::Data() {
	time_t now;
	struct tm * timeinfo;
	time(&now);
	timeinfo = localtime(&now);
	ano = timeinfo->tm_year + 1900;
	mes = timeinfo->tm_mon + 1;
	dia = timeinfo->tm_mday;
}

Data::Data(unsigned short dia, unsigned short mes, int ano){
	this->dia=dia;
	this->mes=mes;
	this->ano=ano;
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

bool Data::operator< (const Data& data) const {
	if (ano == data.getAno()){
		if (mes == data.getMes())
			return (dia < data.getDia());
		return (mes < data.getMes());
	}

	return (ano < data.getAno());
}

bool Data::operator ==(const Data& data) const {
	return (ano == data.getAno() && mes == data.getMes() && dia == data.getDia());
}

std::ostream& operator<<(std::ostream &output, const Data &d1){
	output << d1.dia << "/" << d1.mes << "/" << d1.ano;
	return output;
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

Hora::Hora(unsigned short h, unsigned short m, unsigned short s){
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

bool Hora::operator< (const Hora& h) const {
	if (hora == h.getHora()){
		if (minutos == h.getMinutos())
			return (segundos > h.getSegundos());
		return (minutos > h.getMinutos());
	}
	return (hora > h.getHora());
}

bool Hora::operator ==(const Hora& h) const {
	return (hora == h.getHora() && minutos == h.getMinutos() && segundos == h.getSegundos());
}

std::ostream& operator<<(std::ostream &output, const Hora &h1){
	output << h1.hora << ":" << h1.minutos << ":" << h1.segundos;
	return output;
}
