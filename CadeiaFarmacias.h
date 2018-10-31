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
	Farmacia* removeFarmacia(const std::string &nomeF);
	void sortFarmacias();
	void addCliente(Cliente* cliente);
	Cliente* removeCliente(const std::string &nomeC);
	void sortClientes();
	void addFuncionario(Funcionario* funcionario);
	Funcionario* removeFuncionario(const std::string &nomeF);
	void sortFuncionarios();
};

#endif
