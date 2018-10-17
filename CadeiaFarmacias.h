#ifndef CADEIAFARMACIAS_H
#define CADEIAFARMACIAS_H

#include "Farmacia.h"
#include "Cliente.h"
#include "Funcionario.h"

#include <vector>;

using namespace std;

class CadeiaFarmacias {

private:
	vector<Farmacia*> Farmacias;
	vector<Cliente*> Clientes;
	vector<Funcionario*> Funcionarios;

public:
	CadeiaFarmacias();
	void addFarmacia(Farmacia *farmacia);
	void addCliente(Cliente *cliente);
	void addFuncionario(Funcionario *funcionario);
};

#endif
