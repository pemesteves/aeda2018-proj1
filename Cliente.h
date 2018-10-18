#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente : Pessoa {

public:
	vector<Venda*> historialCompras;

	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	vector<Venda*> getHistorialCompras();

	void addCompras(Venda* compra);

	Cliente(string nome, string morada, double contribuinte);

	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	unsigned int numCompras();

	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();

	string virtual_getNome();

	string virtual_getMorada();

	double virtual_getNoContribuinte();
};

#endif
