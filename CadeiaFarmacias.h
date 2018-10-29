#ifndef CADEIAFARMACIAS_H
#define CADEIAFARMACIAS_H

#include "Farmacia.h"
#include "Pessoa.h"

#include <vector>

class CadeiaFarmacias {
private:
	std::vector<Farmacia *> farmacias;
	std::vector <Cliente*> clientes;
	std::vector <Funcionario*> funcionarios;

public:

	CadeiaFarmacias();
	unsigned int getNumFarmacias() const;
	unsigned int getNumClientes() const;
	unsigned int getNumFuncionarios() const;
	std::vector<Farmacia *> getFarmacias() const;
	std::vector <Cliente*> getClientes() const;
	std::vector <Funcionario*> getFuncionarios() const;
	void addFarmacia(Farmacia* farmacia);
	void addCliente(Cliente* cliente);
	void addFuncionario(Funcionario* funcionario);

};

#endif