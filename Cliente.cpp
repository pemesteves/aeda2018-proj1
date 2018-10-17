#include "Cliente.h"

Cliente::Cliente(string nome, string morada, double contribuinte) {
	Nome=nome;
	Morada = morada;
	NoContribuinte = contribuinte;
}


string Cliente::getNome() {
	return Nome;
}

string Cliente::getMorada() {
	return Morada;
}

double Cliente::getNoContribuinte() {
	return NoContribuinte;
}

vector<Venda*> Cliente::getHistorialCompras() {
	return HistorialCompras;
}

void Cliente::addCompra(Venda* compra) {
	HistorialCompras.push_back(compra);
}

