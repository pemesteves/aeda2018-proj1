#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
#include "Venda.h"

#include <string>
#include <vector>

using namespace std;

class Cliente : Pessoa {

public:
	Cliente(string nome, string morada, double contribuinte);

	vector<Venda*> HistorialCompras;

	string getNome();

	string getMorada();

	double getNoContribuinte();

	vector<Venda*> getHistorialCompras();

	void addCompra(Venda* compra);

};

#endif
