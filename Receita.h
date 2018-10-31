#ifndef RECEITA_H
#define RECEITA_H

#include "Produto.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <map>

class Receita {
private:
	double numero;
	std::string medico; //TODO criar classe medico para a receita
	std::map<Produto*, double>  produtos;
	Cliente* cliente;

public:
	Receita(double numero, std::string medico, Cliente* cliente);
	double getNumero() const;
	Cliente* getCliente() const;
	std::string getMedico() const;
	std::vector<Produto*> getProdutos() const;
	double getPrecoMax(std::string nomeProd) const;
	void addProduto(Produto* produto, double quant);
};

#endif
