#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente : Pessoa {

public:
	vector<Venda*> HistorialCompras;

	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	vector<Venda*> getHistorialCompras();

	void addlCompras(Venda* compra);

	Cliente(string nome, string morada, double contribuinte);
};

#endif
